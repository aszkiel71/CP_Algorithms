#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x == y)
    {
      cout << "NO\n";
      continue;
    }
    if (y == x + 1) {
      cout << "YES\n";
      continue;
    }
    int tmp = x + 1 - y;
    if (tmp < 0 || tmp % 9 != 0) {
      cout << "NO\n";
      continue;
    }
    int k = tmp / 9;
    if (k <= 0) {
      cout << "NO\n";
      continue;
    }
    if ((x - 9 * k >= 1) || (x - 9 * k == 0 && y == 1)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}