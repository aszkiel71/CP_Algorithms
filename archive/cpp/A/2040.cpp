#include <iostream>

using namespace std;

int abs(int a) {
  return a > 0 ? a : -a;
}

bool win(int a, int j, int k) {
  return (abs(a - j) % k != 0);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
      cin >> a[i];

    bool found = false;
    for(int i = 0; i < n; i++) {
      bool flag = true;
      for(int j = 0; j < n; j++) {
        if(i != j && abs(a[i] - a[j]) % k == 0) {
          flag = false;
          break;
        }
      }
      if(flag) {
        cout << "YES" << endl << i + 1 << endl;
        found = true;
        break;
      }
    }

    if(!found) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
