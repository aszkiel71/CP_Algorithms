#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void solve() {
    long long a, b;
    cin >> a >> b;

    if (a % 2 == 0 && b % 2 != 0) {
        cout << -1 << "\n";
    }

    else if (a % 2 != 0 && b % 2 != 0) {
        cout << a*b + 1 << "\n";
    }
    else if (a % 2 == 0 && b % 2 == 0) {
        cout << max(a + b, a * (b/2) + 2) << "\n";
    }
    else {
        if (b % 4 != 0) {
            cout << -1 << "\n";
        } else {
            cout << max(2*a + b/2, a * (b/2) + 2) << "\n";
        }
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}