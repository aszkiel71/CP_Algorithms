#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

bool validator(char c){
    bool b1=0, b2=0, b3=0, b4=0, b5=0, b6=0, b7=0;
    b1 += (c == 'c');
    b2 += (c == 'o');
    b3 += (c == 'd');
    b4 += (c == 'e');
    b5 += (c == 'f');
    b6 += (c == 'r');
    b7 += (c == 's');
    return b1 || b2 || b3 || b4 || b5 || b6 || b7;
}

void solve(){
    char c; cin >> c;
    if(validator(c)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
