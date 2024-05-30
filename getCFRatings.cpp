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
const ll MX = 2e5 + 5, MX2 = 1024 * 1024 + 2, MX3 = 5e2 + 2;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

long double getWinProbability(long double ra, long double rb) {
    return 1.0 / (1.0 + pow((long double)10.0, (rb - ra) / 400.0));
}

long double aggregateRatings(vector<long double> teamRatings) {
    long double left = 1;
    long double right = 1E4;

    for (int tt = 0; tt < 100; tt++) {
        long double r = (left + right) / 2.0;

        long double rWinsProbability = 1.0;
        for (ll i = 0; i < teamRatings.size(); i++) {
            rWinsProbability *= getWinProbability(r, teamRatings[i]);
        }
        long double rating = log10(1 / (rWinsProbability)-1) * 400 + r;

        if (rating > r) left = r;
        else right = r;
    }

    return (left + right) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ld> vec;
    vec.pb(2041);
    vec.pb(1908);
    vec.pb(1436);
    cout << aggregateRatings(vec) << endl;
    vector<ld> vec2;
    vec2.pb(1900);
    vec2.pb(1800);
    vec2.pb(1400);
    cout << aggregateRatings(vec2) << endl;

    return 0;
}
