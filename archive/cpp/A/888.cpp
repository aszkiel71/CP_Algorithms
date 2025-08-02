#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int counter = 0;
    if (n <= 2)
    {
        cout << "0";
        return 0;
    }
    for (int i = 1; i < n - 1 ;i++)
    {
        if (a[i] > a[i-1] && a[i] > a[i+1])
            counter++;
        else if ( a[i] < a[i-1] && a[i] < a[i+1])
            counter++;
    }
    cout << counter;


    return 0;
}
