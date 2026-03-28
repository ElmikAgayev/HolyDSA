#include <stdio.h>

#define N 100

int main() {
    char a[N + 1] = {0};
    a[1] = 1; //Flag - isNotPrime
    for(int i = 2; i <= N/2; i++) {
        for(int j = 2; j <= N/i; j++) {
            a[i*j] = 1;
        } 
    }

    for(int i = 1; i <= N; i++) {
        if(!a[i]) printf("%4d ", i);
    }
}