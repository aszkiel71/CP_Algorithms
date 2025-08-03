#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::string result = "";
  for (int i = 0; i < n; ++i) {
    result += (char)('a' + (i % 3));
  }

  std::cout << result << '\n';

  return 0;
}
