"use strict";

const Puzzle = function (height) {
  this.moves = 0;
  this.rings = this.constructPuzzle(height);
  console.log(this.rings);
  this.moveRing(0, 3);
  console.log(this.rings);
  console.log(`Moves: ${this.moves}`);
}

Puzzle.prototype.constructPuzzle = function (height) {
  const rings = [];
  for (let i = 0; i < height; i++) {
    rings.push(1);
  }
  return rings;
}

Puzzle.prototype.moveRing = function (ring, target) {
  const home = this.rings[ring];
  const spare = [1, 2, 3].find((tower) => {
    return tower !== target && tower !== home;
  });
  if (this.rings[ring + 1]) {
      if (this.rings[ring + 1] !== spare) {
        this.moveRing((ring + 1), spare);
      }
  }
  this.rings[ring] = target;
  console.log(`Moved ring ${ring} from ${home} to ${target}.`);
  this.moves++;
  if (this.rings[ring + 1]) {
    this.moveRing((ring + 1), target);
  }
}

// const puzzle3 = new Puzzle(3);
// const puzzle4 = new Puzzle(4);
// const puzzle5 = new Puzzle(5);
// const puzzle6 = new Puzzle(6);
// const puzzle7 = new Puzzle(7);
const puzzle8 = new Puzzle(8);
// const puzzle9 = new Puzzle(9);
// const puzzle10 = new Puzzle(10);
// const puzzle11 = new Puzzle(11);
