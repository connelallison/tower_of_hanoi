#include <iostream>

using  namespace std;

int main()
{
    int heightInput;
    cout << "Please enter the number of rings in your Tower of Hanoi puzzle." << endl;
    cin >> heightInput;
//    heightInput = 3;
    cout << heightInput << endl;
    int moves = 0;
    int rings[heightInput + 1];
    for (int i = 0; i < heightInput; i++) {
        rings[i] = 1;
    }
    rings[heightInput] = 0;
    function<void(int,int)> moveRing = [&moves, &rings, &moveRing] (int ringIndex, int target) mutable {
        int home = rings[ringIndex];
        int spare = 0;
        for (int i = 1; i < 4; i++) {
            if (i != target && i != home) {
                spare = i;
            }
        }
        if (rings[ringIndex + 1] != 0) {
            if (rings[ringIndex + 1] != spare) {
                moveRing((ringIndex + 1), spare);
            }
        }
        rings[ringIndex] = target;
        cout << "Moved ring " << ringIndex << " from " << home << " to " << target << "." << endl;
        moves++;
        if (rings[ringIndex + 1]) {
            moveRing((ringIndex + 1), target);
        }
    };
    for (int i = 0; i < heightInput; i++) {
        cout << rings[i] << " ";
    }
    cout << endl;
    moveRing(0, 3);
    for (int i = 0; i < heightInput; i++) {
        cout << rings[i] << " ";
    }
    cout << endl;
    cout << "Moves: " << moves << endl;

    return 0;
}
