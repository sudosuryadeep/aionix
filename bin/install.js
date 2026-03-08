#!/usr/bin/env node
'use strict';

const chalk = require('chalk');
const readline = require('readline');
const fs = require('fs');
const path = require('path');
const os = require('os');

const CONFIG_DIR = path.join(os.homedir(), '.aionix');
const CONFIG_FILE = path.join(CONFIG_DIR, 'config.json');

function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }

async function typewrite(text, delay = 18) {
  for (const ch of text) {
    process.stdout.write(ch);
    await sleep(delay);
  }
  process.stdout.write('\n');
}

async function showBanner() {
  console.clear();
  const lines = [
    ``,
    `  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░`,
    `  ░    ██████╗ ██╗ ██████╗ ███╗   ██╗██╗██╗  ██╗  ░`,
    `  ░   ██╔══██╗██║██╔═══██╗████╗  ██║██║╚██╗██╔╝  ░`,
    `  ░   ███████║██║██║   ██║██╔██╗ ██║██║ ╚███╔╝   ░`,
    `  ░   ██╔══██║██║██║   ██║██║╚██╗██║██║ ██╔██╗   ░`,
    `  ░   ██║  ██║██║╚██████╔╝██║ ╚████║██║██╔╝ ██╗  ░`,
    `  ░   ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝  ░`,
    `  ░                                                ░`,
    `  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░`,
    ``,
  ];
  for (const line of lines) {
    console.log(chalk.hex('#00ff9f').bold(line));
    await sleep(40);
  }
  await typewrite(chalk.hex('#ffff00').bold(`         🚀 WELCOME TO AIONIX INSTALLER`), 12);
  console.log();
}

async function animatedLine(char = '═', width = 52, color = '#00ff9f') {
  process.stdout.write(`  `);
  for (let i = 0; i < width; i++) {
    process.stdout.write(chalk.hex(color)(char));
    await sleep(8);
  }
  process.stdout.write('\n');
}

function question(rl, q) {
  return new Promise(resolve => rl.question(q, resolve));
}

async function setup() {
  await showBanner();
  await animatedLine('─');

  console.log(chalk.hex('#00ff9f')(`  ┌─────────────────────────────────────────────────┐`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#ffffff').bold(`   ⚙️  FIRST TIME SETUP                          `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#888888')(`   Configure your personal AIONIX environment    `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  └─────────────────────────────────────────────────┘`));
  console.log();

  const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

  const name     = await question(rl, chalk.hex('#00ff9f')(`  ┃ `) + chalk.hex('#ffff00')(`👤 Your name         `) + chalk.hex('#888888')(`› `));
  const port     = await question(rl, chalk.hex('#00ff9f')(`  ┃ `) + chalk.hex('#ffff00')(`🔌 Port              `) + chalk.hex('#888888')(`› [3000] `));
  const alias    = await question(rl, chalk.hex('#00ff9f')(`  ┃ `) + chalk.hex('#ffff00')(`⚡ Custom alias      `) + chalk.hex('#888888')(`› [aionix] `));
  const autoOpen = await question(rl, chalk.hex('#00ff9f')(`  ┃ `) + chalk.hex('#ffff00')(`🌐 Auto-open browser `) + chalk.hex('#888888')(`› [Y/n] `));
  rl.close();

  const finalName     = name.trim()     || 'Developer';
  const finalPort     = parseInt(port.trim()) || 3000;
  const finalAlias    = alias.trim()    || 'aionix';
  const finalAutoOpen = autoOpen.trim().toLowerCase() !== 'n';

  const config = {
    name: finalName,
    port: finalPort,
    alias: finalAlias,
    autoOpen: finalAutoOpen,
    installedAt: new Date().toISOString(),
    version: '1.2.0'
  };

  if (!fs.existsSync(CONFIG_DIR)) fs.mkdirSync(CONFIG_DIR, { recursive: true });
  fs.writeFileSync(CONFIG_FILE, JSON.stringify(config, null, 2));

  console.log();
  await animatedLine('─');

  console.log(chalk.hex('#00ff9f').bold(`\n  ✓ Config saved → ${CONFIG_FILE}\n`));

  // Show saved config table
  console.log(chalk.hex('#00ff9f')(`  ┌──────────────────┬───────────────────────────────┐`));
  console.log(chalk.hex('#00ff9f')(`  │`) + chalk.hex('#ffff00').bold(`   SETTING         `) + chalk.hex('#00ff9f')(`│`) + chalk.hex('#ffff00').bold(`   VALUE                       `) + chalk.hex('#00ff9f')(`│`));
  console.log(chalk.hex('#00ff9f')(`  ├──────────────────┼───────────────────────────────┤`));
  const rows = [
    ['Name', finalName],
    ['Port', finalPort],
    ['Alias', finalAlias],
    ['Auto-open', finalAutoOpen ? 'Yes' : 'No'],
  ];
  rows.forEach(([k, v]) => {
    console.log(chalk.hex('#00ff9f')(`  │`) + `   ${chalk.hex('#888888')(k.padEnd(15))}` + chalk.hex('#00ff9f')(`│`) + `   ${chalk.hex('#ffffff')(String(v).padEnd(29))}` + chalk.hex('#00ff9f')(`│`));
  });
  console.log(chalk.hex('#00ff9f')(`  └──────────────────┴───────────────────────────────┘`));

  if (finalAlias !== 'aionix') {
    console.log();
    console.log(chalk.hex('#ffff00')(`  💡 To use "${finalAlias}" command:`));
    const isWin = process.platform === 'win32';
    if (isWin) {
      console.log(chalk.hex('#00ff9f')(`     doskey ${finalAlias}=aionix`));
    } else {
      console.log(chalk.hex('#00ff9f')(`     echo "alias ${finalAlias}='aionix'" >> ~/.bashrc && source ~/.bashrc`));
    }
  }

  console.log();
  const rl2 = readline.createInterface({ input: process.stdin, output: process.stdout });
  const launch = await question(rl2, chalk.hex('#00ff9f')(`  ┃ `) + chalk.hex('#ffff00')(`🚀 Launch AIONIX now?`) + chalk.hex('#888888')(` › [Y/n] `));
  rl2.close();

  if (launch.trim().toLowerCase() !== 'n') {
    console.log();
    process.env.AIONIX_PORT     = finalPort;
    process.env.AIONIX_AUTO_OPEN = finalAutoOpen ? 'true' : 'false';
    process.env.AIONIX_NAME     = finalName;
    require('../server/app');
  } else {
    console.log();
    console.log(chalk.hex('#00ff9f').bold(`  ╔══════════════════════════════════════╗`));
    console.log(chalk.hex('#00ff9f').bold(`  ║`) + chalk.hex('#ffffff')(`  Run anytime:  `) + chalk.hex('#ffff00').bold(`aionix              `) + chalk.hex('#00ff9f').bold(`║`));
    console.log(chalk.hex('#00ff9f').bold(`  ║`) + chalk.hex('#ffffff')(`  Edit config:  `) + chalk.hex('#ffff00').bold(`aionix --config     `) + chalk.hex('#00ff9f').bold(`║`));
    console.log(chalk.hex('#00ff9f').bold(`  ╚══════════════════════════════════════╝\n`));
    process.exit(0);
  }
}

setup().catch(e => {
  console.error(chalk.hex('#ff4444')('\n  ✗ Setup failed: ' + e.message));
  process.exit(1);
});