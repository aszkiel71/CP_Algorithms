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
    int n; cin >> n; vector<int> a(n);
    vector<int> cnt(n+1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += ((cnt[i]) >= 2);
        if(cnt[i] >= 4){
            cout << "YES\n";
            return;
        }
    }
    if(res >= 2){
        cout << "YES\n";
    }
    else cout << "NO\n";
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
