#!/usr/bin/env node
'use strict';

const chalk = require('chalk');
const net = require('net');
const fs = require('fs');
const path = require('path');
const os = require('os');

const CONFIG_FILE = path.join(os.homedir(), '.aionix', 'config.json');

let config = { name: 'Developer', port: 3000, autoOpen: true };
try {
  if (fs.existsSync(CONFIG_FILE)) {
    config = JSON.parse(fs.readFileSync(CONFIG_FILE, 'utf8'));
  }
} catch(e) {}

// ═══════════════════════════════════════════
//  NEON ASCII BANNER
// ═══════════════════════════════════════════
function showBanner() {
  console.clear();
  console.log(chalk.hex('#00ff9f').bold(`
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  ░                                                ░
  ░    ██████╗ ██╗ ██████╗ ███╗   ██╗██╗██╗  ██╗  ░
  ░   ██╔══██╗██║██╔═══██╗████╗  ██║██║╚██╗██╔╝  ░
  ░   ███████║██║██║   ██║██╔██╗ ██║██║ ╚███╔╝   ░
  ░   ██╔══██║██║██║   ██║██║╚██╗██║██║ ██╔██╗   ░
  ░   ██║  ██║██║╚██████╔╝██║ ╚████║██║██╔╝ ██╗  ░
  ░   ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝  ░
  ░                                                ░
  ░         OFFLINE  DEVELOPER  TOOLKIT            ░
  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░`));

  console.log(chalk.hex('#00ff9f')(`  ╔${'═'.repeat(50)}╗`));
  console.log(chalk.hex('#00ff9f')(`  ║`) + chalk.hex('#ffffff')(`  👾 Welcome back, `) + chalk.hex('#ffff00').bold(`${config.name}`.padEnd(29)) + chalk.hex('#00ff9f')(`║`));
  console.log(chalk.hex('#00ff9f')(`  ║`) + chalk.hex('#888888')(`  v1.2.0  ·  AI Chat  ·  Image Gen  ·  Tools  `) + chalk.hex('#00ff9f')(` ║`));
  console.log(chalk.hex('#00ff9f')(`  ╚${'═'.repeat(50)}╝`));
  console.log();
}

// ═══════════════════════════════════════════
//  ASCII LOADING BAR
// ═══════════════════════════════════════════
function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }

async function loadingBar(label, duration = 800) {
  const width = 30;
  process.stdout.write(`  ${chalk.hex('#888888')(label.padEnd(20))} [`);
  for (let i = 0; i <= width; i++) {
    const filled = chalk.hex('#00ff9f')('█'.repeat(i));
    const empty = chalk.hex('#333333')('░'.repeat(width - i));
    const pct = Math.round((i / width) * 100);
    process.stdout.write(`\r  ${chalk.hex('#888888')(label.padEnd(20))} [${filled}${empty}] ${chalk.hex('#ffff00')(pct + '%')}`);
    await sleep(duration / width);
  }
  process.stdout.write(`\r  ${chalk.hex('#00ff9f')(label.padEnd(20))} [${'█'.repeat(width)}] ${chalk.hex('#00ff9f')('DONE ✓')}\n`);
}

// ═══════════════════════════════════════════
//  SPINNER
// ═══════════════════════════════════════════
function spinner(label) {
  const frames = ['⠋','⠙','⠹','⠸','⠼','⠴','⠦','⠧','⠇','⠏'];
  let i = 0;
  const id = setInterval(() => {
    process.stdout.write(`\r  ${chalk.hex('#00ff9f')(frames[i])} ${chalk.hex('#888888')(label)}`);
    i = (i + 1) % frames.length;
  }, 80);
  return () => {
    clearInterval(id);
    process.stdout.write(`\r  ${chalk.hex('#00ff9f')('✓')} ${chalk.hex('#ffffff')(label)}\n`);
  };
}

// ═══════════════════════════════════════════
//  PORT CHECK
// ═══════════════════════════════════════════
async function checkPort(port) {
  return new Promise((resolve) => {
    const s = net.createServer();
    s.listen(port, () => { s.close(() => resolve(false)); });
    s.on('error', () => resolve(true));
  });
}

async function showPortTable(preferredPort) {
  console.log(chalk.hex('#00ff9f')(`  ┌─────────────────────────────┐`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#ffff00').bold(`   📡 PORT STATUS MONITOR     `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  ├──────────┬──────────────────┤`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#888888')(`   PORT   `) + chalk.hex('#00ff9f')(`│`) + chalk.hex('#888888')(`     STATUS         `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  ├──────────┼──────────────────┤`));

  const ports = [preferredPort, preferredPort+1, preferredPort+2, preferredPort+3];
  for (const p of ports) {
    const inUse = await checkPort(p);
    const portStr = String(p).padEnd(6);
    const status = inUse
      ? chalk.hex('#ff4444')('● IN USE          ')
      : chalk.hex('#00ff9f')('○ FREE            ');
    const star = p === preferredPort ? chalk.hex('#ffff00')(' ◄') : '  ';
    console.log(chalk.hex('#00ff9f')(`  │`) + `   ${chalk.hex('#ffffff')(portStr)}` + chalk.hex('#00ff9f')(`│`) + `  ${status}` + chalk.hex('#00ff9f')(`│`) + star);
  }
  console.log(chalk.hex('#00ff9f')(`  └──────────┴──────────────────┘`));
  console.log();
}

// ═══════════════════════════════════════════
//  --config FLAG
// ═══════════════════════════════════════════
if (process.argv.includes('--config')) {
  showBanner();
  console.log(chalk.hex('#00ff9f')(`  ┌─────────────────────────────────────┐`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#ffff00').bold(`   ⚙️  CURRENT CONFIG                `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  ├─────────────────────────────────────┤`));
  Object.entries(config).forEach(([k, v]) => {
    console.log(chalk.hex('#00ff9f')(`  │`) + `  ${chalk.hex('#888888')(k.padEnd(15))} ${chalk.hex('#ffffff')(String(v).padEnd(20))}` + chalk.hex('#00ff9f')(`│`));
  });
  console.log(chalk.hex('#00ff9f')(`  └─────────────────────────────────────┘`));
  console.log(chalk.hex('#888888')(`\n  📁 ${CONFIG_FILE}\n`));
  process.exit(0);
}

// ═══════════════════════════════════════════
//  MAIN
// ═══════════════════════════════════════════
async function main() {
  showBanner();

  await loadingBar('Initializing', 400);
  await loadingBar('Loading modules', 300);
  await loadingBar('Checking system', 300);
  console.log();

  await showPortTable(config.port || 3000);

  const stopSpin = spinner('Starting AIONIX server...');
  await sleep(600);
  stopSpin();

  process.env.AIONIX_PORT = config.port || 3000;
  process.env.AIONIX_AUTO_OPEN = config.autoOpen !== false ? 'true' : 'false';
  process.env.AIONIX_NAME = config.name || 'Developer';

  require('../server/app');
}

main().catch(e => {
  console.error(chalk.hex('#ff4444')('\n  ✗ Error: ' + e.message));
  process.exit(1);
});