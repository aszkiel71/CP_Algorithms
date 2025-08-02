#include <iostream>

//have not finished yet
//to do later

using namespace std;

bool firstCondition(const int arr[], int n, int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i]*arr[i]);
    if (sum >= x)
        return true;
    return false;
}

bool secondCondition(const int arr[], int n, int y)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum <= y)
        return true;
    return false;
}

int suma(const int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    int index = 0;
    int am = 1;
    while (suma(arr, n) <= y)
    {
        if (firstCondition(arr, n, x) && secondCondition(arr, n, y))
            break;
        if (suma(arr, n) >= y)
        {
            cout << -1;
            return 0;
        }
        arr[index] += am;
        index++;
        if (index == n)
        {
            index = 0;
            am += 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}
