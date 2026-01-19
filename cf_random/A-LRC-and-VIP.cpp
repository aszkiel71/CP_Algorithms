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
    int n; cin >> n; vector<int> a(n);
    int mx = -1;
    int idx;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= mx){
            mx = a[i];
            idx = i;
        }
    }
    bool same = true;
    for (int i = 0; i < n - 1; i++){
        if(same)
            same = (a[i] == a[i+1]);
    }
    if(same){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(i == idx){
            cout << 2 << " ";
        }
        else cout << 1 << " ";
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
