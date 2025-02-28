class GameAI {
    constructor(name) {
        this.name = name;
    }

    move(from, to) {
        
    }

    attack(target) {}
}

globalThis.createAI = (name) => new GameAI(name);
