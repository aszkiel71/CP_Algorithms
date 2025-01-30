#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp = 0;
    bool is_triangular = false;
    while (n >= tmp*(tmp+1)/2)
    {
        if (tmp*(tmp+1)/2 == n)
            is_triangular = true;
        tmp++;
    }
    if (is_triangular)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
