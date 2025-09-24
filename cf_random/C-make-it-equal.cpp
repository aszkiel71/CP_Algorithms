#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n, k;
        cin >> n >> k;
        vector<int> S(n), T(n);

        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> T[i];
        }

        map<int, int> mapkaS;
        map<int, int> mapkaT;

        for (int i = 0; i < n; i++) {
            int r = S[i] % k;
            mapkaS[min(r, (k - r) % k)]++;
        }

        for (int i = 0; i < n; i++) {
            int r = T[i] % k;
            mapkaT[min(r, (k - r) % k)]++;
        }

        bool possible = (mapkaS == mapkaT);

        if (possible) cout << "YES\n";
        else cout << "NO\n";
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
