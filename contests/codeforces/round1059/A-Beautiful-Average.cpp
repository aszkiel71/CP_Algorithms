#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ps(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + a[i-1];
    }
    int mx = 0;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            mx = max((ps[r+1] - ps[l])/(r-l+1), mx);
        }
    }
    cout << mx << "\n";
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
