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
// const ll MX = 1e3 + 2;
const ll MX = 2e6 + 2; // MX = MX_VAL^(1/3)
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
void linea() {
    cout << "---------------" << endl;
}

// Works for numbers < 2^63 and a, b < M
ull mult(ull a, ull b, ull M) {
    // a %= M
    // b %= M
    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

/*Long mult(__int128 a, __int128 b, Long mod) {
    //Use fastMult or 128-bit integer
    return (a * b) % mod;
}*/

ll fastPow(ll a, ll b, ll mod) { // O(log b)
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = mult(ans, a, mod);
        a = mult(a, a, mod);
        b >>= 1;
    }
    return ans;
}

bool checkComposite(ll a, ll d, ll s, ll n) {
    // O(log n) with 128 bit
    // O(log^2 n) with divide and conquer mult
    ll x = fastPow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int i = 1; i < s; i++) {
        x = mult(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

bool isPrime(ll n) { // DE MILLER-RABIN
    // O(log n * |base|) with 128-bit
    // O(log^2 n * |base|) with divide and conquer
    if (n <= 1) return false;
    ll d = n - 1;
    ll s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    // 64-bit integer
    vector<ll> base = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    // 2 3 5 7 for 32-bit integer
    for (ll a : base) {
        if (a >= n) break;
        if (checkComposite(a, d, s, n)) {
            return false;
        }
    }
    return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(rng);
}

const ll BUCKET = 40;

ll getFactor(ll n) {
    if (isPrime(n)) return n;
    auto f = [n](ll x) { return mult(x, x, n) + 1; };
    // x = 0 will also work
    ll x = random(0, n - 1), y = x;
    ll t = 0, i = 1;
    ll product = 2;
    while (true) {
        t++;
        if (x == y) x = ++i, y = f(x);
        ll cum = mult(abs(y - x), product, n);
        if (cum != 0) product = cum;
        x = f(x);
        y = f(f(y));
        if (t == BUCKET) {
            t = 0;
            ll ans = __gcd(product, n);
            if (ans != 1) {
                return getFactor(ans);
            }
        }
    }
}

vector<pair<ll, ll>> factorize(ll n) {
    if (n == 1) return {};
    vector<pair<ll, ll>> factors;
    while (n > 1) {
        ll f = getFactor(n);
        ll e = 0;
        while (n % f == 0) {
            n /= f;
            e++;
        }
        factors.push_back({f, e});
    }
    // sort(factors.begin(), factors.end());
    return factors;
}

int main() {
    inic;
    inic2;
    // criba(MX - 1);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vpa;
    while (n--) {
        ll d;
        cin >> d;
        if (isPrime(d) == true) {
            cout << "Es primo" << endl;
        }
        vpa = factorize(d);
        for (ll i = 0; i < vpa.size(); i++) {
            cout << vpa[i].first << " " << vpa[i].second << endl;
        }
    }
    return 0;
}