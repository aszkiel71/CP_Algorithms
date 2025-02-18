#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int counter = 0;
      int x1, x2, x3;
      cin >> x1 >> x2 >> x3;
      if(x1 == 1)
        counter++;
      if(x2 == 1)
        counter++;
      if(x3 == 1)
        counter++;
      if(counter >= 2)
        res++;
    }
    cout << res;
    return 0;
}
