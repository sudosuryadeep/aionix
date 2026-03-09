/**
 * GALACTIC DOMINATION: A 2000-Line Space Strategy Game
 * 
 * A complex simulation of interstellar conquest featuring:
 * - Procedurally generated galaxy with stars, planets, and resources
 * - Player empire management with fleets, research, and economy
 * - AI opponents with dynamic behavior
 * - Real-time combat system
 * - Tech tree with 20+ technologies
 * - Diplomatic relations and espionage
 */

// ============================================================================
// CORE CONFIGURATION & CONSTANTS
// ============================================================================

const CONFIG = {
    GALAXY_SIZE: 100,
    STAR_COUNT: 75,
    PLAYER_START_STAR: null, // Will be set during generation
    TICK_RATE: 100, // ms per game tick
    COMBAT_RESOLUTION_TICKS: 5,
    RESEARCH_POINTS_PER_POP: 0.1,
    CREDITS_PER_POP_BASE: 1,
    FLEET_SPEED: 0.5, // stars per tick
    MAX_FLEETS_PER_PLAYER: 20,
    ESPIONAGE_COST: 100,
    ESPIONAGE_SUCCESS_RATE: 0.3,
    SABOTAGE_MULTIPLIER: 0.5,
    ALLIANCE_BONUS: 1.2,
};

const RESOURCE_TYPES = {
    MINERALS: 'minerals',
    ENERGY: 'energy',
    POPULATION: 'population',
    RESEARCH: 'research',
    CREDITS: 'credits',
};

const BUILDING_TYPES = {
    MINE: 'mine',
    POWER_PLANT: 'power_plant',
    RESEARCH_LAB: 'research_lab',
    SHIPYARD: 'shipyard',
    DEFENSE_TURRET: 'defense_turret',
};

const SHIP_TYPES = {
    SCOUT: { cost: { minerals: 10, energy: 5 }, attack: 2, defense: 1, speed: 1.5 },
    FRIGATE: { cost: { minerals: 25, energy: 15 }, attack: 5, defense: 3, speed: 1.0 },
    DESTROYER: { cost: { minerals: 50, energy: 30 }, attack: 12, defense: 8, speed: 0.8 },
    CRUISER: { cost: { minerals: 100, energy: 60 }, attack: 25, defense: 20, speed: 0.6 },
    BATTLESHIP: { cost: { minerals: 250, energy: 150 }, attack: 60, defense: 50, speed: 0.4 },
};

const TECH_TREE = {
    COMBAT_ALGORITHMS: { cost: 100, effect: 'combat_bonus', bonus: 0.1 },
    ENERGY_SHIELDS: { cost: 150, effect: 'defense_bonus', bonus: 0.15 },
    ADVANCED_PROPULSION: { cost: 120, effect: 'speed_bonus', bonus: 0.2 },
    COLONIZATION: { cost: 200, effect: 'pop_growth', bonus: 0.25 },
    MINING_EFFICIENCY: { cost: 80, effect: 'mineral_bonus', bonus: 0.3 },
    ESPIONAGE_NETWORK: { cost: 250, effect: 'espionage_bonus', bonus: 0.2 },
    CLOAKING_DEVICE: { cost: 300, effect: 'stealth', bonus: 0.1 },
    PLANETARY_SHIELDS: { cost: 400, effect: 'planet_defense', bonus: 0.5 },
    TITAN_CONSTRUCTION: { cost: 600, effect: 'unlock_titan', bonus: null },
};

const DIPLOMACY_STATUS = {
    WAR: 'war',
    PEACE: 'peace',
    ALLIANCE: 'alliance',
    NON_AGGRESSION: 'non_aggression',
};

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

const Utils = {
    random: (min, max) => Math.random() * (max - min) + min,
    randomInt: (min, max) => Math.floor(Math.random() * (max - min + 1)) + min,
    distance: (x1, y1, x2, y2) => Math.hypot(x2 - x1, y2 - y1),
    generateId: () => Math.random().toString(36).substr(2, 9),
    clamp: (value, min, max) => Math.min(max, Math.max(min, value)),
    chance: (probability) => Math.random() < probability,
    weightedRandom: (items, weights) => {
        const total = weights.reduce((a, b) => a + b, 0);
        let random = Math.random() * total;
        for (let i = 0; i < items.length; i++) {
            if (random < weights[i]) return items[i];
            random -= weights[i];
        }
        return items[0];
    }
};

// ============================================================================
// CLASS DEFINITIONS
// ============================================================================

class Planet {
    constructor(x, y, starId) {
        this.id = Utils.generateId();
        this.x = x;
        this.y = y;
        this.starId = starId;
        this.ownerId = null;
        this.population = Utils.randomInt(1, 10);
        this.buildings = [];
        this.defenses = 0;
        this.minerals = Utils.randomInt(100, 500);
        this.energy = Utils.randomInt(50, 200);
        this.research = 0;
        this.name = this.generateName();
    }

    generateName() {
        const prefixes = ['New', 'Old', 'Alpha', 'Beta', 'Gamma', 'Delta', 'Epsilon', 'Omicron'];
        const suffixes = ['Terra', 'Prime', 'Secundus', 'Major', 'Minor', 'Station', 'Outpost', 'Colony'];
        return `${prefixes[Utils.randomInt(0, prefixes.length - 1)]} ${suffixes[Utils.randomInt(0, suffixes.length - 1)]}`;
    }

    addBuilding(type) {
        if (this.buildings.length < this.population) {
            this.buildings.push(type);
            return true;
        }
        return false;
    }

    produce(technologies = []) {
        let mineralBonus = 1.0;
        let energyBonus = 1.0;
        let researchBonus = 1.0;
        let popGrowth = 0.01;

        technologies.forEach(tech => {
            if (tech === 'MINING_EFFICIENCY') mineralBonus += TECH_TREE.MINING_EFFICIENCY.bonus;
            if (tech === 'ADVANCED_PROPULSION') energyBonus += 0.1; // Just for flavor
            if (tech === 'COLONIZATION') popGrowth += TECH_TREE.COLONIZATION.bonus;
        });

        let mineralsProduced = 0;
        let energyProduced = 0;
        let researchProduced = 0;

        this.buildings.forEach(building => {
            switch (building) {
                case BUILDING_TYPES.MINE:
                    mineralsProduced += 2 * mineralBonus;
                    break;
                case BUILDING_TYPES.POWER_PLANT:
                    energyProduced += 5 * energyBonus;
                    break;
                case BUILDING_TYPES.RESEARCH_LAB:
                    researchProduced += 3 * researchBonus;
                    break;
            }
        });

        this.minerals += mineralsProduced;
        this.energy += energyProduced;
        this.research += researchProduced;

        // Population growth
        if (this.population < 20) {
            this.population += popGrowth * this.population;
        }

        // Natural resources (base)
        this.minerals += 1;
        this.energy += 1;
    }
}

class Star {
    constructor(x, y) {
        this.id = Utils.generateId();
        this.x = x;
        this.y = y;
        this.name = this.generateName();
        this.planets = [];
        this.ownerId = null;
        this.fleets = [];
    }

    generateName() {
        const names = ['Sol', 'Proxima', 'Alpha Centauri', 'Betelgeuse', 'Sirius', 'Vega', 'Polaris', 'Antares', 'Rigel', 'Deneb'];
        return names[Utils.randomInt(0, names.length - 1)] + '-' + Utils.randomInt(1, 999);
    }

    addPlanet(planet) {
        this.planets.push(planet);
    }

    getTotalPopulation() {
        return this.planets.reduce((sum, p) => p.ownerId === this.ownerId ? sum + p.population : sum, 0);
    }
}

class Fleet {
    constructor(ownerId, x, y, ships = {}) {
        this.id = Utils.generateId();
        this.ownerId = ownerId;
        this.x = x;
        this.y = y;
        this.destinationId = null;
        this.destinationX = null;
        this.destinationY = null;
        this.ships = ships; // { SCOUT: count, FRIGATE: count, ... }
        this.inTransit = false;
        this.eta = 0;
    }

    addShips(type, count) {
        this.ships[type] = (this.ships[type] || 0) + count;
    }

    removeShips(type, count) {
        if (this.ships[type]) {
            this.ships[type] = Math.max(0, this.ships[type] - count);
        }
    }

    getTotalShips() {
        return Object.values(this.ships).reduce((sum, count) => sum + count, 0);
    }

    getCombatStrength() {
        let attack = 0;
        let defense = 0;
        for (let [type, count] of Object.entries(this.ships)) {
            attack += SHIP_TYPES[type].attack * count;
            defense += SHIP_TYPES[type].defense * count;
        }
        return { attack, defense };
    }

    setDestination(star, distance) {
        this.destinationId = star.id;
        this.destinationX = star.x;
        this.destinationY = star.y;
        this.inTransit = true;
        // Speed factor: weighted average of ship speeds
        let totalSpeed = 0;
        let totalShips = 0;
        for (let [type, count] of Object.entries(this.ships)) {
            totalSpeed += SHIP_TYPES[type].speed * count;
            totalShips += count;
        }
        const avgSpeed = totalShips > 0 ? totalSpeed / totalShips : 1;
        this.eta = Math.ceil(distance / (CONFIG.FLEET_SPEED * avgSpeed));
    }

    move() {
        if (this.inTransit && this.eta > 0) {
            this.eta--;
            if (this.eta === 0) {
                this.x = this.destinationX;
                this.y = this.destinationY;
                this.inTransit = false;
                return true; // Arrived
            }
        }
        return false;
    }
}

class Player {
    constructor(id, name, isAI = false) {
        this.id = id;
        this.name = name;
        this.isAI = isAI;
        this.credits = 500;
        this.researchPoints = 0;
        this.technologies = [];
        this.fleets = [];
        this.diplomacy = new Map(); // playerId -> status
        this.espionage = new Map(); // playerId -> { level, lastMission }
        this.color = `hsl(${Utils.randomInt(0, 360)}, 70%, 50%)`;
        this.stars = new Set();
    }

    addFleet(fleet) {
        if (this.fleets.length < CONFIG.MAX_FLEETS_PER_PLAYER) {
            this.fleets.push(fleet);
            return true;
        }
        return false;
    }

    removeFleet(fleetId) {
        this.fleets = this.fleets.filter(f => f.id !== fleetId);
    }

    getTotalPopulation() {
        let total = 0;
        this.stars.forEach(starId => {
            const star = game.galaxy.stars.get(starId);
            if (star) {
                total += star.getTotalPopulation();
            }
        });
        return total;
    }

    getIncome() {
        let minerals = 0, energy = 0, research = 0, credits = 0;
        this.stars.forEach(starId => {
            const star = game.galaxy.stars.get(starId);
            if (star) {
                star.planets.forEach(planet => {
                    if (planet.ownerId === this.id) {
                        minerals += planet.minerals;
                        energy += planet.energy;
                        research += planet.research;
                        credits += planet.population * CONFIG.CREDITS_PER_POP_BASE;
                    }
                });
            }
        });
        return { minerals, energy, research, credits };
    }

    researchTech(techKey) {
        const tech = TECH_TREE[techKey];
        if (tech && this.researchPoints >= tech.cost && !this.technologies.includes(techKey)) {
            this.researchPoints -= tech.cost;
            this.technologies.push(techKey);
            return true;
        }
        return false;
    }

    getDiplomacyStatus(otherId) {
        return this.diplomacy.get(otherId) || DIPLOMACY_STATUS.PEACE;
    }

    setDiplomacy(otherId, status) {
        this.diplomacy.set(otherId, status);
    }

    performEspionage(targetPlayerId, missionType) {
        if (this.credits < CONFIG.ESPIONAGE_COST) return { success: false, reason: 'Insufficient credits' };

        this.credits -= CONFIG.ESPIONAGE_COST;
        const success = Utils.chance(CONFIG.ESPIONAGE_SUCCESS_RATE * (this.hasTech('ESPIONAGE_NETWORK') ? 1.5 : 1));

        if (!success) return { success: false, reason: 'Mission failed' };

        const target = game.players.get(targetPlayerId);
        if (!target) return { success: false, reason: 'Target not found' };

        let result = { success: true, mission: missionType, data: null };

        switch (missionType) {
            case 'sabotage':
                // Reduce target's credits by 20%
                const stolen = Math.floor(target.credits * 0.2);
                target.credits -= stolen;
                result.data = { stolen };
                break;
            case 'steal_tech':
                if (target.technologies.length > 0) {
                    const tech = target.technologies[Utils.randomInt(0, target.technologies.length - 1)];
                    if (!this.technologies.includes(tech)) {
                        this.technologies.push(tech);
                        result.data = { tech };
                    } else {
                        result.data = { tech: 'already owned' };
                    }
                }
                break;
            case 'reveal_fleets':
                result.data = { fleets: target.fleets.map(f => ({ id: f.id, ships: f.ships, location: { x: f.x, y: f.y } })) };
                break;
        }

        return result;
    }

    hasTech(tech) {
        return this.technologies.includes(tech);
    }
}

class Galaxy {
    constructor() {
        this.stars = new Map();
        this.width = CONFIG.GALAXY_SIZE;
        this.height = CONFIG.GALAXY_SIZE;
    }

    generateStars(count) {
        for (let i = 0; i < count; i++) {
            const x = Utils.random(0, this.width);
            const y = Utils.random(0, this.height);
            const star = new Star(x, y);
            this.stars.set(star.id, star);
        }
    }

    generatePlanets() {
        this.stars.forEach(star => {
            const planetCount = Utils.randomInt(1, 5);
            for (let i = 0; i < planetCount; i++) {
                const angle = (i / planetCount) * Math.PI * 2;
                const distance = Utils.random(5, 20);
                const x = star.x + Math.cos(angle) * distance;
                const y = star.y + Math.sin(angle) * distance;
                const planet = new Planet(x, y, star.id);
                star.addPlanet(planet);
            }
        });
    }

    getStarAt(x, y, threshold = 10) {
        let closest = null;
        let minDist = Infinity;
        this.stars.forEach(star => {
            const dist = Utils.distance(x, y, star.x, star.y);
            if (dist < minDist && dist < threshold) {
                minDist = dist;
                closest = star;
            }
        });
        return closest;
    }
}

class Game {
    constructor() {
        this.galaxy = new Galaxy();
        this.players = new Map();
        this.currentTick = 0;
        this.running = false;
        this.selectedObject = null;
        this.log = [];
    }

    init() {
        this.galaxy.generateStars(CONFIG.STAR_COUNT);
        this.galaxy.generatePlanets();

        // Create player
        const player = new Player('player1', 'Commander', false);
        this.players.set(player.id, player);

        // Assign starting star
        const stars = Array.from(this.galaxy.stars.values());
        const startStar = stars[Utils.randomInt(0, stars.length - 1)];
        startStar.ownerId = player.id;
        player.stars.add(startStar.id);

        // Give player a starting fleet
        const startFleet = new Fleet(player.id, startStar.x, startStar.y, { SCOUT: 3, FRIGATE: 1 });
        player.addFleet(startFleet);
        startStar.fleets.push(startFleet);

        // Create AI players
        const aiCount = 3;
        for (let i = 0; i < aiCount; i++) {
            const ai = new Player(`ai_${i + 1}`, `AI Empire ${i + 1}`, true);
            this.players.set(ai.id, ai);

            // Find unclaimed star
            let unclaimedStar;
            do {
                unclaimedStar = stars[Utils.randomInt(0, stars.length - 1)];
            } while (unclaimedStar.ownerId !== null);

            unclaimedStar.ownerId = ai.id;
            ai.stars.add(unclaimedStar.id);

            const aiFleet = new Fleet(ai.id, unclaimedStar.x, unclaimedStar.y, { SCOUT: 2, FRIGATE: 1 });
            ai.addFleet(aiFleet);
            unclaimedStar.fleets.push(aiFleet);
        }

        this.logEvent('Game initialized');
    }

    start() {
        this.running = true;
        this.gameLoop();
    }

    stop() {
        this.running = false;
    }

    gameLoop() {
        if (!this.running) return;

        this.tick();
        setTimeout(() => this.gameLoop(), CONFIG.TICK_RATE);
    }

    tick() {
        this.currentTick++;

        // Production phase
        this.players.forEach(player => {
            player.stars.forEach(starId => {
                const star = this.galaxy.stars.get(starId);
                if (star) {
                    star.planets.forEach(planet => {
                        if (planet.ownerId === player.id) {
                            planet.produce(player.technologies);
                        }
                    });
                }
            });

            // Collect resources
            const income = player.getIncome();
            player.credits += income.credits;
            player.researchPoints += income.research;

            // Fleet maintenance
            player.fleets.forEach(fleet => {
                // Simple maintenance cost
                player.credits -= fleet.getTotalShips() * 0.1;
            });
        });

        // Movement phase
        this.players.forEach(player => {
            player.fleets.forEach(fleet => {
                if (fleet.move()) {
                    // Arrived at destination
                    const destStar = this.galaxy.stars.get(fleet.destinationId);
                    if (destStar) {
                        destStar.fleets.push(fleet);
                        fleet.x = destStar.x;
                        fleet.y = destStar.y;

                        // Check for combat
                        this.resolveCombatAtStar(destStar);
                    }
                }
            });
        });

        // Combat phase (periodic)
        if (this.currentTick % CONFIG.COMBAT_RESOLUTION_TICKS === 0) {
            this.galaxy.stars.forEach(star => {
                this.resolveCombatAtStar(star);
            });
        }

        // AI decision phase
        this.players.forEach(player => {
            if (player.isAI) {
                this.runAITurn(player);
            }
        });

        // Check victory conditions
        this.checkVictory();
    }

    resolveCombatAtStar(star) {
        if (star.fleets.length < 2) return;

        // Group fleets by owner
        const fleetsByOwner = new Map();
        star.fleets.forEach(fleet => {
            if (!fleetsByOwner.has(fleet.ownerId)) {
                fleetsByOwner.set(fleet.ownerId, []);
            }
            fleetsByOwner.get(fleet.ownerId).push(fleet);
        });

        // If only one owner, no combat
        if (fleetsByOwner.size === 1) return;

        // Determine combatants (max 2 sides for simplicity)
        const owners = Array.from(fleetsByOwner.keys());
        let attackerOwner, defenderOwner;

        // For now, first two owners fight
        if (owners.length >= 2) {
            attackerOwner = owners[0];
            defenderOwner = owners[1];

            const attackerFleets = fleetsByOwner.get(attackerOwner);
            const defenderFleets = fleetsByOwner.get(defenderOwner);

            // Combine fleet strengths
            let attackerStrength = { attack: 0, defense: 0 };
            let defenderStrength = { attack: 0, defense: 0 };

            attackerFleets.forEach(fleet => {
                const strength = fleet.getCombatStrength();
                attackerStrength.attack += strength.attack;
                attackerStrength.defense += strength.defense;
            });

            defenderFleets.forEach(fleet => {
                const strength = fleet.getCombatStrength();
                defenderStrength.attack += strength.attack;
                defenderStrength.defense += strength.defense;
            });

            // Apply technology bonuses
            const attacker = this.players.get(attackerOwner);
            const defender = this.players.get(defenderOwner);

            if (attacker.hasTech('COMBAT_ALGOR
