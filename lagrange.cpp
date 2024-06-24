#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define POT(x) ((x) * (x))
const ll MX = 2e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll rest_mod(ll a, ll b, ll c) {
    if (a - b >= 0) return a - b;
    return a - b + c;
}
ll sum_mod(ll a, ll b, ll mod) {
    if (a >= mod) {
        a -= mod;
    }
    if (b >= mod) {
        b -= mod;
    }
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}
ll pot_mod(ll a, ll b, ll c) {
    if (b == 0) {
        return 1 % c;
    }
    ll temp = pot_mod(a, b / 2, c);
    temp = (temp * temp) % c;
    if (b % 2 == 0) return temp;
    return (temp * (a % c)) % c;
}
ll mult_mod(ll a, ll b, ll c) {
    return (((a) * (b)) % c);
}
ll fastPow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1 == 1) ans = mult_mod(ans, a, MOD);
        a = mult_mod(a, a, MOD);
        b >>= 1;
    }
    return ans;
}
ll modInverse(ll a) {
    return fastPow(a, MOD - 2);
}
ll divide(ll a, ll b) {
    return mult_mod(a, modInverse(b), MOD);
}

ll interpolate(ll x, vector<ll> &xSample, vector<ll> &ySample) { // O(n^2)
    ll y = 0;
    for (int i = 0; i < xSample.size(); i++) {
        ll cur = ySample[i];
        ll den = 1;
        for (int j = 0; j < xSample.size(); j++) {
            if (i == j) continue;
            den = mult_mod(den, rest_mod(xSample[i], xSample[j], MOD), MOD);
            cur = mult_mod(cur, rest_mod(x, xSample[j], MOD), MOD);
        }
        cur = divide(cur, den);
        y = sum_mod(y, cur, MOD);
    }
    return y;
}

ll interpolate(ll x, vector<ll> &Y) { // O(n)
    // interpolate for just one value
    // the X vector is not given because it's assumed that you picked x_i = i (0-indexed)
    ll n = Y.size();
    vector<ll> fact(n), factInv(n);
    vector<ll> pref(n), suff(n);
    fact[0] = 1;
    pref[0] = 1;
    for (ll i = 1; i < n; i++) {
        fact[i] = mult_mod(fact[i - 1], i, MOD);
        pref[i] = mult_mod(pref[i - 1], rest_mod(x, rest_mod(i, 1, MOD), MOD), MOD);
    }
    factInv[n - 1] = modInverse(fact[n - 1]);
    suff[n - 1] = 1;
    for (ll i = n - 2; i >= 0; i--) {
        factInv[i] = mult_mod(factInv[i + 1], (i + 1), MOD);
        suff[i] = mult_mod(suff[i + 1], rest_mod(x, sum_mod(i, 1, MOD), MOD), MOD);
    }

    ll y = 0;
    for (ll i = 0; i < n; i++) {
        ll sgn = 1;
        if (i % 2 == n % 2) sgn = MOD - 1;
        y = sum_mod(y,
                    mult_mod(factInv[n - i - 1],
                             mult_mod(sgn,
                                      mult_mod(mult_mod(Y[i], pref[i], MOD),
                                               mult_mod(suff[i], factInv[i], MOD), MOD),
                                      MOD),
                             MOD),
                    MOD);
    }
    return y;
}

int main() {
    inic;
    inic2;
    ll puntos;
    cin >> puntos;
    vector<ll> X, Y;
    while (puntos--) {
        ll x, y;
        cin >> x >> y;
        X.pb(x);
        Y.pb(y);
    }
    cout << interpolate(6, X, Y) << endl; // O(len(Y)*len(Y))
    cout << interpolate(6, Y) << endl;    // O(len(Y))
    return 0;
}
// PONER MAS VALORES DE LOS NECESARIOS (UNOS 3 MÁS)
//  5
//  1 3
//  2 5
//  3 9
//  4 14
//  5 16