//https://codeforces.com/problemset/problem/1363/E

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct vertex {
  vector<int> u;
  ll a, b, c;
};

const int MAXN = 213245;
int n;

vertex graph[MAXN];
ll min_cost[MAXN];
int digit_credit[MAXN]; //number of 1s extra in subtree

void build_min_cost(int x, int prev, ll prev_min) {
  min_cost[x] = min(graph[x].a, prev_min);

  for (int u: graph[x].u) {
    if (u == prev) continue;
    build_min_cost(u, x, min_cost[x]);
  }
}

ll ans = 0;
int solve(int x, int prev) {
  digit_credit[x] = 0;

  for (int u: graph[x].u) {
    if (u == prev) continue;
    int net = solve(u, x);
    if (digit_credit[x] > 0 && net < 0) {
      ans += 2ll*min_cost[x]*(ll)min(-net, digit_credit[x]);
    } else if (digit_credit[x] < 0 && net > 0) {
      ans += 2ll*min_cost[x]*(ll)min(net, -digit_credit[x]);
    }
    digit_credit[x] += net;
  }

  int crr = graph[x].b - graph[x].c;

  if (digit_credit[x] > 0 && crr < 0) {
    ans += 2ll*min_cost[x]*(ll)min(-crr, digit_credit[x]);
  } else if (digit_credit[x] < 0 && crr > 0) {
    ans += 2ll*min_cost[x]*(ll)min(crr, -digit_credit[x]);
  }
  digit_credit[x] += crr;

  if (digit_credit[x] != 0 && x == 1) ans = -1;

  return digit_credit[x];
}

int main() {
  cin >> n;

  for (int i = 0; i <= n; i++) min_cost[i] = LONG_LONG_MAX;

  for (int i = 1; i <= n; i++) {
    cin >> graph[i].a >> graph[i].b >> graph[i].c;
  }

  for (int i = 0; i < n-1; i++) {
    int x,y;
    cin >> x >> y;
    graph[x].u.push_back(y);
    graph[y].u.push_back(x);
  }

  build_min_cost(1, 0, LONG_LONG_MAX);
  solve(1, 0);

  cout << ans << endl;

  return 0;
}