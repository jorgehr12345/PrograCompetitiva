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
const ll MX = 1e5 + 2, MX2 = 8e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

struct Node {
    ll sum;
    Node *left;
    Node *right;
    Node(ll sum = 0, Node *left = nullptr, Node *right = nullptr)
        : sum(sum), left(left), right(right) {}
};

ll combine2(ll a, ll b) {
    return a + b;
}

struct SegmentTree {
    vector<Node *> roots; // O(n + Q log n)
    ll n;

    ll combine(ll x, ll y) {
        return x + y;
    }

    Node *combine(Node *left, Node *right) {
        return new Node(combine(left->sum, right->sum), left, right);
    }

    Node *build(vector<ll> &a, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            return new Node(a[tl - 1]);
        } else {
            ll tm = (tl + tr) / 2;
            return combine(build(a, tl, tm), build(a, tm + 1, tr));
        }
    }

    SegmentTree() {}

    SegmentTree(vector<ll> &a) {
        n = a.size();
        roots = {build(a, 1, n)};
    }

    ll query(ll l, ll r, Node *node, ll tl, ll tr) { // O(log n)
        if (l <= tl && tr <= r) return node->sum;
        ll tm = (tl + tr) / 2;
        if (r < tm + 1) return query(l, r, node->left, tl, tm);
        else if (tm < l) return query(l, r, node->right, tm + 1, tr);
        else
            return combine(query(l, r, node->left, tl, tm),
                           query(l, r, node->right, tm + 1, tr));
    }

    ll kthElem(ll k, Node *ultimo, Node *anterior, ll tl, ll tr) {
        ll tot = ultimo->sum - anterior->sum;
        // cout << "VALOR DE TOT: " << tot << endl;
        if (tot < k) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        ll cant = ultimo->left->sum - anterior->left->sum;
        ll med = (tl + tr) / 2;
        if (cant >= k) {
            return kthElem(k, ultimo->left, anterior->left, tl, med);
        }
        return kthElem(k - cant, ultimo->right, anterior->right, med + 1, tr);
    }

    ll query(ll l, ll r, ll version = -1) {
        // query in the version (or the last version if it's -1)
        assert(n > 0);
        if (version == -1) {
            version = (ll)roots.size() - 1;
        }
        return query(l, r, roots[version], 1, n);
    }

    Node *update(ll pos, ll val, Node *node, ll tl, ll tr) { // O(log n)
        if (tl == tr) {
            return new Node(node->sum + val);
        } else {
            ll tm = (tl + tr) / 2;
            Node *left = node->left;
            Node *right = node->right;
            if (pos <= tm) {
                left = update(pos, val, node->left, tl, tm);
            } else {
                right = update(pos, val, node->right, tm + 1, tr);
            }
            return combine(left, right);
        }
    }

    void update(ll pos, ll val, ll version = -1, bool change = false) {
        // update a past version and append the new version to the history
        //(or update the last version if it's -1)
        assert(n > 0);
        if (version == -1) {
            version = (ll)roots.size() - 1;
        }
        if (change == true) {
            roots[version] = update(pos, val, roots[version], 1, n);
        } else {
            roots.push_back(update(pos, val, roots[version], 1, n));
        }
    }
};

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    vector<ll> vec, vec2;
    Rep1(i, n) {
        ll l;
        cin >> l;
        // vec.pb(0);
        vec2.pb(l);
    }
    Rep1(i, 50) {
        vec.pb(0);
    }
    SegmentTree st(vec);
    for (ll i = 0; i < vec2.size(); i++) {
        // cout << "Meto el valor 1 en la posicion: " << vec2[i] << endl;
        st.update(vec2[i], 1);
    }
    ll m;
    cin >> m;
    while (m--) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll pos = st.kthElem(k, st.roots[b], st.roots[a - 1], 1, 50);
        if (pos == -1) {
            cout << "Fuera de rango" << endl;
        } else {
            cout << pos << " asdasd " << endl;
        }
    }
    return 0;
}