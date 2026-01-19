#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int k, x, cnt = 0; cin >> k >> x;
    int K = (1LL) << k; vector <int> res; res.clear();
    int u = 2*K - x;
    while(x!=K){
        if(x > u){
            res.pb(2);
            x -= u;
            u *= 2;
        }
        else{
            res.pb(1);
            u -= x;
            x *= 2;
        }
    }
    cout << (int)res.size() << "\n";
    reverse(all(res));
    for (int x : res) cout << x << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
