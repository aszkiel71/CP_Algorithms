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

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> idx;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') idx.pb(i);
    }
    int res = idx.size();
    if(res == 0){
        cout << 0 << "\n";
        return;
    }
    // assert(0);
    // debug(res);
    for(int i = 0; i < idx.size() - 1; i++){
        if(idx[i+1] - idx[i] < k){
            res--;
        }
    }
    cout << res << "\n";
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
