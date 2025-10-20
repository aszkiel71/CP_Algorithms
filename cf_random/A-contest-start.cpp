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
ll max(ll a, ll b){
    return a > b ? a : b;
}
void solve(){
    ll n, x, t; cin >> n >> x >> t;
    ll t1 = max(0, n-t/x);
    ll t2 = min(n, t/x);
    ll res = t1*(t/x) + (t2-1)*t2/2;
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
