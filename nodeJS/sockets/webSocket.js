// Node.js WebSocket server script
// const http = require('http');
// const WebSocketServer = require('websocket').server;
// const server = http.createServer();
// server.listen(9898);
// const wsServer = new WebSocketServer({
//     httpServer: server
// });
// wsServer.on('request', function(request) {
//     const connection = request.accept(null, request.origin);
//     connection.on('message', function(message) {
//         console.log(wsServer.clients);
//       console.log('Received Message:', message.utf8Data);
//       while(true) {
//       connection.sendUTF('Hi this is WebSocket server!');
//       }
//     });
//     connection.on('close', function(reasonCode, description) {
//         console.log('Client has disconnected.');
//     });
// });


const express = require('express');
const http = require('http');
const WebSocket = require('ws');

const port = 6969;
const server = http.createServer(express);
const wss = new WebSocket.Server({ server })

wss.on('connection', function connection(ws) {
    ws.id = Math.trunc(Math.random() * 1000);
    ws.send('Connection establieshed ' + ws.id);
  ws.on('message', function incoming(data) {

    
    wss.clients.forEach(function each(client) {
      if (client !== ws && client.readyState === WebSocket.OPEN) {
        console.log(data);
        client.send(ws.id+ " : " +data);
      }
    })
  })
})

server.listen(port, function() {
  console.log(`Server is listening on ${port}!`)
})