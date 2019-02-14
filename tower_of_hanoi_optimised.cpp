#include <iostream>

void moveRing(long rings[], long& moves, long ringIndex, long target);
void moveRing(long rings[], long ringIndex, long target);

int main(int argc, char const *argv[]) {
    using namespace std;
    int heightInput;
    // cout << "Please enter the number of rings in your Tower of Hanoi puzzle." << endl;
    // cin >> heightInput;
   if (argc > 1) {
     heightInput = atoi(argv[1]);
   } else {
     heightInput = 12;
   }

    // cout << heightInput << endl;
    long rings[heightInput + 1];
    for (int i = 0; i < heightInput; i++) {
        rings[i] = 1;
    }
    rings[heightInput] = 0;
    // for (int i = 0; i < heightInput; i++) {
    //     cout << rings[i] << " ";
    // }
    // cout << endl;
    if (argc > 2) {
      long moves = 0;
      moveRing(rings, moves, 0, 3);
      cout << "Moves: " << moves << endl;
    } else {
      moveRing(rings, 0, 3);
    }

    // for (int i = 0; i < heightInput; i++) {
    //     cout << rings[i] << " ";
    // }
    // cout << endl;

    return 0;
}

void moveRing(long rings[], long& moves, long ringIndex, long target){
  if (rings[ringIndex + 1])
      moveRing(rings, moves, (ringIndex + 1), 6 - target - rings[ringIndex]);
  rings[ringIndex] = target;
  // cout << "Moved ring " << ringIndex << " from " << home << " to " << target << "." << endl;
  moves++;
  if (rings[ringIndex + 1])
      moveRing(rings, moves, (ringIndex + 1), target);
}

void moveRing(long rings[], long ringIndex, long target){
  if (rings[ringIndex + 1])
      moveRing(rings, ringIndex + 1, 6 - target - rings[ringIndex]);
  rings[ringIndex] = target;
  // cout << "Moved ring " << ringIndex << " from " << home << " to " << target << "." << endl;
  if (rings[ringIndex + 1])
      moveRing(rings, ringIndex + 1, target);
}
