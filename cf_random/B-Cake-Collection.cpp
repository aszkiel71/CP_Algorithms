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
    int n, m; cin >> n >> m; vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll res = 0;
    sort(all(a));
    reverse(all(a));
    for(int i = 0; i < n; i++){
        res += a[i] * max(0, m-i);
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
