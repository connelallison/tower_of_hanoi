#include <iostream>

void moveRing(int rings[], long& moves, int ringIndex, int target);
void moveRing(int rings[], int ringIndex, int target);

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
    int rings[heightInput + 1];
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

void moveRing(int rings[], long& moves, int ringIndex, int target){
  int home = rings[ringIndex];
  int spare = 6 - target - home;
  // int spare;
  // for (int i = 1; i < 4; i++) {
  //     if (i != target && i != home) {
  //         spare = i;
  //     }
  // }
  if (rings[ringIndex + 1]) {
      if (rings[ringIndex + 1] != spare) {
          moveRing(rings, moves, (ringIndex + 1), spare);
      }
  }
  rings[ringIndex] = target;
  // cout << "Moved ring " << ringIndex << " from " << home << " to " << target << "." << endl;
  moves++;
  if (rings[ringIndex + 1]) {
      moveRing(rings, moves, (ringIndex + 1), target);
  }
}

void moveRing(int rings[], int ringIndex, int target){
  int home = rings[ringIndex];
  int spare = 6 - target - home;
  // int spare;
  // for (int i = 1; i < 4; i++) {
  //     if (i != target && i != home) {
  //         spare = i;
  //     }
  // }
  if (rings[ringIndex + 1]) {
      if (rings[ringIndex + 1] != spare) {
          moveRing(rings, (ringIndex + 1), spare);
      }
  }
  rings[ringIndex] = target;
  // cout << "Moved ring " << ringIndex << " from " << home << " to " << target << "." << endl;
  if (rings[ringIndex + 1]) {
      moveRing(rings, (ringIndex + 1), target);
  }
}
