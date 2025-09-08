#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void solve(){
    int k, x; cin >> k >> x;
    while(k--){
        int tmp1, tmp2;
        tmp1 = x * 2;
        tmp2 = (x - 1) / 3;
        if((x - 1) % 3 == 0){
            if(tmp2 % 2 == 0){
                x = tmp1;
            }
            else x = tmp2;
        }
        else x = tmp1;
    }
    cout << x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}