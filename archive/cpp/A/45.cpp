#include <iostream>

using namespace std;

int search(const string arr[], const string &x)
{
    for (int i = 0; i < 12; i++)
    {
        if (arr[i] == x)
            return i;
    }
}

int main() {
    string months [] = {"January", "February", "March", "April", "May", "June", "July", "August",
                        "September", "October", "November", "December"};

    string s;
    int n;
    cin >> s >> n;
    int actual = search(months, s);
    int val = (n + actual) % 12;
    cout << months[val];

    return 0;
}
