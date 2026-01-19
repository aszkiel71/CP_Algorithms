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
    int n, m, sum = 0, c0 = 0, c1 = 0, c2 = 0; cin >> n >> m; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        c0 += a[i] == 0;
        c1 += a[i] == 1;
        c2 += a[i] == 2;
    }

    if (sum == m){
        cout << -1 << "\n";
        return;
    }

    if (sum > m){
        for (int x : a) cout << x << " ";
        cout << "\n";
        return;
    }

    int d = m - sum;
    if(d == 1){
        while(c0--) cout << 0 << " ";
        while(c2--) cout << 2 << " ";
        while(c1--) cout << 1 << " ";
        cout << "\n";
        return;
    }
    else{
        cout << -1 << "\n";
        return;
    }

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
