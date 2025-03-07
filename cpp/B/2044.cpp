#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
      string a;
      cin>>a;
      reverse(a.begin(),a.end());
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'p')
            {
                a[i] = 'q';
            }
            else if (a[i] == 'q')
            {
                a[i] = 'p';
            }
        }
        cout<<a<<"\n";
    }
    return 0;
}
