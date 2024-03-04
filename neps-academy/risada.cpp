// https://neps.academy/br/exercise/118
#include <iostream>
using namespace std;

int main() {
    bool vowels[(int)'z'+1] = { false };
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    string s;
    cin >> s;

    string x = "";

    // an alternative is using copy_if from <algorithms> library
    for (char c: s) {
        if (vowels[c])
            x += c;
    }

    int n = x.length();
    for (int i = 0; i < n/2; i++) {
        if (x[i] != x[n-i-1]) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}
