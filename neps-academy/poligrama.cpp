// https://neps.academy/br/exercise/1726
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int len = 1; len <= n/2; len++) {
        if (n%len != 0) continue;

        long root_hash = 0;
        for (int i = 0; i < len; i++)
            root_hash += 1<<(s[i]-'a');

        bool valid = true;
        for (int start = len; start < n; start += len) {
            long crr_hash = 0;
            for (int i = start; i < start+len; i++)
                crr_hash += 1<<(s[i]-'a');

            if (crr_hash != root_hash) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << s.substr(0, len) << endl;
            return 0;
        }
    }

    cout << "*" << endl;
    return 0;
}
