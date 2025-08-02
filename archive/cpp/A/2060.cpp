#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        int a3 = a5 - a4;
        int fibonacciness1 = (a1 + a2 == a3) + (a2 + a3 == a4) + (a3 + a4 == a5);
        a3 = a1 + a2;
        int fibonacciness2 = (a1 + a2 == a3) + (a2 + a3 == a4) + (a3 + a4 == a5);
        int result;
        result = max(fibonacciness1, fibonacciness2);
        cout << result << endl;
    }
    return 0;
}
