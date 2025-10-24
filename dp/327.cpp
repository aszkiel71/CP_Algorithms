#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n; int tmp = 0;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    if(a[i]) {
        b[i] = -1; tmp++;
    }
    else b[i] = 1;
  }
  vector<int> dp(n);
  dp[0] = b[0]; int res = dp[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(b[i], dp[i - 1] + b[i]);
    res = max(res, dp[i]);
  }

  res += tmp;
  if(tmp == n){cout << n - 1;}
  else cout << res;

}
