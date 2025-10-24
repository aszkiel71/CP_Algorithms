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
vector<int>dp(N, 0);
int fun(int n){
    int res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}

void load(){
    for(int i = 1; i < N; i++){
        dp[i] = dp[i-1] + fun(i);
    }
}

void solve(){
    int n; cin >> n;
    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    load();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
