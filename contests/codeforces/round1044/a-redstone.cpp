#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//vector<int> x;

// y[i] = x[i - 1];
// z[i] = s[i - 1];
// s[i] = (float)y/x * z = x[i-1]/x[i] * s[i - 1]
/*
bool validator(int index, int n) {
  vector<double> s(n);
  s[0] = 1.0;
  swap(x[index], x[n - 1]);

  for (int i = 1; i < n; i++) {
    s[i] = ((double)x[i - 1]) / ((double)x[i]) * s[i - 1];
  }

  bool result = !(abs(s[n - 1] - 1.0)
  swap(x[index], x[n - 1]);
  return false;
}*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    bool ok = false;

    for (int i = 0; i < n && !ok; i++) {
        for(int j = 0 ; j < n; j++){
            if(i != j && x[i] == x[j]){
                ok = 1;
                break;
            }
        }
    }
    if (ok)
      cout << "yEs\n";
    else
      cout << "No\n";
  }
}
