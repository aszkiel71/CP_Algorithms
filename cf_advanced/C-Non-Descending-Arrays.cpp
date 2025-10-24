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
const ll M = 998244353;
void solve(){
    int n; cin >> n; vector<int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    ll res = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(i == 0) res = (res * 2) % M;
        else if (a[i] >= b[i-1]) res = (res * 2) % M;
    }
    cout << res << "\n";
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
