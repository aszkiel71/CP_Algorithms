#include <algorithm>
#include <cassert>
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int am = 0;
  bool possible = 1;
  vector<bool> taken(n + 1, 0);
  for (int i = 0; i < n; i++) {
    am += a[i] == -1;
    if(a[i] == -1){
        continue;
    }
    if (taken[a[i]]) {
      possible = 0;
      break;
    }
    taken[a[i]] = true;
  }
  if (!possible) {
    cout << "No\n";
    return;
  }

  vector<int> fill;
  for (int i = 1; i <= n; i++) {
    if (!taken[i]) fill.pb(i);
  }
  for (int i = 0, j = 0; i < n; i++) {
    if (a[i] == -1) {
      a[i] = fill[j];
      j++;
    }
  }

  cout << "Yes\n";
  for (int x : a) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
