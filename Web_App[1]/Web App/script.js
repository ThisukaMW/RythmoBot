const socket = new WebSocket("ws://192.168.8.190:81"); // ESP32 WebSocket IP
const startButton = document.getElementById("start-button");
const songSelector = document.getElementById("song-selector");
const audioPlayer = document.getElementById("audio-player");
const audioSource = document.getElementById("audio-source");
const statusDiv = document.getElementById("status");
// ==================== LED CONTROL VARIABLES ====================
        let currentLedPattern = "breathing";
        let autoLedDanceMode = true;
        let ledDancePatterns = ["dance", "rainbow", "pulse", "chase", "wave"]; // Patterns to cycle during dance
        let currentPatternIndex = 0;
        let ledDanceInterval = null;
// ==================== DRAG AND DROP ELEMENTS ====================
const dropZone = document.getElementById("drop-zone");
const fileInput = document.getElementById("file-input");
const uploadedFilesDiv = document.getElementById("uploaded-files");
const filesListDiv = document.getElementById("files-list");

let step = 1;
let intervalId = null;
let selectedSongName = "";
let currentSongPath = "";
let isPlaying = false;
let isPaused = false; // Track if we're in a paused state
let uploadedFiles = [];
let currentPlayingIndex = null; // Track which uploaded song is playing
let isUploadedSongPlaying = false; // Track if currently playing song is uploaded or normal

// WebSocket events
socket.onopen = () => {
  console.log("WebSocket connected to ESP32");
};

socket.onmessage = (event) => {
  console.log("Received from ESP32:", event.data);
};

socket.onerror = (error) => {
  console.log("WebSocket Error:", error);
};


        // ==================== LED CONTROL FUNCTIONS ====================

        // Send LED pattern command to robot
        function setLedPattern(pattern) {
            if (socket.readyState === WebSocket.OPEN) {
                socket.send(`led:${pattern}`);
                console.log(`LED pattern changed to: ${pattern}`);
                currentLedPattern = pattern;
                
                // Update UI to show active pattern
                updateLedButtonStates(pattern);
                statusDiv.innerHTML = `💡 LED pattern: ${pattern.toUpperCase()}`;
            } else {
                alert("WebSocket not connected!");
            }
        }


// ==================== DRAG AND DROP FUNCTIONALITY ====================

// Click to browse files
dropZone.addEventListener("click", () => {
  fileInput.click();
});

// Drag over event
dropZone.addEventListener("dragover", (e) => {
  e.preventDefault();
  dropZone.classList.add("dragover");
});

// Drag leave event
dropZone.addEventListener("dragleave", (e) => {
  if (!dropZone.contains(e.relatedTarget)) {
    dropZone.classList.remove("dragover");
  }
});

// Drop event
dropZone.addEventListener("drop", (e) => {
  e.preventDefault();
  dropZone.classList.remove("dragover");
  handleFiles(e.dataTransfer.files);
});

// File input change event
fileInput.addEventListener("change", (e) => {
  handleFiles(e.target.files);
  e.target.value = ""; // reset input
});

// Handle uploaded files
function handleFiles(files) {
  const validFiles = [];
  const invalidFiles = [];

  Array.from(files).forEach((file) => {
    if (file.type === "audio/mp3" || file.name.toLowerCase().endsWith(".mp3")) {
      validFiles.push(file);
    } else {
      invalidFiles.push(file.name);
    }
  });

  if (invalidFiles.length > 0) {
    alert(
      `These files are not MP3 format and were skipped:\n${invalidFiles.join(
        "\n"
      )}\n\nPlease upload only MP3 files.`
    );
  }

  if (validFiles.length > 0) {
    validFiles.forEach((file) => addUploadedFile(file));
    statusDiv.innerHTML = `Added ${validFiles.length} song${
      validFiles.length > 1 ? "s" : ""
    }.`;
  }
}

// Add uploaded file to the list
function addUploadedFile(file) {
  // Check if file already exists (by name and size)
  const existingFile = uploadedFiles.find(
    (f) => f.name === file.name && f.size === file.size
  );
  if (existingFile) {
    console.log(`${file.name} is already uploaded.`);
    return;
  }

  const fileURL = URL.createObjectURL(file);
  const fileObject = {
    name: file.name,
    url: fileURL,
    file: file,
    size: file.size,
    id: Date.now() + Math.random(),
  };

  uploadedFiles.push(fileObject);
  updateUploadedFilesList();
  console.log(`Added file: ${file.name}`);
}

// Update uploaded files list display with Play, Pause, Remove buttons
function updateUploadedFilesList() {
  if (uploadedFiles.length === 0) {
    uploadedFilesDiv.style.display = "none";
    return;
  }

  uploadedFilesDiv.style.display = "block";
  filesListDiv.innerHTML = "";

  uploadedFiles.forEach((fileObj, index) => {
    const fileItem = document.createElement("div");
    fileItem.className = "file-item";

    const fileSize = formatFileSize(fileObj.size);

    fileItem.innerHTML = `
      <span class="file-name" title="${fileObj.name}">${fileObj.name} (${fileSize})</span>
      <div class="file-actions">
        <button class="file-button play-btn" title="Play this song">Play</button>
        <button class="file-button pause-btn" title="Pause this song">Pause</button>
        <button class="file-button remove" title="Remove this song">Remove</button>
      </div>
    `;
    filesListDiv.appendChild(fileItem);

    const playBtn = fileItem.querySelector(".play-btn");
    const pauseBtn = fileItem.querySelector(".pause-btn");
    const removeBtn = fileItem.querySelector(".remove");

    playBtn.addEventListener("click", () => {
      playUploadedFile(index);
    });
    pauseBtn.addEventListener("click", () => {
      if (!audioPlayer.paused) {
        audioPlayer.pause();
      }
    });
    removeBtn.addEventListener("click", () => {
      removeUploadedFile(index);
    });
  });
}

// Format file size for display
function formatFileSize(bytes) {
  if (bytes === 0) return "0 Bytes";
  const k = 1024;
  const sizes = ["Bytes", "KB", "MB", "GB"];
  const i = Math.floor(Math.log(bytes) / Math.log(k));
  return parseFloat((bytes / Math.pow(k, i)).toFixed(2)) + " " + sizes[i];
}

// Play uploaded file with resume support
function playUploadedFile(index) {
  if (index < 0 || index >= uploadedFiles.length) return;
  const fileObj = uploadedFiles[index];

  if (currentPlayingIndex === index) {
    // Same song clicked: resume if paused
    if (audioPlayer.paused) {
      audioPlayer.play();
    }
  } else {
    // Different song clicked: load and play from start
    currentPlayingIndex = index;
    isUploadedSongPlaying = true; // Mark as uploaded song
    playSelectedSong(fileObj.url, fileObj.name);
  }
}

// Remove uploaded file
function removeUploadedFile(index) {
  if (index < 0 || index >= uploadedFiles.length) return;
  const fileObj = uploadedFiles[index];

  if (currentPlayingIndex === index) {
    stopSong();
    currentPlayingIndex = null;
    isUploadedSongPlaying = false;
  }

  URL.revokeObjectURL(fileObj.url);
  uploadedFiles.splice(index, 1);
  updateUploadedFilesList();
  statusDiv.innerHTML = `Removed: ${fileObj.name}`;
  console.log(`Removed file: ${fileObj.name}`);
}

// Send step signal to ESP32 - Updated to handle both normal and uploaded songs
function sendSteps() {
  let stepSignal;

  if (isUploadedSongPlaying) {
    // For uploaded songs: send random numbers between 1-18
    stepSignal = Math.floor(Math.random() * 18) + 1;
    console.log(`Sending random step signal for uploaded song: ${stepSignal}`);
  } else {
    // For normal songs: send sequential numbers
    stepSignal = step;
    step++;
    console.log(
      `Sending sequential step signal for normal song: ${stepSignal}`
    );
  }

  if (socket.readyState === WebSocket.OPEN) {
    socket.send(stepSignal.toString());
  }
}

// Load song but don't play
function preloadSong(path, name) {
  if (!path || !name) return;

  clearInterval(intervalId);
  intervalId = null;
  step = 1;
  isPlaying = false;
  isPaused = false;
  isUploadedSongPlaying = false; // Reset uploaded song flag

  audioSource.src = path;
  audioPlayer.load();

  selectedSongName = name;
  currentSongPath = path;
  currentPlayingIndex = null;

  statusDiv.innerHTML = `Loaded: ${name}`;
  document.querySelector(".container").classList.remove("playing");

  if (socket.readyState === WebSocket.OPEN) {
    socket.send("stop");
  }
}

// Play song and start dance steps
function playSelectedSong(path, name) {
  if (!path || !name) return;

  clearInterval(intervalId);
  intervalId = null;
  step = 1;
  isPaused = false;

  audioSource.src = path;
  audioPlayer.load();
  audioPlayer.play();

  selectedSongName = name;
  currentSongPath = path;
  isPlaying = true;

  statusDiv.innerHTML = "Song Playing...";
  document.querySelector(".container").classList.add("playing");

  if (socket.readyState === WebSocket.OPEN) {
    socket.send(`song:${selectedSongName}`);
    console.log(`Started new song: ${selectedSongName}`);
  }

  intervalId = setInterval(sendSteps, 5000);
}

// Stop and reset song playback
function stopSong() {
  audioPlayer.pause();
  audioPlayer.currentTime = 0;

  clearInterval(intervalId);
  intervalId = null;
  step = 1;
  isPlaying = false;
  isPaused = false;
  isUploadedSongPlaying = false; // Reset uploaded song flag

  statusDiv.innerHTML = `Stopped: ${selectedSongName}`;
  document.querySelector(".container").classList.remove("playing");

  if (socket.readyState === WebSocket.OPEN) {
    socket.send("stop");
    console.log(`Song stopped: ${selectedSongName}`);
  }
}

// Event Listeners

// On song selector change (preload only)
songSelector.addEventListener("change", () => {
  const path = songSelector.value;
  const name = songSelector.options[songSelector.selectedIndex].text;
  isUploadedSongPlaying = false; // Mark as normal song
  currentPlayingIndex = null; // Reset uploaded song index
  preloadSong(path, name);
});

// Start dance button plays the currently loaded song
startButton.addEventListener("click", () => {
  if (currentPlayingIndex !== null) {
    // If playing uploaded song, resume that
    playUploadedFile(currentPlayingIndex);
  } else {
    // Playing normal song from selector
    isUploadedSongPlaying = false;
    playSelectedSong(currentSongPath, selectedSongName);
  }
});

// Audio player pause event
audioPlayer.addEventListener("pause", () => {
  if (isPlaying && !audioPlayer.ended) {
    clearInterval(intervalId);
    intervalId = null;
    isPaused = true;
    statusDiv.innerHTML = `Paused: ${selectedSongName}`;
    document.querySelector(".container").classList.remove("playing");

    if (socket.readyState === WebSocket.OPEN) {
      socket.send("pause");
      console.log(`Song paused: ${selectedSongName}`);
    }
  }
});

// Audio player play/resume event
audioPlayer.addEventListener("play", () => {
  if (isPaused) {
    if (!intervalId) {
      intervalId = setInterval(sendSteps, 5000);
    }
    statusDiv.innerHTML = "Song Playing...";
    document.querySelector(".container").classList.add("playing");
    isPaused = false;
    isPlaying = true;

    if (socket.readyState === WebSocket.OPEN) {
      socket.send("resume");
      console.log(`Song resumed: ${selectedSongName}`);
    }
  } else if (!isPlaying) {
    if (!intervalId) {
      intervalId = setInterval(sendSteps, 5000);
    }
    statusDiv.innerHTML = "Song Playing...";
    document.querySelector(".container").classList.add("playing");
    isPlaying = true;

    if (socket.readyState === WebSocket.OPEN) {
      socket.send(`song:${selectedSongName}`);
      console.log(`Song started via play event: ${selectedSongName}`);
    }
  }
});

// Audio player ended event
audioPlayer.addEventListener("ended", () => {
  clearInterval(intervalId);
  intervalId = null;
  step = 1;
  isPlaying = false;
  isPaused = false;
  currentPlayingIndex = null;
  isUploadedSongPlaying = false; // Reset uploaded song flag

  statusDiv.innerHTML = `Ended: ${selectedSongName}`;
  document.querySelector(".container").classList.remove("playing");

  if (socket.readyState === WebSocket.OPEN) {
    socket.send("stop");
    console.log(`Song ended: ${selectedSongName}`);
  }
});

// Load first song on page load
window.addEventListener("DOMContentLoaded", () => {
  if (songSelector.options.length > 0) {
    const defaultPath = songSelector.value;
    const defaultName = songSelector.options[songSelector.selectedIndex].text;
    isUploadedSongPlaying = false; // Mark as normal song
    preloadSong(defaultPath, defaultName);
  }
});

// Expose functions if needed in HTML inline (optional)
window.playUploadedFile = playUploadedFile;
window.removeUploadedFile = removeUploadedFile;