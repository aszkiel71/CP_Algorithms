#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b;
    cin >> b;
    string c;
    cin >> c;
    string s1 = "", s2 = "";
    int i = 0;
    for (char k : c) {
      if (k == 'V') {
        s1 += b[i];
      } else {
        s2 += b[i];
      }
      i++;
    }
    reverse(s1.begin(), s1.end());
    cout << s1 << a << s2 << "\n";
  }
}
