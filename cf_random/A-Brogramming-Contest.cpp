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
#define int long long
void solve(){
    int n; string s; cin >> n >> s;
    // s -> 0, t -> 1
    int res = 0;
    for(int i = 0; i < n-1; i++){
        res += (s[i] != s[i+1]);
    }
    res += s[0] == '1';
    cout << res << "\n";
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
