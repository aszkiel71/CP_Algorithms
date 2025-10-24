#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
// [1, 3] [2, 5]
typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(c < a){
        swap(a, c);
        swap(b, d);
    }

    if(d < b){
        cout << d - c << "\n";
    }
    else if(b > c){
        cout << b - c << "\n";
    }
    else{
        cout << 0 << "\n";
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
