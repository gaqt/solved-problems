// https://neps.academy/br/exercise/110
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int crr;
    cin >> crr;
    int seq = 1;
    int max_seq = 1;

    while(--n) {
        int v;
        cin >> v;

        if (crr == v) {
            seq++;
            max_seq = max(max_seq, seq);
        } else {
            crr = v;
            seq = 1;
        }
    }

    cout << max_seq << endl;

    return 0;
}
