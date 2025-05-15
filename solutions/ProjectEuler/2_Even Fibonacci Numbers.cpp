#include <bits/stdc++.h>

int main(void) {
    int MAX = 4e6;
    int l = 1, r = 2;
    int sum = 2;

    while (r <= MAX) {
        int next = l + r;
        if (next < MAX && next % 2 == 0) sum += next;
        l = r;
        r = next;
    }

    cout << sum << el;
}