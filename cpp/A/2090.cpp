#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a;  cin >> x >> y >> a; int tmp = a / (x + y);    int sum = tmp * (x+y);
        float aprim = (float) a;
        if (x > a)
        {
            cout << "NO\n";
        }
        else if (x + y > aprim + 0.5)
        {
            cout << "YES\n";
        }
        else
        {
            int que = 0;
            while (sum <= a)
            {
                if (que % 2 == 0)
                {
                    sum += x;
                    if (sum > a)
                    {
                        cout << "NO\n";
                        continue;
                    }
                }
                else
                {
                    sum += y;
                    if (sum > a)
                    {
                        cout << "YES\n";
                        continue;
                    }
                }
                que++;
            }
        }


    }
    return 0;
}