"use strict";

const towerOfHanoi = function (height) {
  const moveRing = function (ring, target) {
    // const home = rings[ring];
    // const spare = [1, 2, 3].find((tower) => {
    //   return tower !== target && tower !== home;
    // });
    if (rings[ring + 1]) {
          moveRing((ring + 1), 6 - target - rings[ring]);
    }
    rings[ring] = target;
    // console.log(`Moved ring ${ring} from ${home} to ${target}.`);
    moves++;
    if (rings[ring + 1]) {
      moveRing((ring + 1), target);
    }
  }

  let moves = 0;
  const rings = [];
  for (let i = 0; i < height; i++) {
    rings[i] = 1;
  };
  // console.log(rings);
  moveRing(0, 3);
  // console.log(rings);
  console.log(`Moves: ${moves}`);
}
if (process.argv.length > 2) {
  towerOfHanoi(process.argv[2]);
} else {
  towerOfHanoi(12);
}
