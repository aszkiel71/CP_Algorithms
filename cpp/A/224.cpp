#include <iostream>

using namespace std;

int main() {
    int p1, p2, p3;
    cin>>p1>>p2>>p3;
    float a = 1, b = p1, c = p3/p1;
    // a * b = p1
    // a * c = p2
    // b * c = p3
    // find int a, b, c
    while (true)
    {
        if (a == int(a) && b == int(b) && c == int(c) && int(a*b) == p1 && int(a*c == p2) && int(b*c) == p3)
        {
            break;
        }
        a += 1;
        b = p1/a;
        c = p3/b;
    }
    cout << (4*a + 4*b + 4*c);
    return 0;
}
