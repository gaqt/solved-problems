// https://codeforces.com/problemset/problem/2/A

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {

    int n;
    cin >> n;

    pair<string, int> rounds[n];
    map<string, int> score;

    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        rounds[i] = make_pair(s, p);
        if (score.find(s) == score.end()) {
            score.insert(make_pair(s, 0));
        }
        score[s] += p;
    }

    set<string> finalists;
    int m = 0;

    for (auto &ps: score) {
        if (ps.second > m) {
            finalists.clear();
            finalists.insert(ps.first);
            m = ps.second;
        } else if (ps.second == m) {
            finalists.insert(ps.first);
        }

        ps.second = 0;
    }

    if (finalists.size() == 1) {
        cout << *finalists.begin() << endl;
        return 0;
    }

    string winner;

    for (int i = 0; i < n; i++) {
        string s = rounds[i].first;
        int p = rounds[i].second;

        if (finalists.find(s) == finalists.end()) {
            continue;
        }

        score[s] += p;

        if (score[s] >= m) {
            winner = s;
            break;
        }
    }

    cout << winner << endl;

    return 0;
}
