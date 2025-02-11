#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    bool even = false;
    int balance = 0;
    if (t1 % 2 == 0)
    {
        balance += 1;
    }
    if (t2 % 2 == 0)
    {
        balance += 1;
    }
    if (t3 % 2 == 0)
    {
        balance += 1;
    }
    if (balance > 1)
    {
        even = true;
    }

    for (int i = 3; i < n; i++)
    {
        int a;
        cin >> a;
        if (even)
        {
            if (a % 2 == 1)
            {
                cout << i + 1;
                return 0;
            }
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << i + 1;
                return 0;
            }
        }
    }

    if (even)
    {
        if (t1 % 2 == 1)
        {
            cout << 1;
            return 0;
        }
        if (t2 % 2 == 1)
        {
            cout << 2;
            return 0;
        }
        cout << 3;
        return 0;
    }
    else
    {
        if (t1 % 2 == 0)
        {
            cout << 1;
            return 0;
        }
        if (t2 % 2 == 0)
        {
            cout << 2;
            return 0;
        }
        cout << 3;
        return 0;
    }

    return 0;
}
