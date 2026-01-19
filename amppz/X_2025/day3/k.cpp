#include <stdint.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// #define int long long
#define INLINE __attribute__((always_inline)) inline
#define NOINLINE __attribute__((noinline))
#define LIKELY(x) (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

INLINE int ile_1(uint32_t x){
    int res = 0;
    while(x){
        res += x%2;
        x/=2;
    }
    return res;
}

INLINE void solve() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<uint32_t> spotkania;
  uint32_t wszyscy = 0;
  for (int i = 0; i < m; i++) {
    wszyscy = wszyscy | (1 << i);
  }

  for (int i = 0; i < n; i++) {
    uint32_t time_slot = 0;
    std::string time_slot_str;
    std::cin >> time_slot_str;
    for (int j = 0; j < m; j++) {
      if (time_slot_str[j] == 'Y') {
        time_slot = time_slot | (1 << j);
      }
    }
    spotkania.push_back(time_slot);
  }

  int max_suma_jedynek = 0;
  int max_i;
  int max_j;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((spotkania[i] | spotkania[j]) == wszyscy) {
        if((ile_1(spotkania[i]) + ile_1(spotkania[j])) > max_suma_jedynek)
        {
            max_suma_jedynek = (ile_1(spotkania[i]) + ile_1(spotkania[j]));
            max_i = i;
            max_j = j;
        }
      }
    }
  }
  if(max_suma_jedynek != 0 ) {
    std::cout << (max_i + 1) << " " << (max_j + 1);
  }
  else {
  std::cout << "No";
  }


  return;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);
  solve();
}
