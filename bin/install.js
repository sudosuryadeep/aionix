
'use strict';

const chalk = require('chalk');
const readline = require('readline');
const fs = require('fs');
const os = require('os');
const path = require('path');

const CONFIG_DIR = path.join(os.homedir(), '.aionix');
const CONFIG_FILE = path.join(CONFIG_DIR, 'config.json');

console.log(chalk.cyan.bold(`
+==============================+
|        🚀 AIONIX             |
|  Offline Developer Toolkit   |
+==============================+
`));

console.log(chalk.green('✅ AIONIX successfully installed!\n'));

let config = {};
try {
  if (fs.existsSync(CONFIG_FILE)) {
    config = JSON.parse(fs.readFileSync(CONFIG_FILE, 'utf8'));
  }
} catch(e) {}

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function question(q) {
  return new Promise(resolve => rl.question(q, resolve));
}

async function setup() {
  console.log(chalk.yellow('⚙️  Quick Setup\n'));

  const name = await question(chalk.white('👤 Your name: '));
  const port = await question(chalk.white('🔌 Preferred port (default 3000): '));
  const alias = await question(chalk.white('⚡ Custom command alias (default: aionix): '));
  const autoOpen = await question(chalk.white('🌐 Auto open browser? (y/n, default y): '));

  const finalPort = port.trim() || '3000';
  const finalAlias = alias.trim() || 'aionix';
  const finalName = name.trim() || 'Developer';
  const finalAutoOpen = autoOpen.trim().toLowerCase() !== 'n';

  config = {
    name: finalName,
    port: parseInt(finalPort),
    alias: finalAlias,
    autoOpen: finalAutoOpen,
    installedAt: new Date().toISOString()
  };

  if (!fs.existsSync(CONFIG_DIR)) fs.mkdirSync(CONFIG_DIR, { recursive: true });
  fs.writeFileSync(CONFIG_FILE, JSON.stringify(config, null, 2));

  console.log(chalk.green('\n✅ Config saved!'));
  console.log(chalk.gray(`📁 ${CONFIG_FILE}\n`));

  if (finalAlias !== 'aionix') {
    console.log(chalk.yellow(`💡 To use "${finalAlias}" as your command:`));
    const isWindows = process.platform === 'win32';
    if (isWindows) {
      console.log(chalk.cyan(`   doskey ${finalAlias}=aionix`));
    } else {
      console.log(chalk.cyan(`   echo "alias ${finalAlias}='aionix'" >> ~/.bashrc && source ~/.bashrc\n`));
    }
  }

  rl.close();

  const rl2 = readline.createInterface({ input: process.stdin, output: process.stdout });
  rl2.question(chalk.yellow('\n🚀 Launch AIONIX now? (y/n, default y): '), (ans) => {
    rl2.close();
    if (ans.trim().toLowerCase() !== 'n') {
      console.log(chalk.green('\nStarting server...'));
      process.env.AIONIX_PORT = config.port || 3000;
      process.env.AIONIX_AUTO_OPEN = config.autoOpen ? 'true' : 'false';
      require('../server/app');
    } else {
      console.log(chalk.cyan('\n👉 Run anytime:'), chalk.white.bold('aionix'));
      console.log(chalk.cyan('⚙️  Edit config:'), chalk.white.bold('aionix --config\n'));
      process.exit(0);
    }
  });
}

setup().catch(e => { console.error(e); rl.close(); process.exit(1); });
