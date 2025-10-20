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
    int n; cin >> n; 
    string r,b;
    cin >> r >> b;
    int b0 = 0, r0 = 0;
    for(int i = 0; i < n; i++){
        b0 += (b[i] > r[i]);
        r0 += (r[i] > b[i]);
    }
    if(r0 > b0){
        cout << "RED\n";
    }
    else if(r0 < b0){
        cout << "BLUE\n";
    }
    else cout << "EQUAL\n";
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
