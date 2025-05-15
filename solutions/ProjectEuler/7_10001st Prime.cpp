#include <bits/stdc++.h>

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx", "avx2", "fma")

using namespace std;
typedef long long ll;

#define el          "\n"
#define OmarMGaber  return 0;
#define all(ocate)  ocate.begin(), ocate.end()
#define fastIO      ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define deb(x)      cout << "Line(" << __LINE__ << "): " << #x << " := " << x << el;
#define TIME(stmts) { auto start = chrono::high_resolution_clock::now(); { stmts; } auto stop = chrono::high_resolution_clock::now(); cerr << "Time test case(" << testNum - 1 << "): " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << " micro seconds" << el; }

constexpr int N = 1e7;
bool isPrime[N];

void run_test_case(const int32_t& testNum) {
    // apply sieve
    int idx;
    cin >> idx;
    memset(isPrime, true, sizeof isPrime);

    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 4; i < N; i += 2) {
        isPrime[i] = false;
    }

    for (int i = 3; i * i < N; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; ++i) {
        idx -= isPrime[i];
        if (idx == 0) {
            cout << i << el;
            break;
        }
    }
}

int32_t main() {
    auto ssss = chrono::high_resolution_clock::now();
    fastIO

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cout << fixed << setprecision(20);

    int TEST_CASES = 1, testNum = 1;
    // cin >> TEST_CASES;

    while (testNum <= TEST_CASES)
        run_test_case(testNum++);


    auto eeee = chrono::high_resolution_clock::now();
    cerr << "Total time: " << chrono::duration_cast<chrono::seconds>(eeee - ssss).
        count() << " seconds" << el;
    OmarMGaber;
}
