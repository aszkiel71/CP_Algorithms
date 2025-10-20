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

void solve3(int a1, int a2, int a3, int a4, int a5 = 1) {
  for (int i = 0; i < a2 * a4; i++) {
    for (int j = 0; j < a1 * a3; j++) {
      int x = j / a3, y = i / a4;
      if (((x + y) % 2) ^ a5)
        printf("#");  // x%2 != y%2 := (x+y)%2
      else
        printf(".");
    }
    printf("\n");
  }
}

void solve() {
  int n;
  cin >> n;
  solve3(n, n, 2, 2);
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
