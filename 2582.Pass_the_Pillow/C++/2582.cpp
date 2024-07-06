int passThePillow(int n, int time) {
    int direction = 1;
    int idx = 0;

    for (int i = 0; i < time; ++i) {
        idx += direction;
        if (idx == n - 1) {
            direction = -1;
        }
        else if (idx == 0) {
            direction = 1;
        }
    }

    return (idx + 1);
}