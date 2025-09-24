#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    vector<vector<int>> contain(m + 1);
    for (int i = 0; i < n; i++){
        int li; cin >> li;
        for(int j = 0; j < li; j++){
            int tmp; cin >> tmp;
            cnt[tmp]++;
            contain[tmp].pb(i);
        }
    }

    int res = 0;
    set<int> ess;
    for(int i = 1; i <= m; i++){
        if(cnt[i] == 0){
            cout << "NO\n";
            return;
        }
        if(cnt[i] == 1){
            ess.insert(contain[i][0]);
        }
    }
    int ness = n - ess.size();
    if(ness >= 2){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
