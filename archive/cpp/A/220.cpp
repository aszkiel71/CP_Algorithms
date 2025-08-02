#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n), sortedArr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sortedArr[i] = arr[i];
  }

  sort(sortedArr.begin(), sortedArr.end());

  int diffCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != sortedArr[i]) {
      diffCount++;
    }
  }

  if (diffCount == 2 || diffCount == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
