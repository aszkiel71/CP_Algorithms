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
    int n; cin >> n; vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> ps(n);
    ps[0] = a[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1] + a[i];
    }
    ll res = a[0] == 0;
    set<ll> setka; setka.insert(a[0]);
    ll tmp_max = a[0];
    for(int i = 1; i < n; i++){
        tmp_max = max(tmp_max, a[i]);
        ll tmp_sum = ps[i] - tmp_max;
        if(tmp_sum == tmp_max) res++;
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
