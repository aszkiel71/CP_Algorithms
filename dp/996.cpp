#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int res1 = n/100;
    n -= res1*100;
    int res2 = n/20;
    n -= res2*20;
    int res3 = n/10;
    n -= res3*10;
    int res4 = n/5;
    n -= res4*5;
    cout << res1 + res2 + res3 + res4 + n;
}
