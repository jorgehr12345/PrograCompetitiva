#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
#define fore(i, a, b) for (ll i = a, to = b; i < to; i++)
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POll(x) ((x) * (x))
#define SZ(v) (ll) v.size()
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

vector<ll> get_pr(ll x) { // O(sqrt(n))
    vector<ll> pr;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) pr.pb(i);
        while (x % i == 0) x /= i;
    }
    if (x > 1) pr.pb(x);
    return pr;
}

ll InclusionExclusion(vector<ll> &v, ll m) { // O((2^cantidad de primos)*cantidad de primos)
    ll n = v.size();
    ll ans = m;
    for (ll i = 1; i < (1 << n); ++i) {
        ll prod = 1LL;
        for (ll j = 0; j < n; ++j) {
            if (i >> j & 1) {
                if (v[j] <= m / prod) prod *= v[j]; // overflow by mult
                else prod = m + 1;
            }
        }
        if (__builtin_popcount(i) & 1) ans -= m / prod;
        else ans += m / prod;
    }
    return ans;
}

ll mult_mod(ll a, ll b, ll c) {
    return (((a % c) * (b % c)) % c);
}

int main() {
    inic;
    inic2;
    return 0;
}