#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            bool tmp = false;
            if(i > 0 && s[i-1] == '0'){
                tmp = true;
            }

            if(i < n - 1 && s[i+1] == '0'){
                tmp = true;
            }

            if (!tmp) {
                cout << "NO\n";
                return;
            }
        }
        cnt += s[i] == '1';
    }

    if(cnt == 0){
        cout << "YES\n";
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    vector<int> res(n + 1);
    int last = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            int t1 = last + 1;
            int t2 = i - 1;
            //debug(t1);
            //debug(t2);
            if (t1 <= t2) {
                res[t2] = t1;
                for (int j = t1; j < t2; ++j){
                    res[j] = j + 1;
                    //debug(p[j]);
                }
            }
            if (i <= n){
                res[i] = i;
                //debug(p[i]);
            }
            last = i;
            //debug(last);
        }
    }

    int t1 = last + 1;
    int t2 = n;
    if(t1 <= t2){
        res[t2] = t1;
        for(int i = t1; i < t2; i++){
            res[i] = i + 1;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
