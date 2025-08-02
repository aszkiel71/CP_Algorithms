#include <iostream>

using namespace std;
using ll = long long;

int counter(ll n)
{
    if (n <= 3)
        return 1;
    else
        return 2*counter(n / 4);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout << counter(n) << endl;
    }
    return 0;
}
