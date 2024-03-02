// https://neps.academy/br/exercise/206
#include <iostream>
using namespace std;

int _find_intersect_layer(int crr, int a, int b) {
    if (a == b) return crr-1;
    return _find_intersect_layer(crr+1, a/2, b/2);
}

int find_interesct_layer(int a, int b) {
    return _find_intersect_layer(0, a, b);
}

int main() {
    int n = 16;
    string layer_name[] = {"oitavas", "quartas", "semifinal", "final"};

    int kung_idx, lu_idx;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if (c == 1)
            kung_idx = i;
        else if (c == 9)
            lu_idx = i;
    }

    int layer = find_interesct_layer(kung_idx, lu_idx);
    cout << layer_name[layer] << endl;

    return 0;
}
