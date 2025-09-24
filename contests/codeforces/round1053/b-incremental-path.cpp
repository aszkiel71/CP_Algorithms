#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
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
#define int ll
// pseudo-mex :)


void solve() {
  int n, m;
  cin >> n >> m;

  string s;
  set<int> black;
  cin >> s;
  for (int i = 0; i < m; i++) {
    int tmp; cin >> tmp;
    black.insert(tmp);
  }
  //bool visit_pls = 0;
   int cell = 1;
  for (int i = 0; i < n; i++) {
      char c = s[i];
      cell++;
      // debug(c);
      if (c == 'B'){
        while(black.count(cell)){
            cell++;
        }
      }

        black.insert(cell);
        if (c == 'B'){
        while(black.count(cell)){
            cell++;
        }
      }


            //debug(cell);


        // vector<ll> tmp(black.begin(), black.end());

        // int l = 0, r = black.size() - 1;
        // int wynik = -1;
        // while(l <= r){
        //     int mid = (l + r) / 2;
        //     if(tmp[mid] >= cand){
        //     }
        // }
        // cell = nxt_white_cell; // bin search
        // res.pb(cell);


        //debug(cell);

      //debug(res.back());

    }


  cout << black.size() << "\n";
  for (auto x : black){
    cout << x << " ";
  }

  cout << "\n";

}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
