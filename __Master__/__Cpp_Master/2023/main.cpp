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

//#define TESTCASES
int run_test_case(int testNum) {

    cout << testNum << el;

    return INT_MAX;
}

int main() {
    InputOutput();

    int TEST_CASES = 1, testNum = 1;

#ifdef TESTCASES
    cin >> TEST_CASES;
#endif

    for (; testNum <= TEST_CASES;)
        run_test_case(testNum++);

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
