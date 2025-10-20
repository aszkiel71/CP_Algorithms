#include <stdio.h>

int main(){
    int arr[9] = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    int r; scanf("%i", &r);
    for(int i = 0; i < 9; i++){
        if(arr[i] > r){
            printf("%i", arr[i]);
            return 0;
        }
    }
}
