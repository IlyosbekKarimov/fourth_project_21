#include <stdio.h>

int divisor(int a, int b);
int modulo(int a, int b);
int prime_divisor(int n);
int isPrime(int n);

int main() {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a");
        return 0;
    }
    if (a < 0) {
        a = -a;
    }
    printf("%d", prime_divisor(a));
    return 0;
}

int divisor(int a, int b) {
    int k = 0;
    while (a >= b) {
        a -= b;
        k++;
    }
    return k;
}

int modulo(int a, int b) {
    int qoldiq = a;
    while (qoldiq >= b) {
        qoldiq -= b;
    }
    return qoldiq;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (modulo(n, i) == 0) {
            return 0;
        }
    }
    return 1;
}

int prime_divisor(int n) {
    int largestDivisor = -1;
    for (int i = 2; i * i <= n; i++) {
        if (modulo(n, i) == 0) {
            if (isPrime(i)) {
                largestDivisor = i;
            }
            int otherDivisor = divisor(n, i);
            if (isPrime(otherDivisor) && otherDivisor > largestDivisor) {
                largestDivisor = otherDivisor;
            }
        }
    }
    return largestDivisor;
}