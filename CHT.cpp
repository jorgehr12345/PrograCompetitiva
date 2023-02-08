#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

struct lineaY {
    mutable ll m, b, r = 0;
    // m: pendiente
    // b: constante
    // r: coordenada x de envolvente
    bool operator<(const lineaY &other) const {
        return m < other.m;
    }
    bool operator<(const ll &x) const {
        return r < x;
    }
    ll getY(ll x) {
        return m * x + b;
    }
};

struct CHT {
    set<lineaY, less<>> envelope;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    ll intersect(lineaY l1, lineaY l2) {
        return div(l1.b - l2.b, l2.m - l1.m);
    }
    bool bad(lineaY l1, lineaY l2, lineaY l3) {
        return intersect(l2, l3) <= intersect(l1, l2);
    }
    void addLine(lineaY L) {
        L.r = INF;
        auto it = envelope.lower_bound(L);
        if (it != envelope.end() && (*it).m == L.m) {
            if ((*it).b >= L.b) {
                return;
            } else {
                it = envelope.erase(it);
            }
        }
        if (it != envelope.begin()) {
            if (it != envelope.end() && bad(*prev(it), L, *it)) {
                return;
            }
            it--;
            while (it != envelope.begin()) {
                if (bad(*prev(it), *it, L)) {
                    it = envelope.erase(it);
                    it--;
                } else break;
            }
            it->r = intersect(*it, L);
        }
        it = envelope.upper_bound(L);
        if (it != envelope.end()) {
            while (next(it) != envelope.end()) {
                if (bad(L, *it, *next(it))) it = envelope.erase(it);
                else break;
            }
            L.r = intersect(L, *it);
        }
        envelope.insert(L);
    }

    ll yOptimo(ll x) { // Maximo valor de las rectas
        assert(!envelope.size() == 0);
        lineaY resp = *envelope.lower_bound(x);
        return resp.getY(x);
    }
} conv;

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    lineaY nuevo;
    Rep1(i, n) {
        ll pendiente, constante;
        cin >> pendiente >> constante;
        nuevo.m = pendiente;
        nuevo.b = constante;
        conv.addLine(nuevo);
    }
    cout << conv.yOptimo(5) << endl;
    return 0;
}