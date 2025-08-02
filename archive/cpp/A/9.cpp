#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


int main() {
    int y, w;
    cin >> y >> w;
    int max_val = max(y, w);
    if (max_val == 1)
    {
        cout<<"1/1";
    }

    else
    {

        cout << (7 - max_val) / gcd(7 - max_val, 6) << "/" << 6 / gcd(7 - max_val, 6);
    }

    return 0;
}
