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
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = (ll) (prefix_sum[i - 1] + a[i]);
    }
    

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
