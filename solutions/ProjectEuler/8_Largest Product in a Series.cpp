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

static const string digits =
    "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

void run_test_case(const int32_t& testNum) {
    int windowSize;
    cin >> windowSize;

    const int len = digits.size();
    int l = 0, r = 0;
    ll bestAns = 0, curValue = 1;
    // sliding window
    while (r <= len - windowSize) {
        while (r - l < windowSize) {
            if (digits[r] == '0') {
                while (r < len && digits[r] == '0') {
                    ++r;
                }
                l = r;
                curValue = 1;
            }
            curValue *= (digits[r] - '0');
            ++r;
        }

        bestAns = max(bestAns, curValue);
        curValue /= (digits[l] - '0');
        ++l;
    }

    // naive approach
    ll bestAns2 = 0;
    for (int i = 0; i + windowSize < len; ++i) {
        curValue = 1;
        for (int j = i; j < i + windowSize; ++j) {
            curValue *= (digits[j] - '0');
        }

        bestAns2 = max(bestAns2, curValue);
    }

    cout << bestAns << " " << bestAns2 << el;
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
