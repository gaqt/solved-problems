// https://codeforces.com/problemset/problem/1526/C1

//parts of this template come from this
//https://iq.opengenus.org/cpp-template-for-competitive-coding/

#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
using namespace std;

#pragma GCC optimize("O3")

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;
typedef pair<pii,pii> piiii;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pddd;
typedef pair<pdd,pdd> pdddd;

#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define ins insert
#define bg begin
#define all(a) (a).begin(), (a).end()
#define sz(a) ((a).size())

#define INF INT_MAX
#define PI 3.1415926535897932384626433832795l
#define MOD 1000000007ll
#define MAX2 112
#define MAX3 1123
#define MAX4 11234
#define MAX5 112345
#define MAX6 1123456
#define MAX7 11234567
#define MAX8 112345678
#define MAX9 1123456789
#define FORI(n) for(int i = 0; i < (n); i++)
#define FORI1(n) for(int i = 1; i < (n); i++)
#define FORJ(n) for(int j = 0; j < (n); j++)
#define FORJ1(n) for(int j = 1; j < (n); j++)
#define FORH(n) for(int h = 0; h < (n); h++)
#define FORH1(n) for(int h = 1; h < (n); h++)
#define FORK(n) for(int k = 0; k < (n); k++)
#define FORK1(n) for(int k = 1; k < (n); k++)
#define FORZ(n) for(int z = 0; z < (n); z++)
#define FORZ1(n) for(int z = 1; z < (n); z++)
#define FOR0(k,n) for(int k = 0; k < (n); k++)
#define FOR1(k,n) for(int k = 1; k < (n); k++)

#define BIT_INV(a) (a^1)
#define BIT_FLIP(a,b) ((a)^=(1ull)<<(b))
#define BIT_SET(a,b) ((a)|=(1ull)<<(b))
#define BIT_CLEAR(a,b) ((a)&=~(1ull)<<(b))
#define BIT_CHECK(a,b) (!!((a) & (1ull<<(b))))

ld distE(pdd a, pdd b) {
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

ld distM(pdd a, pdd b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}

ll distE(pii a, pii b) {
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

ll distM(pii a, pii b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}

void extended_gcd(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return;
    }

    ll x_, y_;
    extended_gcd(b%a, a, &x_, &y_);
    *x = y_ - x_*(b/a);
    *y = x_;
}

ll mod_inv(ll a, ll m) {
	ll x, y;
    extended_gcd(a, m, &x, &y);

    x = (1 - y*m) / a;
    if (x < 0) {
        return x + m*(1+ abs(x)/m);
    } else {
        return x % m;
    }
}

struct scmp {
	bool operator() (const int& a, const int& b) const {
		return a < b;
	}
};

template<typename T>
class segtree {
	int size;
	T (*merge) (T& a, T& b);
	T* tree;
	T placeholder;

	static T default_merge(T& a, T& b) {
		return a + b;
	}

	void build() {
		for (int i = size-1; i > 0; i--)
			tree[i] = merge(tree[i<<1], tree[i<<1|1]);
	}

	public:

	segtree(int nsize, T nplaceholder) {
		size = nsize;
		merge = default_merge;
		placeholder = nplaceholder;
		tree = new T[2*size];
		for (int i = 0; i < 2*size; i++) tree[i] = placeholder;
		build();
	}

	segtree(int nsize, T nplaceholder, T* from_arr) {
		size = nsize;
		merge = default_merge;
		placeholder = nplaceholder;
		tree = new T[2*size];
		for (int i = 0; i < size; i++) {
			tree[size+i] = from_arr[i];
		}
		build();
	}

	segtree(int nsize, T nplaceholder, T (*nmerge) (T a, T b)) {
		size = nsize;
		merge = nmerge;
		placeholder = nplaceholder;
		tree = new T[2*size];
		for (int i = 0; i < 2*size; i++) tree[i] = placeholder;
		build();
	}

	segtree(int nsize, T nplaceholder, T* from_arr, T (*nmerge) (T a, T b)) {
		size = nsize;
		merge = nmerge;
		placeholder = nplaceholder;
		tree = new T[2*size];
		for (int i = 0; i < size; i++) {
			tree[size+i] = from_arr[i];
		}
		build();
	}

	void update(int idx, const T& value) {
		for (tree[idx += size] = value; idx >>= 1; )
			tree[idx] = merge(tree[idx<<1], tree[idx<<1|1]);
	}

	//queries [l,r)
	T query(int l, int r) {
		T resl = placeholder, resr = placeholder;
		for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = merge(resl, tree[l++]);
			if (r&1) resr = merge(tree[--r], resr);
		}
		return merge(resl, resr);
	}

	T* get_tree() {
		return tree;
	}

	~segtree() {
		delete[] tree;
	}
};







//ACTUAL SOLUTION GOES HERE
//----------------------------------------------------------------------------------


inline void _preprocess_() {

}



inline void _solve_() {
    ll n;
    cin >> n;

    ll h[n+1], tot=0, p[n+1];
    h[0] = 0;
    vector<pair<ll,ll> > neg;

    FORI1(n+1) {
        cin >> p[i];
        if (p[i] >= 0) {
            h[i] = h[i-1] + p[i];
            tot++;
        } else {
            h[i] = h[i-1];
            neg.pb(make_pair(-p[i], i));
        }
    }

    sort(all(neg));

    for (auto p: neg) {
        bool valid = true;
        for (int i = p.y; i <= n; i++) {
            if (h[i] - p.x < 0) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        tot++;
        for (int i = p.y; i <= n; i++) {
            h[i] -= p.x;
        }
    }

    cout << tot << endl;
}



// #define USE_TEST_CASES

int main() {
	_preprocess_();

	#ifdef USE_TEST_CASES
		int test_cases;

		scanf("%d", &test_cases);

		while (test_cases--) {
			_solve_();
		}
	#else
		_solve_();
	#endif

	return 0;
}
