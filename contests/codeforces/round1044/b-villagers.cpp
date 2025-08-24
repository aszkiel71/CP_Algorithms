#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// ver1 --- doesn't work
// later I will do upsolving


void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long res = 0;
  if (n % 2) res = a[n - 1];
  for (int i = 0; i + 1 < n; i += 2) {
    res += a[i + 1];
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
