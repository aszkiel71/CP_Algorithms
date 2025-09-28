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
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << s1 << " " << s2 << "\n";
    string t1, t2;
    cin >> t1 >> t2;
    if (t1 == s1) {
      s1 = t2;
    } else {
      s2 = t2;
    }
  }
  cout << s1 << " " << s2 << "\n";
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
