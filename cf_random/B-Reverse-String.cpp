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

#define int long long


const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;

int hash1[N], pot1[N];
int hash2[N], pot2[N];

pair<int, int> getHash(int a, int b) {
  int res1 =
      (hash1[a] - (((long long)hash1[b + 1] * pot1[b - a + 1]) % M1) + M1) % M1;
  int res2 =
      (hash2[a] - (((long long)hash2[b + 1] * pot2[b - a + 1]) % M2) + M2) % M2;
  return {res1, res2};
}

void precomputePowers() {
  pot1[0] = 1;
  pot2[0] = 1;
  for (int i = 1; i < N; i++) {
    pot1[i] = ((long long)pot1[i - 1] * ST1) % M1;
    pot2[i] = ((long long)pot2[i - 1] * ST2) % M2;
  }
}


void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  string s_rev = s;
  reverse(all(s_rev));

  string combined = s + "#" + t + "$" + s_rev;
  int n_comb = combined.size();

  hash1[n_comb] = 0;
  hash2[n_comb] = 0;
  for (int i = n_comb - 1; i >= 0; i--) {
    hash1[i] = (((long long)hash1[i + 1] * ST1) + (combined[i] - 'a' + 1)) % M1;
    hash2[i] = (((long long)hash2[i + 1] * ST2) + (combined[i] - 'a' + 1)) % M2;
  }

  int s_offset = 0;
  int t_offset = n + 1;
  int s_rev_offset = n + 1 + m + 1;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int len_right = j - i + 1;
      if (len_right > m) continue;

      pair<int, int> hash_s_right = getHash(s_offset + i, s_offset + j);
      pair<int, int> hash_t_right =
          getHash(t_offset + 0, t_offset + len_right - 1);

      if (hash_s_right == hash_t_right) {
        int len_left = m - len_right;

        if (j < len_left) continue;

        if (len_left == 0) {
          cout << "YES\n";
          return;
        }

        pair<int, int> hash_t_left =
            getHash(t_offset + len_right, t_offset + m - 1);

        int a_rev = n - 1 - j + 1;
        int b_rev = n - 1 - j + len_left;

        pair<int, int> hash_s_left =
            getHash(s_rev_offset + a_rev, s_rev_offset + b_rev);

        if (hash_t_left == hash_s_left) {
          cout << "YES\n";
          return;
        }
      }
    }
  }

  cout << "NO\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  precomputePowers();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
