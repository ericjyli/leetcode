#include <iostream>


bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int x_move = abs(fx - sx);
    int y_move = abs(fy - sy);

    if (x_move > t || y_move > t) {
        return false;
    }

    if (x_move == 0 && y_move == 0) {
        return t != 1;
    }

    return true;
}

