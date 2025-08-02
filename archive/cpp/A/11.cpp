#include <iostream>

using namespace std;

//dynamic programming

int main() {
    int n, d;
    cin >> n >> d;
    int counter = 0;
    int a;
    cin >> a;
    int tmp;
    for (int i = 0; i < n-1; i++) {
        cin >> tmp;
        while (a >= tmp)
        {
            tmp += d;
            counter++;
        }
        a = tmp;
    }

    cout << counter;


    return 0;
}
