#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double chance = ((double)a / b) / (1 - (1 - ((double)a / b)) * (1 - ((double)c / d)));

    cout << fixed << setprecision(12) << chance;

    return 0;
}
