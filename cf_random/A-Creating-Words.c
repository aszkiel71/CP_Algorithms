#include <stdio.h>

void solve(){
    char a[4], b[4]; scanf("%s%s", &a, &b);
    printf("%c%c%c %c%c%c\n", b[0], a[1], a[2], a[0], b[1], b[2]);
}

int main(){
    int t; scanf("%i", &t);
    while(t--) solve();
}
