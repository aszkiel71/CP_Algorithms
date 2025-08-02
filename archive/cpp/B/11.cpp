#include <iostream>
#include <cmath>

using namespace std;

int min_jumps(int x) {
    x = abs(x);
    int n = 0;
    int sum = 0;

    while (sum < x || (sum - x) % 2 != 0) {
        n++;
        sum += n;
    }

    return n;
}

int main() {
    int x;
    cin >> x;
    cout << min_jumps(x) << endl;
    return 0;
}
