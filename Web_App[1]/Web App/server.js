const express = require('express');
const path = require('path'); 
const WebSocket = require('ws');
const app = express();

// Serve static files from the "public" folder
app.use(express.static(path.join(__dirname, 'public')));

// Home route serves the index.html file
app.get('/', (req, res) => {
  console.log("Home page requested");
  res.sendFile(path.join(__dirname, 'index.html'));
});

// Start the server on port 3000
const server = app.listen(3000, () => {
  console.log('Server is running at http://localhost:3000');
});

// Create WebSocket server
const wss = new WebSocket.Server({ server });

wss.on('connection', (ws) => {
  console.log('Client connected');

  // When a message is received from the frontend (signals 1-10 and "start")
  ws.on('message', (message) => {
    console.log('Received message:', message);
    
    // For now, logging to the console to visualize the signals
    if (parseInt(message) >= 1 && parseInt(message) <= 10) {
      console.log(`Step signal received: ${message}`);  // Log signal step
    }
    
    // You can add additional logic for handling other messages like "start" here
  });

  // Send a message to the client confirming the connection
  ws.send('Connected to WebSocket server');
});
