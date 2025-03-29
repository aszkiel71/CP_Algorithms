#include <iostream>

using namespace std;

bool even(int num) {
  return num % 2 == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int op = 0;
    int n, k;
    cin >> n >> k;

    if (n <= k) {
      cout << "1\n";
      continue;
    }

    if (n < 2 * k) {
      cout << "2\n";
      continue;
    }


    if (n % 2 != 0) {
      n -= k;
      op += 1;
    }

    int tmp = n / (k - 1);
    op += tmp;
    n -= tmp * ((k / 2) + ((k - 1) / 2));

    if (n == 0) {
      cout << op << "\n";
      continue;
    }

    while (n > 0) {
      if (even(n)) {
        if (n <= k - 1) {
          op++;
          n = 0;
        } else {
          op++;
          n -= (k - 1);
        }
      } else {
        if (n <= k) {
          op++;
          n = 0;
        } else {
          op++;
          n -= k;
        }
      }
    }

    cout << op << "\n";
  }
  return 0;
}