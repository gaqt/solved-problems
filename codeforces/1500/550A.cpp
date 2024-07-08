// https://codeforces.com/problemset/problem/550/A

#include <iostream>
#include <string>
using namespace std;

int find_substr(string s, int x, string target) {
    int y = 0;
    for (; x < s.length(); x++) {
        if (target[y] == s[x]) {
            y++;
            if (y == 2) {
                return x+1;
            }
        } else {
            if (target[0] == s[x]) y = 1;
            else y = 0;
        }
    }

    return -1;
}

int main() {
    string s;
    cin >> s;

    int x;
    x = find_substr(s, 0, "AB");
    if (x != -1) {
        x = find_substr(s, x, "BA");
        if (x != -1) {
            cout << "YES" << endl;
            return 0;
        }
    }

    x = find_substr(s, 0, "BA");
    if (x != -1) {
        x = find_substr(s, x, "AB");
        if (x != -1) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
