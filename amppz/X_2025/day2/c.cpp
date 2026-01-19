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
void solve(){
    int n; cin >> n;

    if(n == 1){
        cout << "No\n";
        return;
    }
    if(n % 3 == 1){
        cout << 2 << " " << (n-4)/3 << "\n";
    }
    else if(n % 3 == 0){
        cout << 0 << " " << n/3 << "\n"; // git
    }
    else{
        cout << 1 << " " <<  (n-2)/3 << "\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
