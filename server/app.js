'use strict';

const express = require('express');
const path    = require('path');
const open    = require('open');
const chalk   = require('chalk');
const net     = require('net');

const snippetsRoute = require('./routes/snippets');
const quizRoute     = require('./routes/quiz');
const habitsRoute   = require('./routes/habits');
const docsRoute     = require('./routes/docs');
const aiRoute       = require('./routes/ai');

const app = express();

app.use(express.json());
app.use(express.static(path.join(__dirname, '../client')));

app.use('/api/snippets', snippetsRoute);
app.use('/api/quiz',     quizRoute);
app.use('/api/habits',   habitsRoute);
app.use('/api/docs',     docsRoute);
app.use('/api/ai',       aiRoute);

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../client/index.html'));
});

function getPort(start) {
  return new Promise((resolve) => {
    const s = net.createServer();
    s.listen(start, () => { s.close(() => resolve(start)); });
    s.on('error', () => resolve(getPort(start + 1)));
  });
}

const preferredPort = parseInt(process.env.AIONIX_PORT) || 3000;
const autoOpen      = process.env.AIONIX_AUTO_OPEN !== 'false';
const userName      = process.env.AIONIX_NAME || 'Developer';

getPort(preferredPort).then(PORT => {
  app.listen(PORT, async () => {
    console.log();
    console.log(chalk.hex('#00ff9f')(`  ╔══════════════════════════════════════════════╗`));
    console.log(chalk.hex('#00ff9f')(`  ║`) + chalk.hex('#ffffff').bold(`   🟢 AIONIX IS LIVE                         `) + chalk.hex('#00ff9f')(`║`));
    console.log(chalk.hex('#00ff9f')(`  ╠══════════════════════════════════════════════╣`));
    console.log(chalk.hex('#00ff9f')(`  ║`) + `   🌐 ` + chalk.hex('#ffff00')(`http://localhost:${PORT}`.padEnd(39)) + chalk.hex('#00ff9f')(`║`));
    console.log(chalk.hex('#00ff9f')(`  ║`) + `   👤 ` + chalk.hex('#888888')(`User: `.padEnd(6)) + chalk.hex('#ffffff')(userName.padEnd(33)) + chalk.hex('#00ff9f')(`║`));
    console.log(chalk.hex('#00ff9f')(`  ║`) + `   🔌 ` + chalk.hex('#888888')(`Port: `.padEnd(6)) + chalk.hex('#ffffff')(String(PORT).padEnd(33)) + chalk.hex('#00ff9f')(`║`));
    console.log(chalk.hex('#00ff9f')(`  ╠══════════════════════════════════════════════╣`));
    console.log(chalk.hex('#00ff9f')(`  ║`) + chalk.hex('#888888')(`   Press Ctrl+C to stop the server           `) + chalk.hex('#00ff9f')(`║`));
    console.log(chalk.hex('#00ff9f')(`  ╚══════════════════════════════════════════════╝`));
    console.log();

    if (autoOpen) await open(`http://localhost:${PORT}`);
    else console.log(chalk.hex('#888888')(`  ↗ Open manually: http://localhost:${PORT}\n`));
  });
});

module.exports = app;