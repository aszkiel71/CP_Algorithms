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
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      continue;
    }

    bool b1 = false;
    if (i == 0) {
      b1 = true;
    }

    else if (s[i - 1] == '0') {
      b1 = true;
    }

    else if (i - 2 >= 0 && s[i - 2] == '0') {
      b1 = true;
    }

    bool b2 = false;
    if (i == n - 1) {
      b2 = true;
    }

    else if (s[i + 1] == '0') {
      b2 = true;
    }

    else if (i + 2 < n && s[i + 2] == '0') {
      b2 = true;
    }

    if (!b1 && !b2) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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
