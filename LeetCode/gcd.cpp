#include <stdio.h>

struct fraciton {
    int nominator, denominator;
};

int gcd(int a, int b) {
    while(a > 0) {
        if(a < b) {
            a ^= b; //smart swap
            b ^= a; //
            a ^= b; //
        }
        a %= b;
    }
    return b;
}

int convert() {
    char c;
    int v = 0;
    while((c = getchar()) != ' ' && c != EOF && c != '\n') {
        if('0' <= c && c <= '9') {
            v *= 10;
            v += c - '0';
        }
    } 
    return v;
}

void binary(int n) {
    char t[32] = {0};
    char useful = false;
    for(int i = 0; n; i++) {
        t[i] = n % 2;
        n /= 2;
    }

    printf("0b");
    for(int i = 31; i >= 0; i--) {
        if(t[i]) useful = true;
        if(useful) printf("%d", t[i]);
    }
}

int main(unsigned int argc, const char* argv[]) {
    printf("%d %d %d\n", _CRT_INT_MAX, _CRT_INT_MAX - 1, gcd(_CRT_INT_MAX, _CRT_INT_MAX - 1));
    return 0;
}