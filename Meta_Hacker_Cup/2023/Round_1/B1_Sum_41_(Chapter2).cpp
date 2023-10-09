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

template<typename T>
class SparseTable {
private:
    vector<vector<T>> table;

public:
    explicit SparseTable(const vector<T> &arr) {
        int n = arr.size();
        int log_n = static_cast<int>(log2(n)) + 1;

        table.resize(n, vector<T>(log_n));

        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int left, int right) {
        int j = static_cast<int>(log2(right - left + 1));
        return min(table[left][j], table[right - (1 << j) + 1][j]);
    }
};

bool compareBySize(const pair<ll, vector<int>> &a, const pair<ll, vector<int>> &b) {
    if (a.first == b.first)
        return a.second.size() < b.second.size();

    return a.first < b.first;
}

void generateArrays(int targetSum, int currentSum, int start, vector<int> &currentArray,
                    vector<pair<ll, vector<int>>> &result) {
    if (currentSum == targetSum) {
        ll pdt = 1;
        for (int num: currentArray) {
            pdt *= num;
        }
        result.emplace_back(pdt, currentArray);
        return;
    }

    for (int i = start; i <= targetSum - currentSum; i++) {
        currentArray.push_back(i);
        generateArrays(targetSum, currentSum + i, i, currentArray, result);
        currentArray.pop_back();
    }
}

vector<int> currentArray;
vector<pair<ll, vector<int>>> result;

void run_test_case() {
    ll p;
    cin >> p;
    cout << "Case #" << t++ << ": ";
    auto it = lower_bound(result.begin(), result.end(), make_pair(p, vector<int>{}));
    if (it != result.end() && it->first == p) {
        cout << it->second.size() << ' ';
        printStructure(it->second);
    } else {
        cout << -1 << el;
    }
}

int main() {
    InputOutput();
//    cout << fixed;
    generateArrays(41, 0, 1, currentArray, result);
    sort(all(result), compareBySize);

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
