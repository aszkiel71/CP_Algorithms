#include <iostream>
using namespace std;

bool isLucky(int n)
{
    if (n == 0)
        return false;
    while (n > 0)
    {
        if (n % 10 != 4 and n % 10 != 7)
        {
            return false;
        }
        n = n / 10;
    }

    return true;
}


bool isNearlyLucky(long long n)
{
    int counter = 0;
    while (n > 0)
    {
        if (n % 10 == 4 or n % 10 == 7)
            counter++;
        n = n / 10;
    }
    return isLucky(counter);
}

int main() {
    long long n;
    cin >> n;
    cout << (isNearlyLucky(n) ? "YES" : "NO");
    return 0;
}
