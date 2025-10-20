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

void solve(){
    int n, cnt_s = 0, cnt_p = 0; string s; cin >> n >> s;
    // p przed s -> false
    // nie ma 's' -> true
    /*bool b1 = 1;
    for(char c : s) {
        cnt_s += c == 's';
        cnt_p += c == 'p';
    }

    for(char c : s){
        if(c == 's'){
            b1 = 0;
            break;
        }
    }
    if(b1){
        cout << "YES\n";
        return;
    }
    int first_p = -1, last_s = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'p'){
            if(first_p == -1) first_p = i;
        }
        else if(s[i] == 's'){
            last_s = i;
        }
    }
    if(first_p < last_s){
        cout << "NO\n";
        return;
    }
    else{
        cout << "YES\n";
    }*/

    if(s[0] == 's') s[0] = '.';
    if(s[n-1] == 'p') s[n-1] = '.';
    bool b1 = 0, b2 = 0;
    for(char c : s){
        if(!b1) b1 = c == 's';
        if(!b2) b2 = c == 'p';
    }
    cout << (!(b1 && b2) ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        //debug(t);
        solve();
    }
}
