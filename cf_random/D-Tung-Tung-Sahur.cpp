#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    string p, s; cin >> p >> s;
    int l = 0;
    int d = 0;
    int n = s.size();
    int m = p.size();

    while (d < m) {
        if (l >= n || p[d] != s[l]) {
            cout << "NO\n";
            return;
        }

        int d_end = d;
        while (d_end + 1 < m && p[d_end + 1] == p[d]) {
            d_end++;
        }
        long long count_p = d_end - d + 1;

        int l_end = l;
        while (l_end + 1 < n && s[l_end + 1] == s[l]) {
            l_end++;
        }
        long long count_s = l_end - l + 1;

        if (count_s < count_p || count_s > 2 * count_p) {
            cout << "NO\n";
            return;
        }

        d = d_end + 1;
        l = l_end + 1;
    }

    if (l < n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
