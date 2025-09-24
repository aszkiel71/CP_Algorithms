#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

struct Trie {
  vector<array<int, 26>> nr;
  vector<int> cnt1;  // how many words use that node
  vector<int> cnt2;  // how many words end in that node
  int t;

 public:
  Trie() {
    t = 1;
    cnt1.push_back(0);
    cnt2.push_back(0);
    nr.emplace_back();
  }
  void insert(string s) {
    int x = 0;
    int n = s.size();
    cnt1[x]++;
    for (int i = 0; i < n; i++) {
      int p = s[i] - 'a';
      if (nr[x][p] == 0) {
        nr[x][p] = t;
        t++;
        nr.emplace_back();
        cnt1.push_back(0);
        cnt2.push_back(0);
      }
      x = nr[x][p];
      cnt1[x]++;
    }
    cnt2[x]++;
  }

  void del(string s) {
    if (!find(s)) return;
    int x = 0;
    int n = s.size();
    cnt1[x]--;
    for (int i = 0; i < n; i++) {
      int p = s[i] - 'a';
      int next = nr[x][p];
      cnt1[next]--;
      x = next;
    }
    cnt2[x]--;
  }

  bool find(string s) {
    int x = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int p = s[i] - 'a';
      if (nr[x][p] == 0) return false;
      x = nr[x][p];
    }
    if (cnt2[x] == 0) return false;
    return true;
  }
};

string decToBin(int x) {
  string res = "";
  while (x) {
    res += '0' + (x & 1);
    x >>= 1;
  }
  while (res.length() < 31) {
    res += '0';
  }
  reverse(res.begin(), res.end());
  return res;
}


void solve() {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    Trie t;
    for (int i1 = 0; i1 <= tmp2; ++i1) {
        string s1 = decToBin(i1);
        string s2 = "";
        for (char ch : s1) {
            if (ch == '0') {
                s2 += 'a';
            } else {
                s2 += 'b';
            }
        }
        t.insert(s2);
    }

    vector<int> res_v(tmp2 + 1);
    for (int i1 = tmp2; i1 >= 0; --i1) {
        string s3 = decToBin(i1);
        string s4 = "";
        for (char ch : s3) {
            if (ch == '0') {
                s4 += 'a';
            } else {
                s4 += 'b';
            }
        }

        string s5 = "";
        int v1 = 0;
        for (int i2 = 0; i2 < 31; ++i2) {
            int v2 = s4[i2] - 'a';
            int v3 = 1 - v2;
            int v4 = t.nr[v1][v3];

            if (v4 != 0 && t.cnt1[v4] > 0) {
                s5 += (char)('a' + v3);
                v1 = v4;
            } else {
                s5 += (char)('a' + v2);
                v1 = t.nr[v1][v2];
            }
        }

        t.del(s5);

        int v5 = 0;
        for (int i2 = 0; i2 < 31; ++i2) {
            if (s5[i2] == 'b') {
                v5 |= (1 << (30 - i2));
            }
        }
        res_v[i1] = v5;
    }

    long long final_sum = 0;
    for (int i1 = 0; i1 <= tmp2; ++i1) {
        final_sum += (long long)(i1 | res_v[i1]);
    }

    cout << final_sum << "\n";
    for (int i1 = 0; i1 <= tmp2; ++i1) {
        cout << res_v[i1] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
