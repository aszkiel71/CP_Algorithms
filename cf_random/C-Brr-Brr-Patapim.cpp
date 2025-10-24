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
  int n;
  cin >> n;
  vector<vector<int>> a(1+n, vector<int>(1+n));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<bool> used(2*n + 1, 0);
  vector<int> res(2 * n + 1, -1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        res[i + j] = a[i][j];
        used[a[i][j]] = true;
        //debug(res[i + j]);
    }
  }
  vector<int> fill;
  for(int i = 1; i <= 2*n; i++){
        if(!used[i]) fill.pb(i);
  }
  int j = 0;
  for(int i = 1; i < 2*n + 1; i++){
    if(res[i] == -1){
        res[i] = fill[j];
        j++;
    }
  }
  for(int i = 1; i < 2*n + 1; i++){
    cout << res[i] << " ";
  }

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
