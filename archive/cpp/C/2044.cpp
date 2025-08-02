#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int seated_a = min(a, m);
        int seated_b = min(b, m);
        int a_b = seated_a + seated_b;
        int remaining_seats = 2*m - a_b;
        int seated_c = min(c, remaining_seats);
        cout << (a_b + seated_c) << endl;
    }
    return 0;
}
