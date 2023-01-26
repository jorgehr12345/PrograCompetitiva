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
    return ((a % c) - (b % c) + c) % c;
}
ll sum_mod(ll a, ll b, ll c) {
    return (a % c + b % c) % c;
}
ll pot_mod(ll a, ll b, ll c) {
    if (b == 0) {
        return 1 % c;
    }
    int temp = pot_mod(a, b / 2, c);
    temp = (temp * temp) % c;
    if (b % 2 == 0) return temp;
    return (temp * (a % c)) % c;
}
ll mult_mod(ll a, ll b, ll c) {
    return (((a % c) * (b % c)) % c);
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
    cout << interpolate(6, X, Y) << endl;
    return 0;
}
// PONER MAS VALORES DE LOS NECESARIOS (UNOS 3 MÁS)
//  5
//  1 3
//  2 5
//  3 9
//  4 14
//  5 16