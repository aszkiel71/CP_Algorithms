#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool valid(int x, int y) {
  if (x == 0 || y == 0) {
    return max(x, y) < 3;
  }
  return x <= 2 * y + 2 && y <= 2 * x + 2;
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (valid(a, b) && valid(c - a, d - b)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}
