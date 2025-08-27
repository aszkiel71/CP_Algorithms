#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define fast_io                      \
  std::ios_base::sync_with_stdio(0); \
  std::cin.tie(0);                   \
  std::cout.tie(0);

#define debug(x) std::cerr << #x << " = " << x << std::endl;

using ll = long long;
using vi = std::vector<int>;
using pi = std::pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define EACH(x, a) for (auto& x : a)

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if ((n % 2 == b % 2) && ((n % 2 == a % 2) || (a <= b))){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
  }
}

int main() {
  fast_io;
  solve();
  return 0;
}
