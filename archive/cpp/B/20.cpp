#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        cout << -1;
        return 0;
      }
      cout << 0;
      return 0;
    }
    cout << 1 << endl;
    cout << fixed << setprecision(5) << -c / (double)b;
    return 0;
  }

  long long delta = 1LL * b * b - 4LL * a * c;
  double sqrt_delta = sqrt(delta);

  if (delta == 0) {
    cout << 1 << endl;
    cout << fixed << setprecision(5) << -b / (2.0 * a);
    return 0;
  }
  else if (delta > 0) {
    cout << 2 << endl;
    double x1 = (-b - sqrt_delta) / (2.0 * a);
    double x2 = (-b + sqrt_delta) / (2.0 * a);
    if (x1 > x2)
      swap(x1, x2);
    cout << fixed << setprecision(5) << x1 << endl;
    cout << fixed << setprecision(5) << x2;
    return 0;
  }
  else {
    cout << 0;
  }

  return 0;
}
