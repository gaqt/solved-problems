// https://olimpiada.ic.unicamp.br/pratique/p2/2018/f2/wifi/

#include <iostream>
#include <map>
using namespace std;

struct event {
    int x;
    int ytop;
    int ybot;
    bool is_open;
};

bool cmp(event a, event b) { return a.x <= b.x; }

int main() {
    int n;
    cin >> n;

    event events[2 * n];

    for (int i = 1; i < 2 * n; i += 2) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        events[i] = {x1, max(y1, y2), min(y1, y2), true};
        events[i - 1] = {x2, max(y1, y2), min(y1, y2), false};
    }

    sort(events, events + (2 * n), cmp);

    map<int, bool> is_empty;
    int ans = 0;

    for (event crr : events) {
        if (crr.is_open) {
            is_empty[crr.ytop] = true;  // set value is arbitrary
            is_empty[crr.ybot] = true;
        } else {
            if (is_empty[crr.ybot]) ans++;

            auto it = is_empty.find(crr.ybot);
            if (it == is_empty.begin()) continue;

            it--;
            it->second = false;

            is_empty.erase(crr.ybot);
            is_empty.erase(crr.ytop);
        }
    }

    cout << ans << endl;

    return 0;
}
