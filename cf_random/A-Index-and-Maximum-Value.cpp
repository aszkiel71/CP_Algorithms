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
    int n, m; cin >> n >> m; vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for(int i = 0; i < m; i++){
        char c; cin >> c;
        int l, r; cin >> l >> r;
        if(l <= mx && mx <= r){
            if(c == '+') mx++;
            else mx--;
        }
        cout << mx << " ";
    }
    cout << "\n";
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
