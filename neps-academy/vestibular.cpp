// https://neps.academy/br/exercise/160
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
