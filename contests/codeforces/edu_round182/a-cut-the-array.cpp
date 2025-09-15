#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  bool flague = true;
  for (int i = 0; i < n - 2 && flague; i++) {
    for (int j = i + 1; j < n - 1 && flague; j++) {
      int s1 = pref[i];
      int s2 = pref[j] - s1;
      int s3 = pref[n - 1] - pref[j];
      if (!((s1 + s2 + s3) % 3)) {
        cout << i + 1 << " " << j + 1 << "\n";
        flague = 0;
      }
    }
  }
  if (flague) {
    cout << 0 << " " << 0 << "\n";
  }
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
