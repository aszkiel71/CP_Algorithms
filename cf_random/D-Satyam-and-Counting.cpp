#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;



inline void solve(){
    int n; cin >> n;
    map<int, vector<int>> mapka;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mapka[x].pb(y);
    }

    ll res = 0;
    for(auto k : mapka){
        if(k.second.size() == 2){
            res += n - 2;
        }
    }

    for(auto k : mapka){
        int x = k.first;
        for(int y : k.second){
            bool middle_point_found = false;
            if (mapka.count(x + 1)) {
                for (int middle_y : mapka.at(x + 1)) {
                    if (middle_y == 1 - y) {
                        middle_point_found = true;
                        break;
                    }
                }
            }

            if (middle_point_found) {
                bool right_point_found = false;
                if (mapka.count(x + 2)) {
                    for (int right_y : mapka.at(x + 2)) {
                        if (right_y == y) {
                            right_point_found = true;
                            break;
                        }
                    }
                }
                if (right_point_found) {
                    res++;
                }
            }
        }
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
