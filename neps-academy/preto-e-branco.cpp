// https://neps.academy/br/exercise/1105
#include <iostream>
using namespace std;

#define MAXL 8

int board[MAXL][MAXL];
int Y, X;

bool side_of_has(int y, int x, int k) {
    return board[y-1][x] == k ||
           board[y+1][x] == k ||
           board[y][x-1] == k ||
           board[y][x+1] == k;
}

int find_max(int y, int x) {
    bool take = true;
    if (board[y][x] != 0) take = false;
    if (!side_of_has(y,x, 1)) take = false;
    if (side_of_has(y,x, 2)) take = false;

    int next_y = y, next_x = x+1;
    if (next_x > X) {
        next_x = 1;
        if (++next_y > Y)
            return 1*take;
    }

    int res = find_max(next_y, next_x);
    if (take) {
        board[y][x] = 2;
        res = max(res, 1+find_max(next_y, next_x));
        board[y][x] = 0;
    }

    return res;
}

int solve() {
    return find_max(1, 1);
}

int main() {
    int p;
    cin >> X >> Y >> p;

    while(p--) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }

    cout << solve() << endl;

    return 0;
}
