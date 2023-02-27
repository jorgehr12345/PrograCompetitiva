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
const ll MX = 8e3 + 5, MX2 = 3e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll dp[MX2][MX], locura[MX];
ll riesgo(ll j, ll i) {
    if (j > i) {
        return INF;
    }
    return (locura[i] - locura[j - 1]) * (i - j + 1);
}
void compute(int guardiaParcial, int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mi = (l + r) / 2;
    ll opt = -1;
    dp[guardiaParcial][mi] = INF;
    for (ll i = optl; i <= optr; i++) {
        ll costoParcial = dp[guardiaParcial - 1][i] + riesgo(i + 1, mi);
        // cout << "Costo parcial " << i << " asd " << costoParcial << endl;
        if (costoParcial < dp[guardiaParcial][mi]) {
            dp[guardiaParcial][mi] = costoParcial;
            opt = i;
        }
    }
    // cout << " qweqwe " << dp[guardiaParcial][mi] << endl;
    // cout << " sadasd " << opt[guardiaParcial][mi] << endl;
    compute(guardiaParcial, l, mi - 1, optl, opt);
    compute(guardiaParcial, mi + 1, r, opt, optr);
}
void dcOp(ll guardias, ll presos) {
    for (ll i = 1; i <= presos; i++) {
        // opt[1][i] = 1;
        dp[1][i] = riesgo(1, i);
    }
    if (guardias >= 2) {
        for (ll i = 2; i <= guardias; i++) {
            compute(i, 1, presos, 0, presos);
        }
        cout << dp[guardias][presos] << endl;
    } else {
        cout << dp[1][presos] << endl;
    }
}

int main() {
    inic;
    inic2;
    ll n, g;
    cin >> n >> g;
    Rep1(i, n) {
        cin >> locura[i];
        locura[i] += locura[i - 1];
    }
    dcOp(g, n);
    return 0;
}