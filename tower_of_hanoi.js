"use strict";

const towerOfHanoi = function (height) {
  const moveRing = function (ring, target) {
    const home = rings[ring];
    const spare = [1, 2, 3].find((tower) => {
      return tower !== target && tower !== home;
    });
    if (rings[ring + 1]) {
        if (rings[ring + 1] !== spare) {
          moveRing((ring + 1), spare);
        }
    }
    rings[ring] = target;
    console.log(`Moved ring ${ring} from ${home} to ${target}.`);
    moves++;
    if (rings[ring + 1]) {
      moveRing((ring + 1), target);
    }
  }

  let moves = 0;
  const rings = [];
  for (let i = 0; i < height; i++) {
    rings.push(1);
  };
  console.log(rings);
  moveRing(0, 3);
  console.log(rings);
  console.log(`Moves: ${moves}`);
}

// towerOfHanoi(3);
// towerOfHanoi(4);
// towerOfHanoi(5);
// towerOfHanoi(6);
// towerOfHanoi(7);
towerOfHanoi(8);
// towerOfHanoi(9);
// towerOfHanoi(10);
// towerOfHanoi(11);
