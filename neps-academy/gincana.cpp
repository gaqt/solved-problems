// https://neps.academy/br/exercise/309
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1123

bool verified[MAXN];
vector<int> friends[MAXN];

void fill_component(int x) {
    verified[x] = true;

    for (int y: friends[x]) {
        if (verified[y]) continue;
        fill_component(y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int i, j;
        cin >> i >> j;
        friends[i].push_back(j);
        friends[j].push_back(i);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (verified[i]) continue;

        ans++;
        fill_component(i);
    }

    cout << ans << endl;

    return 0;
}
