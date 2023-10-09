#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define el '\n'
#define OmarMGaber return 0
#define all(ocate) ocate.begin(), ocate.end()

void InputOutput();

void fileIO();

template<typename T>
void printStructure(T &arr) {
    for (auto &element: arr) cout << element << ' ';
    cout << '\n';
}

short test_case = 1;

int run_test_case() {

    int s, d, k;
    cin >> s >> d >> k;

    while (s && d) {
        k -= 3;
        d--;
        s--;
    }
    while (s > 0) {
        k -= 2;
        s -= 2;
    }

    while (d > 0) {
        k -= 3;
        d -= 2;
    }
    if (k <= 0)
        cout << "Case #" << test_case++ << ": YES" << el;
    else
        cout << "Case #" << test_case++ << ": NO" << el;

    return 0;
}

int main() {
    InputOutput();

    int TEST_CASES = 1;
    cin >> TEST_CASES;

    while (TEST_CASES--)
        run_test_case();

    OmarMGaber;
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void fileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void InputOutput() {
    fastIO();
#ifndef ONLINE_JUDGE
    fileIO();
#endif
}
