// https://neps.academy/br/exercise/258
#include <climits>
#include <iostream>
using namespace std;

#define MAXN 112

bool verified[MAXN][MAXN];
int values[MAXN][MAXN] = { INT_MAX };

int solve(int y, int x) {
    verified[y][x] = true;

    int res = 1;

    if (values[y][x+1] >= values[y][x] && !verified[y][x+1])
        res += solve(y, x+1);
    if (values[y+1][x] >= values[y][x] && !verified[y+1][x])
        res += solve(y+1, x);
    if (values[y][x-1] >= values[y][x] && !verified[y][x-1])
        res += solve(y, x-1);
    if (values[y-1][x] >= values[y][x] && !verified[y-1][x])
        res += solve(y-1, x);

    return res;
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++)
            cin >> values[y][x];
    }

    cout << solve(i, j) << endl;

    return 0;
}
