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

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}


void solve(){
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    ll res = 0;
    for(int i = 0; i < n - 1; i+=2){
        ll tmp = abs(a[i] - a[i+1]);
        //debug(tmp);
        //debug(a[i]);
        //debug(a[i+1]);
        if(tmp > res) res = tmp;
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
