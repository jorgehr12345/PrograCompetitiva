#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef int ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5, MX2 = 3e5 + 2;
const ll MOD = 998244353;
// const ll INF = 1e18;
// const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

// phi(x) = phi(p)^a * phi(q)^b
ll phi(ll n) { // O(sqrt(n))
    ll ans = n;
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans -= ans / i;
        }
        i++;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

ll phi_euler[MX];
void preprocesar_phi(ll n) { // O(n log log n)
    for (int i = 0; i <= n; i++) phi_euler[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi_euler[i] == i) {
            for (int j = i; j <= n; j += i) phi_euler[j] -= phi_euler[j] / i;
        }
    }
}

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    cout << "La cantidad de coprimos de n: " << phi(n) << endl;
    preprocesar_phi(30);
    cout << phi_euler[20] << " " << phi_euler[30] << endl;
    return 0;
}