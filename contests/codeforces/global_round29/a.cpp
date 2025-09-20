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
    int x, y; cin >> x >> y;;
    if(x < y){
        cout << 2 << "\n";
        return;
    }
    if(x == y){
        cout << -1 << "\n";
        return;
    }
    if(x >= y + 2 && y >= 2){
        cout << 3 << "\n";
        return;
    }
    cout << -1 << "\n";


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
