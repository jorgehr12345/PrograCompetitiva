#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 10, MX2 = 1e9 + 2;
bool bo[MX];
pair<ll, ll> pa;
deque<ll> deq, deq2, deq3;
deque<pair<ll, ll>> dpa, dpa2, dpa3;
deque<pair<pair<ll, ll>, ll>> dpapa, dpapa2, dpapa3;
vector<ll> vec, vec2, vec3;
vector<ll> vec4, vec5, vec6;
vector<pair<ll, ll>> vpa, vpa2, vpa3, vpas[MX];
vector<pair<pair<ll, ll>, ll>> vpapa, vpapa2, vpapa3;
set<ll> se, se2, se3, se4;
set<pair<ll, ll>> sepa, sepa2, sepa3;
set<pair<pair<ll, ll>, ll>> sepapa, sepapa2, sepapa3;
map<ll, ll> ma, ma2, ma3, ma4;
map<pair<ll, ll>, ll> mapa, mapa2, mapa3;
map<pair<ll, ll>, pair<ll, ll>> mapapa, mapapa2, mapapa3;
map<ll, pair<ll, ll>> malpa, malpa2, malpa3;
map<ll, pair<pair<ll, ll>, ll>> malpapa, malpapa2, malpapa3;
ll combine(ll x, ll y) {
    // return max(x, y);
    return x + y;
}

struct SegmentTree {
    ll t[2 * MX];
    int n;

    void clear(int n) {
        for (int i = 1; i <= 2 * n; i++) {
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
            t[id] = combine(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        // if (tr < l || tl > r || l>R) return 0; //Dependiendo lo que te pidan
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            t[id] += val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update(pos, val, left, tl, tm);
            else update(pos, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(ll pos, ll val) {
        assert(n > 0);
        update(pos, val, 1, 1, n);
    }
} st;

int main() {
    ll t, k;
    cin >> t;
    ll as = t;
    while (as--) {
        char c;
        cin >> c;
        if (c == 'C') {
            ll p;
            cin >> p;
            ll as2 = p;
            while (p--) {
                ll l;
                cin >> l;
            }
        }
    }

    return 0;
}