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

void yes() { cout << "YES\n"; }

void no() { cout << "NO\n"; }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> prefix_max(n, 0);
  prefix_max[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix_max[i] = max(prefix_max[i - 1], a[i]);
  }
  ll res = 0;
  // int curr_min = a[0];
  /*for(int i = 0; i < n-1; i++){
      if(i%2 == 1){
          if(a[i] >= a[i+1]){
              res++; // 4 > 10 -> 10 := 4 -> 4 > 4 -> 4 > 3
              a[i+1] = a[i] - 1;
          }
      }
      else{
          if(a[i] <= a[i+1]){
              res++;
              a[i+1] = a[i];
              a[i]--;
          }
      }
  }*/
  for (int i = 1; i < n; i += 2) {
    a[i] = prefix_max[i];
    // debug(a[i]);
  }
  /*for(int i = 1; i < n; i+=2){
      if(a[i] == a[i-1]){
          res++;
      }
      if(i+1 < n){
          if(a[i] <= a[i+1]){
              res += (a[i+1] - a[i]) + 1;
          }
      }
  }*/
  for (int i = 0; i < n; i += 2) {
    ll tmp;
    if (i == 0) {
      tmp = a[i + 1] - 1;
    } else if (i == n - 1) {
      tmp = a[i - 1] - 1;
    } else {
      tmp = min(a[i - 1], a[i + 1]) - 1;
    }
    if (a[i] - tmp > 0) {
      res += (a[i] - tmp);
    }
  }

  cout << res << "\n";
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
