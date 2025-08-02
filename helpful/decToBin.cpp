#include <iostream>
using namespace std;

string decToBin(int x) {
  string res = "";
  while (x) {
    res += '0' + (x & 1);
    x >>= 2;
  }
  while (res.length() < 31) {
    res += '0';
  }
  reverse(res.begin(), res.end());
  return res;
}
