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

#define int long long

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a % b);
}

void solve(){
    int n, k; cin >> n >> k; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] << "\n";
        return;
    }
    sort(all(a));
    int lower = 1, upper = a[k];
    


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
