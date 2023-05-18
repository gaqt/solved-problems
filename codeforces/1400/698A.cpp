#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N;
    cin >> N;
    
    bool gym[N];
    bool contest[N];
    int workDays = 0;
    bool gymLast = false, contestLast = false;
    
    for (int i = 0; i < N; i++) {
        int aux;
        cin >> aux;
        if (aux == 0) {
            gym[i] = false;
            contest[i] = false;
        } else if (aux == 1) {
            gym[i] = false;
            contest[i] = true;
        } else if (aux == 2) {
            gym[i] = true;
            contest[i] = false;
        } else if (aux == 3) {
            gym[i] = true;
            contest[i] = true;
        }
    }
    
    
    
    for (int i = 0; i < N; i++) {
        if (gym[i] && contest[i]) {
            workDays++;
    
            if (gymLast) {
                gymLast = false;
                contestLast = true;
            } else if (contestLast) {
                gymLast = true;
                contestLast = false;
            }
    
            continue;
        }
    
        if (gym[i] && !gymLast) {
            gymLast = true;
            workDays++;
        } else if (gymLast) {
            gymLast = false;
        }
    
        if (contest[i] && !contestLast) {
            contestLast = true;
            workDays++;
        } else if (contestLast) {
            contestLast = false;
        }
    
    }
    
    cout << N - workDays;
}