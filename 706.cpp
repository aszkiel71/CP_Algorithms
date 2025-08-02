#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

struct Trie {
  vector<array<int, 2>> nr;
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
      int p = s[i] - '0';
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
    // if (!find(s)) return;
    int x = 0;
    int n = s.size();
    cnt1[x]--;
    for (int i = 0; i < n; i++) {
      int p = s[i] - '0';
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
      int p = s[i] - '0';
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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  Trie trie;
  trie.insert(decToBin(0));
  while (q--) {
    char s;
    int x;
    cin >> s >> x;
    string str_temp = decToBin(x);
    if (s == '+') {
      trie.insert(str_temp);
      continue;
    }
    if (s == '-') {
      trie.del(str_temp);
      continue;
    }
    if (s == '?') {
      int res = 0;
      int node = 0;
      for (int i = 30; i >= 0; i--) {
        int cb = (x >> i) & 1;
        int target = !cb;
        if (trie.nr[node][target] && trie.cnt1[trie.nr[node][target]] > 0) {
          node = trie.nr[node][target];
          res += (1 << i);
        } else if (trie.nr[node][cb] && trie.cnt1[trie.nr[node][cb]] > 0) {
          node = trie.nr[node][cb];
        }
      }
      cout << res << '\n';
    }
  }
  return 0;
}
