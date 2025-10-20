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
ll min(ll a, ll b){return (a < b ? a : b);}
void solve(){
    int m, x;
    cin >> m >> x;
    vector<ll> h(m), c(m); ll hap = 0;

    for(int i = 0; i < m; i++) {
        cin >> c[i] >> h[i];
        hap += h[i];
    }
    vector<ll> dp(hap+1, inf); dp[0] = 0;
    for(ll i = 0; i < m; i++){
        for(ll j = hap; j >= h[i]; j--){
            if(dp[j-h[i]] + c[i] <= i*x){
                dp[j] = min(dp[j], dp[j-h[i]] + c[i]);
            }
        }
    }
    for(ll i = hap; i >= 0; i--){
        if(dp[i] != inf){
            cout << i << "\n";
            return;
        }
    }
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
