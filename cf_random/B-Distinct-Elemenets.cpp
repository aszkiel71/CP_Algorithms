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
    int n; cin >> n; vector<int> a(n+1, 0), res;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int tmp = a[i+1] - a[i];
        if(i >= tmp){
            res.pb(res[i-tmp]);
        }
        else res.pb(i+1);
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
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
