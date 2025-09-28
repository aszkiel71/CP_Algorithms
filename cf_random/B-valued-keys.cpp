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
    string x, y; cin >> x >> y;
    int n = x.size();
    string s = "";
    for(int i = 0; i < n; i++){
        if(x[i] == y[i]){
            s += x[i];
        }
        else if(x[i] > y[i]){
            s += y[i];
        }
        else{
            cout << -1;
            return;
        }
    }
    cout << s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
