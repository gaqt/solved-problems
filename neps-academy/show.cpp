// https://neps.academy/br/exercise/2069
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int a, n, m;
    cin >> a >> n >> m;

    int res = INT_MAX;

    for (int i = n; i > 0; i--) {
        int seq = 0;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;

            switch (x) {
                case 0:
                    seq++;
                    break;
                case 1:
                    seq = 0;
            }

            if (seq >= a) {
                res = min(res, i);
            }
        }
    }

    if (res == INT_MAX)
        res = -1;

    cout << res << endl;

    return 0;
}
