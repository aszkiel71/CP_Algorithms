#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    long long axis_x = (n + a - 1) / a;
    long long axis_y = (m + a - 1) / a;
    long long result = axis_y * axis_x;
    cout << result;
    return 0;

}
