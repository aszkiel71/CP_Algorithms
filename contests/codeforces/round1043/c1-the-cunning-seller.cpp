#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // 1 watermelon -> 3 coinsy
        // 3 watermelony -> 10 coinsow
        // 9 watermelonow ->
        vector<int> trojeczka(30);
        int i = 29;
        while(n > 0){
            trojeczka[i] = n % 3;
            n /= 3;
            i--;
        }
        long long cena;
        vector<long long> potegi3(20);
        potegi3[0] = 1;
        for(int j = 1; j < 20; j++)
            potegi3[j] = potegi3[j - 1] * 3;

        vector<long long> ceny(20);
        ceny[0] = 3; // 3^0 watermelonow
        for (int j = 1; j < 19; j++){
            ceny[j] = potegi3[j + 1] + j * potegi3[j - 1];
        }
        long long res = 0;
        for(int j = 0; j < 30; j++){
            if(trojeczka[j] == 0) continue;
            int power = 29 - j;
            res += (long long)trojeczka[j] * ceny[power];
        }
        cout << res << "\n";
    }

}
