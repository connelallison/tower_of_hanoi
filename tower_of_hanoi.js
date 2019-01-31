"use strict";

const Ring = function (level) {
  this.level = level;
  this.tower = 1;
}

const Puzzle = function (height) {
  this.moves = 0;
  this.rings = this.constructPuzzle(height);
  console.log(this.rings.map((ring) => {
    return ring.tower;
  }));
  this.moveRing(this.rings[0], 3);
  console.log(this.rings.map((ring) => {
    return ring.tower;
  }));
  console.log(`Moves: ${this.moves}`);
}

Puzzle.prototype.constructPuzzle = function (height) {
  const rings = [];
  for (let i = 0; i < height; i++) {
    const ring = new Ring(i);
    rings.push(ring);
  }
  return rings;
}

Puzzle.prototype.moveRing = function (ring, target) {
  const home = ring.tower;
  const spare = [1, 2, 3].find((tower) => {
    return tower !== target && tower !== home;
  });
  if (this.rings[ring.level + 1]) {
    // for (let i = ring.level + 1; i < array.length; i++) {
      if (this.rings[ring.level + 1].tower !== spare) {
        this.moveRing(this.rings[ring.level + 1], spare);
      }
    // }
  }
  ring.tower = target;
  console.log(`Moved ring ${ring.level} from ${home} to ${target}.`);
  this.moves++;
  if (this.rings[ring.level + 1]) {
    this.moveRing(this.rings[ring.level + 1], target);
  }
}

// const puzzle3 = new Puzzle(3);
// const puzzle4 = new Puzzle(4);
// const puzzle5 = new Puzzle(5);
// const puzzle6 = new Puzzle(6);
// const puzzle7 = new Puzzle(7);
const puzzle8 = new Puzzle(8);
