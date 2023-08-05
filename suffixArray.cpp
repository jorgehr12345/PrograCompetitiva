#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 3e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

const int ALPH = 256;
struct SuffixArray {
    vector<int> suffixArray;

    SuffixArray() {}

    void buildSuffix(string &s) { // Obtengo el arreglo de suffix array
        char mnmChar = *min_element(s.begin(), s.end()) - 1;
        s += mnmChar;
        suffixArray = sortCyclic(s);
        suffixArray.erase(suffixArray.begin());
        s.pop_back();
        // for(ll i=0;i<suffixArray.size();i++){
        //     cout<<suffixArray[i]<<" ";
        // }cout<<endl;
    }

    void buildCyclicShift(string &s) {
        suffixArray = sortCyclic(s);
    }

    vector<int> sortCyclic(const string &s) { // O(N log N)
        int n = s.size();
        vector<int> p(n), c(n), cnt(max(ALPH, n));
        // counting sort
        for (int i = 0; i < n; ++i) cnt[s[i]]++;
        for (int i = 1; i < ALPH; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]]) classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pNew(n), cNew(n);
        // radix sort
        for (int k = 0; (1 << k) < n; k++) {
            // sort pNew by the second substring
            for (int i = 0; i < n; i++) {
                cnt[i] = 0;
                pNew[i] = p[i] - (1 << k);
                if (pNew[i] < 0) pNew[i] += n;
            }
            // counting sort in the first substring
            for (int i = 0; i < n; ++i) cnt[c[pNew[i]]]++;
            for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) p[--cnt[c[pNew[i]]]] = pNew[i];
            cNew[p[0]] = 0, classes = 1;
            for (int i = 1; i < n; i++) {
                int x = p[i] + (1 << k), y = p[i - 1] + (1 << k);
                if (x >= n) x -= n;
                if (y >= n) y -= n;
                pair<int, int> cur = {c[p[i]], c[x]};
                pair<int, int> prev = {c[p[i - 1]], c[y]};
                if (cur != prev) classes++;
                cNew[p[i]] = classes - 1;
            }
            c = cNew;
        }
        return p;
    };

    vector<int> buildLCP(const string &s) { // O(n)
        int n = s.size();
        vector<int> lcp(n - 1), pos(n);
        for (int i = 0; i < n; ++i) pos[suffixArray[i]] = i;
        for (int r = 0, k = 0; r < n; ++r) {
            if (!pos[r]) continue;
            int l = suffixArray[pos[r] - 1];
            while (s[l + k] == s[r + k]) k++;
            lcp[pos[r] - 1] = k;
            k = max(0, k - 1);
        }
        return lcp;
    }
};

int main() {
    inic;
    inic2;
    string s;
    cin >> s;
    SuffixArray sa = SuffixArray();
    sa.buildSuffix(s);
    vector<int> vec = sa.buildLCP(s);
    for (ll i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
