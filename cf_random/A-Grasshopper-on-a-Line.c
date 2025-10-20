#include <stdio.h>

void solve(){
    int x, k; scanf("%i%i", &x, &k);
    if(x % k){
        printf("1\n");
        printf("%i\n", x);
    }
    else{
        printf("2\n");
        printf("%i %i\n", 1, x-1);
    }
}

int main(){
    int t; scanf("%i", &t);
    while(t--){
        solve();
    }
}
