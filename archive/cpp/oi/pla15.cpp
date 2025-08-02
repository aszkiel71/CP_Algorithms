#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        int d, h;
        cin >> d >> h;
        heights[i] = h;
    }

    stack<int> S;
    int posters = 0;
    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && S.top() > heights[i])
        {
            S.pop(); //wyzsze budynki niz te obecne
        }
        if (S.empty() || S.top() < heights[i]) //sprawdza czy ma unikalna wartosc
        {
            S.push(heights[i]);  //dodajemy nowy plakat
            posters++;
        }

    }
    cout << posters<< endl;
    return 0;
}
