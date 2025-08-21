#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unsigned long long prv = 45;
  cout << prv;

  unsigned long long pot = 1;

  for (int n = 2; n <= 15; ++n) {
    pot *= 10;
    unsigned long long act = 10 * prv + 45 * pot;
    unsigned long long res = act - prv;
    cout << ", " << res;
    prv = act;
  }

  cout << endl;

  return 0;
}
