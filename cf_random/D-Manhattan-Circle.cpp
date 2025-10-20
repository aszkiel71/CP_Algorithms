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
    int n, m; cin >> n >> m;
    int sum = 0; int c_x = 0, c_y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == '#'){
                c_x += i+1;
                c_y += j+1;
                sum++;
            }
        }
    }
    cout << c_x / sum << " " << c_y / sum << "\n";
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
