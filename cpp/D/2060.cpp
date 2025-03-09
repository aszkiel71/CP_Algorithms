#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isNonIncreasing(const vector<int>& arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] < arr[i+1]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (isNonIncreasing(arr)) {
      cout << "YES\n";
      continue;
    }

    bool possible = true;
    for (int i = 0; i < n - 1; i++) {
      while (arr[i] < arr[i+1]) {
        if (i + 2 >= n) {
          possible = false;
          break;
        }
        int min_val = min(arr[i+1], arr[i+2]);
        arr[i+1] -= min_val;
        if (arr[i+1] < 0) {
          possible = false;
          break;
        }
      }
      if (!possible) break;
    }

    if (possible && isNonIncreasing(arr)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}