#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get_digits(ll x) {
  vector<ll> result;

  for (int i = 0; i < 19 && x != 0; i++) {
    result.push_back(x%10);
    x /= 10;
  }

  return result;
}

int main() {

  priority_queue<ll> q;
  map<ll, ll> b_cnt;

  b_cnt[-1] = -1;

  q.push(0);

  ll u = 10;

  while (!q.empty()) {
    ll x = q.top();
    q.pop();
    x = -x;

    b_cnt[x] = 1;
    b_cnt[x] += (--b_cnt.find(x))->second;

    if (x > u) {
      printf("%lld\n", x);
      u *= 10;
    }

    vector<ll> digits = get_digits(x);
    ll k10 = 1;

    if (digits.size() > 18) continue;

    for (int i = 0; i < digits.size(); i++) k10 *= 10;

    for (ll i = 1; i < 10; i++) {
      bool valid = (x % i == 0);
      for (ll d: digits) {
        if (d == 0) continue;
        if ((i*k10) % d != 0) {
          valid = false;
          break;
        }
      }

      if (valid) {
        q.push(-(x+k10*i));
      }
    }
  }

  int t;
  std::cin >> t;

  while(t--) {
    ll l,r;
    std::cin >> l >> r;

    ll r_idx = (--b_cnt.lower_bound(r))->second;
    ll l_idx = (--(--b_cnt.lower_bound(l)))->second;

    cout << r_idx - l_idx << endl;
  }

  return 0;
}

/*

lets say n is an k+1 digit number that it is beautiful, then
n = d_0 + d_1*10 + ... + d_k*10^k
n = 0 (mod d_i) for 0 <= i <= k

n + d_(k+1)*10^(k+1) is beautiful if:
1. n + d_(k+1)*10^(k+1) = 0 (mod d_i) for 0 <= i <= k
2. n + d_(k+1)*10^(k+1) = 0 (mod d_(k+1))

1. n + d_(k+1)*10^(k+1) = 0 (mod d_i) for 0 <= i <= k
   d_(k+1)*10^(k+1) = 0 (mod d_i) for 0 <= i <= k

2. n + d_(k+1)*10^(k+1) = 0 (mod d_(k+1))
   n = 0 (mod d_(k+1))

in other words, n + d_(k+1)*10^(k+1) is beautiful if:
1. d_(k+1)*10^(k+1) is divisible by all other digits
2. n is divisible by d_(k+1)

all nonzero 1 digit numbers are beautiful

are all numbers covered by this generation method?
suppose m is a beautiful number:
m = d_0 + d_1*10 + ... + d_k*10^k

if we reverse the process,
m - d_k*10^k is also beautiful, because:
d_k*10^k = 0 (mod d_i) for 0 <= i <= k-1
thus, m = 0 (mod d_i) for 0 <= i <= k-1
if we repeat this, we will arrive at d_0, which is either beautiful or zero

solution: generate all beautiful numbers from the numbers 0..9
and store them in a prefix sum hashmap h, then for each l, r, calculate:
r' = closest beautiful number not greater than r
l' = second closest beautiful number not greater than l
 
ans = h[r'] - h[l']

*/