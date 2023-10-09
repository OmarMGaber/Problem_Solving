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
