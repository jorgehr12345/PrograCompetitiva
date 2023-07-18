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

ll combineMin(ll a, ll b) {
    // return a + b;
    return min(a, b);
}

struct SegmentTreeMin {
    ll t[2 * MX];
    ll lazy[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 0; i <= 2 * n; i++) {
            t[i] = INF;
            lazy[i] = INF;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl - 1];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combineMin(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    void push(ll id, ll tl, ll tr) { // O(1)
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        ll szLeft = tm - tl + 1;
        ll szRight = tr - tm;
        if (lazy[id] != 0) {
            t[left] = lazy[id];
            t[right] = lazy[id];
            lazy[left] = lazy[id];
            lazy[right] = lazy[id];
        }
        lazy[id] = 0;
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) {
            // cout << " qqq " << endl;
            return INF;
        }
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        push(id, tl, tr);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combineMin(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll l, ll r, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            ll sz = tr - tl + 1;
            t[id] = val;
            lazy[id] = val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combineMin(t[left], t[right]);
        }
    }

    void update(ll l, ll r, ll val) {
        assert(n > 0);
        update(l, r, val, 1, 1, n);
    }
} minis;

ll combineMax(ll a, ll b) {
    // return a + b;
    return max(a, b);
}

struct SegmentTreeMax {
    ll t[2 * MX];
    ll lazy[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 0; i <= 2 * n; i++) {
            t[i] = 0;
            lazy[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl - 1];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combineMax(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    void push(ll id, ll tl, ll tr) { // O(1)
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        ll szLeft = tm - tl + 1;
        ll szRight = tr - tm;
        if (lazy[id] != 0) {
            t[left] = lazy[id];
            t[right] = lazy[id];
            lazy[left] = lazy[id];
            lazy[right] = lazy[id];
        }
        lazy[id] = 0;
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) {
            // cout << " qqq " << endl;
            return 0;
        }
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        push(id, tl, tr);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combineMax(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll l, ll r, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) {
            // cout << " qqq " << endl;
            return;
        }
        if (l <= tl && tr <= r) {
            ll sz = tr - tl + 1;
            t[id] = val;
            lazy[id] = val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combineMax(t[left], t[right]);
        }
    }

    void update(ll l, ll r, ll val) {
        assert(n > 0);
        update(l, r, val, 1, 1, n);
    }
} maxis;

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    vector<ll> vec;
    while (n--) {
        ll l;
        cin >> l;
        vec.pb(l);
    }
    minis.build(vec);
    ll m;
    cin >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        cout << minis.query(a, b) << endl;
        ll c;
        cin >> a >> b >> c;
        minis.update(a, b, c);
        cout << minis.query(a, b) << endl;
    }
    return 0;
}

// 5
// 10 20 30 40 50
// 2
// 1 2
// 1 2 5
// 1 1
// 1 1 3