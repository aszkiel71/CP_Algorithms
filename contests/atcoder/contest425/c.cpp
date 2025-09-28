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
    int n, Q; cin >> n >> Q; vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> ps(2*n + 1, 0);
    for(int i = 0; i < 2*n; i++){
        ps[i + 1] = ps[i] + a[i % n];
    }
    ll delta = 0;
    while(Q--){
        int query; cin >> query;
        if(query == 1){
            int c; cin >> c;
            delta += c;
            delta = delta % n;
        }
        else if(query == 2){
            int l, r; cin >> l >> r; l--; r--;
            ll res = ps[delta + r + 1] - ps[delta + l];
            cout << res << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
