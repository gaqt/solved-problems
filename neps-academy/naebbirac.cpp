// https://neps.academy/br/exercise/98
#include <iostream>
using namespace std;

bool is_complete(int occ[], int k) {
    for (int i = 1; i <= k; i++) {
        if (occ[i] != occ[1])
            return false;
    }

    return true;
}

int occ_min(int occ[], int k) {
    int min_idx = 1;
    for (int i = 2; i <= k; i++) {
        if (occ[i] < occ[min_idx])
            min_idx = i;
    }

    return min_idx;
}

int occ_max(int occ[], int k) {
    int max_idx = 1;
    for (int i = 2; i <= k; i++) {
        if (occ[i] > occ[max_idx])
            max_idx = i;
    }

    return max_idx;
}

int main() {
    int k, n;
    cin >> k >> n;

    int occ[k+1];
    for (int i = 0; i <= k; i++)
        occ[i] = 0;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        occ[s]++;
    }

    int min_idx = occ_min(occ, k);
    occ[min_idx]++;
    if (is_complete(occ, k)) {
        printf("+%d\n", min_idx);
        return 0;
    }
    occ[min_idx]--;

    int max_idx = occ_max(occ, k);
    occ[max_idx]--;
    if (is_complete(occ, k)) {
        printf("-%d\n", max_idx);
        return 0;
    }

    occ[min_idx]++;
    if (is_complete(occ, k)) {
        printf("-%d +%d\n", max_idx, min_idx);
        return 0;
    }

    cout << "*" << endl;

    return 0;
}
