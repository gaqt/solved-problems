/*
 * https://codeforces.com/problemset/problem/1092/F
 *
 * sum(v) = sum of weights of subtree of v including v
 * sum(v) = av + a0 + a1 + ... + ak
 * cost(v) = sum of costs of subtree of v including v
 * cost(v) = d0a0 + d1a1 + ... + dkak
 * cost(parent(v)) = av + (d0+1)a0 + (d0+1)a1 + ... + (dk+1)ak =
 * a_parent(v) + (d0a0 + d1a1 + ... + dkak) + av + a0 + a1 + ... + ak =
 * cost(parent(v)) = cost(v) + sum(v) if parent has only one child v
 * cost(v) = cost(child0(v)) + sum(child0(v)) + cost(child1(v)) + sum(child1(v)) + ...
 * 
 * rsum(v) = sum of weights of reverse subtree of v including v
 * rcost(v) = sum of costs of reverse subtree of v including v
 * 
 * rsum(v) = rsum(parent(v) + sum(parent(v)) - a_parent(v) - sum(v)
 * rcost(v) = rcost(parent(v)) + rsum(parent(v)) + cost(parent(v)) + sum(parent(v)) - a_parent(v) - cost(v) - 2*sum(v)
 *
 * ans(v) = cost(v) + rcost(v)
 *
 * final complexity -> O(N)
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 212345

typedef long long ll;

vector<int> adj[MAXN];
int parent[MAXN];
ll a[MAXN];
ll sum[MAXN];
ll rsum[MAXN];
ll cost[MAXN];
ll rcost[MAXN];

ll get_sum(int x) {
  if (sum[x] != -1) return sum[x];
  ll result = a[x];

  for (int u: adj[x]) result += get_sum(u);

  sum[x] = result;
  return result;
}

ll get_rsum(int x) {
  if (rsum[x] != -1) return rsum[x];
  if (x == 1) {
    rsum[x] = a[x];
    return rsum[x];
  }
  rsum[x] = get_sum(parent[x]) + get_rsum(parent[x]) - a[parent[x]] - get_sum(x) + a[x];
  return rsum[x];
}

ll get_cost(int x) {
  if (cost[x] != -1) return cost[x];
  ll result = 0;

  for (int u: adj[x]) result += get_sum(u) + get_cost(u);
  cost[x] = result;
  return result;
}

ll get_rcost(int x) {
  if (rcost[x] != -1) return rcost[x];
  if (x == 1) {
    rcost[x] = 0;
    return 0;
  }
  rcost[x] = get_rcost(parent[x]) + get_cost(parent[x]) + get_rsum(parent[x]) + get_sum(parent[x]) - a[parent[x]] - get_cost(x) - 2*get_sum(x);
  return rcost[x];
}

ll solve(int x) {
  return get_cost(x) + get_rcost(x);
}

void root_tree(int x, int prev) {
  int pos = -1;
  for (int i = 0; i < adj[x].size(); i++) if (adj[x][i] == prev) pos = i;
  if (pos != -1) adj[x].erase(adj[x].begin()+pos);
  //O(N) but we dont care because sum of all adj[x] = N-1 so it averages out as O(1) for all N vertices

  parent[x] = prev;

  for (int u: adj[x]) root_tree(u, x);
}


int main() {

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    parent[i] = -1;
    sum[i] = -1;
    rsum[i] = -1;
    cost[i] = -1;
    rcost[i] = -1;
  }

  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  root_tree(1,0);

  ll max_cost = 0;

  for (int i = 1; i <= n; i++) {
    max_cost = max(max_cost, solve(i));
  }

  cout << max_cost << endl;

  return 0;
}

