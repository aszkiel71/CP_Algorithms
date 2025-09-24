#include <algorithm>
#include <cctype>
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
  vector<bool> used(26, 1);
  for (char c : s) {
    c = tolower(c);
    used[c - 'a'] = 0;
  }
  int res = 0;
  for (bool b : used) {
    res += b;
  }
  if (res == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
