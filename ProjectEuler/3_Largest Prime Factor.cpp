#include <bits/stdc++.h>

int main(void) {
    int n = 600851475143;
    int maxFactor = 1;

    // prime factorization
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            maxFactor = max(maxFactor, i);
            n /= i;
        }
    }

    if (n > 1) maxFactor = max(maxFactor, n);

    cout << maxFactor << '\n';
}