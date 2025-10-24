#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    vector<long long> dp(n, LLONG_MAX);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j)
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n - 1];


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

}
