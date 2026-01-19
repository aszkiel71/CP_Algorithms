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
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    sort(all(s1)); sort(all(s2));
    if(s1 == s2){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
