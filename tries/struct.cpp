#include <array>
#include <iostream>
#include <vector>
using namespace std;

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
