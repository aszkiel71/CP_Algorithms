#include <iostream>

using namespace std;

int main() {
    int n, k, n1;
    cin >> n >> k >> n1;
    if (n*n <= k*n1*n1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
