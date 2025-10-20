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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  unsigned long long int pow = (1ULL << n);
  int cnt = 0;
  for (char c : t) cnt += (c == 'a');
  if (t == "a") {
    cout << 1 << "\n";
    return;
  }
  if (cnt > 0) {
    cout << -1 << "\n";
    return;
  }
  cout << pow << "\n";
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
