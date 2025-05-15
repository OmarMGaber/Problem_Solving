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

void run_test_case() {
    ll mx = 0, cmax = 0;
    char c, last = '-';
    while (cin >> c)
        cmax = (last == c) ? cmax + 1 : 1, mx = max(mx, cmax), last = c;
    cout << mx;
}

int main() {
    InputOutput();

    int TEST_CASES = 1;
//    cin >> TEST_CASES;

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
