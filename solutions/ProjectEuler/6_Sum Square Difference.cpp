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

void run_test_case(const int32_t& testNum) {
    ll n;
    cin >> n;

    ll sumSq = (n * (n + 1) * (2 * n + 1)) / 6;
    ll sqSum = (n * (n + 1) / 2) * (n * (n + 1) / 2);

    cout << sqSum - sumSq << el;
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
