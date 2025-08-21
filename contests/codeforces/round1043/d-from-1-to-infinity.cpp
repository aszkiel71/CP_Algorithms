#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

long long pot10[17];
long long sum45[17];
using namespace std;
long long suma(long long n) {
  if (n < 0) return 0;
  if (n < 10) return n * (n + 1) / 2;
  string s;
  s = to_string(n);
  long long res = 0;
  long long tmp = n;
  for (int i = 0; i < s.length(); i++) {
    // np 345 -> 0-299 + 300-345
    long long d = s[i] - '0';
    long long p = pot10[s.length() - 1 - i];
    res += d * sum45[s.length() - 1 - i];
    res += (d * (d - 1) / 2) * p;
    tmp = tmp % p;
    res += d * (tmp + 1);
  }
  return res;
}

int main() {
  pot10[0] = 1;
  for (int i = 1; i < 17; i++) pot10[i] = pot10[i - 1] * 10;
  sum45[0] = 0;
  for (int i = 1; i < 17; i++) sum45[i] = (long long)i * 45 * pot10[i - 1];
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  vector<long long> il_cyfr = {// 1 cyfrowe, 2 cyfrowe etc.
                               45,
                               855,
                               12600,
                               166500,
                               2070000,
                               24750000,
                               288000000,
                               3285000000,
                               36900000000,
                               409500000000,
                               4500000000000,
                               49050000000000,
                               531000000000000,
                               5715000000000000,
                               61200000000000000};
  vector<long long> blck_len(16, 0);
  for (int i = 1; i <= 15; i++) {
    blck_len[i] = (long long)i * 9 * pot10[i - 1];
  }

  while (t--) {
    long long k;
    cin >> k;
    long long ans = 0;

    long long d = 1;
    for (; d <= 15; d++) {
      if (k > blck_len[d]) {
        ans += il_cyfr[d - 1];
        k -= blck_len[d];
      } else
        break;
    }
    long long strt_nm = pot10[d - 1];
    long long full = (k - 1) / d;
    if (full > 0) {
      long long end = strt_nm + full - 1;
      ans += suma(end) - suma(strt_nm - 1);
    }
    long long rmn = (k - 1) % d + 1;
    string last_num;
    last_num = to_string(strt_nm + full);
    for (int i = 0; i < rmn; i++) {
      ans += last_num[i] - '0';
    }
    cout << ans << "\n";
  }
}
