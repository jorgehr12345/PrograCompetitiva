#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
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

// Cantidad de valores mayores o iguales a x en un arreglo desordenado
ll operador(ll x, ll y) {
    // return max(x, y);
    return x + y;
}

struct SegmentTree {
    ll t[2 * MX];
    vector<ll> segs[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 1; i <= 2 * n; i++) {
            t[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            t[id] = a[tl - 1];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
        for (ll i = tl; i <= tr; i++) {
            segs[id].pb(a[i - 1]);
        }
        sort(segs[id].begin(), segs[id].end());
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr, ll valor) { // O(logn)
        if (l <= tl && tr <= r) {
            ll cantidad =
                segs[id].end() - upper_bound(segs[id].begin(), segs[id].end(), valor);
            // cout << "VALOR " << *lower_bound(segs[id].begin(), segs[id].end(), valor) <<
            // endl; cout << "cantidad parcial: " << cantidad << " izq " << tl << " der " << tr
            // << endl;
            return cantidad;
        }
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm, valor);
        else if (tm < l) return query(l, r, right, tm + 1, tr, valor);
        else
            return operador(query(l, r, left, tl, tm, valor),
                            query(l, r, right, tm + 1, tr, valor));
    }

    ll query(ll l, ll r, ll valor) {
        assert(n > 0);
        return query(l, r, 1, 1, n, valor);
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            t[id] = val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update(pos, val, left, tl, tm);
            else update(pos, val, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void update(ll pos, ll val) {
        assert(n > 0);
        update(pos, val, 1, 1, n);
    }
} st;

int main() {
    inic;
    inic2;

    ll n, m;
    cin >> n >> m;
    vector<ll> vec;
    Rep1(i, n) {
        ll l;
        cin >> l;
        vec.pb(l);
    }
    st.build(vec);
    while (m--) {
        ll l, r, x;
        cin >> l >> r >> x;
        cout << st.query(l, r, x) << " asdasdas " << endl;
    }
    return 0;
}

// 6 1
// 20 30 30 10 40 30
// 1 6 30