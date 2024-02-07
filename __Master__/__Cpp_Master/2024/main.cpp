#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define el '\n'
#define OmarMGaber return 0
#define all(ocate) ocate.begin(), ocate.end()

void InputOutput();
void fastIO();
void fileIO();

template <typename T>
void printStructure(T& arr) {
    for (auto& element : arr) cout << element << ' ';
    cout << '\n';
}

#define TESTCASES
#define int ll
auto run_test_case(int testNum) {
    /*

        Hello World :D

    */
}

int32_t main() {
    // fastIO();
    InputOutput();
    //    fileIO();
    //    cin.ignore();

    int TEST_CASES = 1, testNum = 1;

#ifdef TESTCASES
    cin >> TEST_CASES;
#endif
    for (; testNum <= TEST_CASES;) run_test_case(testNum++);

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