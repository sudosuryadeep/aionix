const express = require('express');
const path = require('path');
const open = require('open');
const chalk = require('chalk');
const net = require('net');

const snippetsRoute = require('./routes/snippets');
const quizRoute = require('./routes/quiz');
const habitsRoute = require('./routes/habits');
const docsRoute = require('./routes/docs');

const app = express();

app.use(express.json());
app.use(express.static(path.join(__dirname, '../client')));

app.use('/api/snippets', snippetsRoute);
app.use('/api/quiz', quizRoute);
app.use('/api/habits', habitsRoute);
app.use('/api/docs', docsRoute);

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../client/index.html'));
});

function getPort(start) {
  return new Promise((resolve) => {
    const server = net.createServer();
    server.listen(start, () => { server.close(() => resolve(start)); });
    server.on('error', () => resolve(getPort(start + 1)));
  });
}

const preferredPort = parseInt(process.env.AIONIX_PORT) || 3000;
const autoOpen = process.env.AIONIX_AUTO_OPEN !== 'false';

getPort(preferredPort).then(PORT => {
  app.listen(PORT, async () => {
    console.log(chalk.green(`✅ Server running at http://localhost:${PORT}`));
    if (autoOpen) {
      console.log(chalk.yellow('Opening browser...'));
      await open(`http://localhost:${PORT}`);
    } else {
      console.log(chalk.cyan(`👉 Open manually: http://localhost:${PORT}`));
    }
  });
});

module.exports = app;
