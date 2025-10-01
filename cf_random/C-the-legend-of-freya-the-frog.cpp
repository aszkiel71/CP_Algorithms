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
    int x, y, k; cin >> x >> y >> k;
    int x0 = (x+k-1)/k, y0 = (y+k-1)/k;

    if(y0 >= x0){
        cout << 2*y0;
    }
    else{
        cout << 2*x0 - 1;
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
