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
    int n, q; cin >> n >> q; string s; cin >> s;
    vector<int> a(q); int mx = 0;
    for(int i = 0; i < q; i++){
        cin >> a[i];
        bool just_a = true;
        for(char c : s){
            if(c == 'B'){
                just_a = false;
                break;
            }
        }
        if(just_a){
            cout << a[i] << "\n";
            continue;
        }
        else{
            bool skip = false;
            int res = 0;
            while(!skip){
            for(char c : s){
                if(a[i] <= 0 && !skip){
                    cout << res << "\n";
                    skip = true;
                    break;
                }
                if(c == 'A'){
                    a[i]--;
                }
                else{
                    a[i] /= 2;
                }
                res++;
              }
            }
        }
        // mx = max(mx, a[i]);
        /*int tmp = a[i];
        int dx; int res = n; // res -> dlugosc cyklu * ile razy cykl + reszta
        for(char c : s){
            if(c == 'A'){
                tmp -= 1;
            }
            else tmp/=2;
        }
        dx = a[i] - tmp;
        // sprawdzamy ile jeden cykl zmienia
        res *= (a[i] / dx);
        int reszta = a[i] - dx*(a[i]/dx);
        // int tmp_res = 0;
        for(char c : s){
            if(reszta <= 0) break;
            res++;
            reszta -= dx;
        }
        cout << res << "\n";/*/
    }

    // vector<ll> dp(mx+1, 0);

    // A :  x -= 1
    // B :  x /= 2

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
