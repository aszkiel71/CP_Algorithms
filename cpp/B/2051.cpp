#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int cycle = a + b + c;
    int full_cycles = n / cycle;
    int remaining = n % cycle;

    int res = full_cycles * 3;

    if (remaining > 0) {
      res++;
      if (remaining > a) {
        res++;
        if (remaining > a + b) {
          res++;
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
