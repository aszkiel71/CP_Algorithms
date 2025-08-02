#include <iostream>

using namespace std;


int main() {
    long long k, l;
    cin >> k >> l;
    int counter = 0;
    while (l > 1)
    {
        if (l % k != 0)
        {
            cout << "NO";
            return 0;
        }

        l /= k;
        counter++;
    }
    cout << "YES" << endl;
    cout << counter - 1;
    return 0;
}
