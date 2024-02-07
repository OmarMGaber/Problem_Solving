template <typename T>
class SparseTable {
private:
    vector<vector<pair<int, T>>> minTable;
    vector<vector<pair<int, T>>> maxTable;

public:
    explicit SparseTable(const vector<T>& arr) {
        int n = arr.size();
        int log_n = static_cast<int>(log2(n)) + 1;

        minTable.resize(n, vector<pair<int, T>>(log_n));
        maxTable.resize(n, vector<pair<int, T>>(log_n));

        for (int i = 0; i < n; i++) {
            minTable[i][0].second = arr[i];
            minTable[i][0].first = i;

            maxTable[i][0].second = arr[i];
            maxTable[i][0].first = i;
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                if (minTable[i][j - 1].second <
                    minTable[i + (1 << (j - 1))][j - 1].second) {
                    minTable[i][j].second = minTable[i][j - 1].second;
                    minTable[i][j].first = minTable[i][j - 1].first;
                } else {
                    minTable[i][j].second =
                        minTable[i + (1 << (j - 1))][j - 1].second;
                    minTable[i][j].first =
                        minTable[i + (1 << (j - 1))][j - 1].first;
                }

                if (maxTable[i][j - 1].second >
                    maxTable[i + (1 << (j - 1))][j - 1].second) {
                    maxTable[i][j].second = maxTable[i][j - 1].second;
                    maxTable[i][j].first = maxTable[i][j - 1].first;
                } else {
                    maxTable[i][j].second =
                        maxTable[i + (1 << (j - 1))][j - 1].second;
                    maxTable[i][j].first =
                        maxTable[i + (1 << (j - 1))][j - 1].first;
                }
            }
        }
    }

    pair<int, T> queryMin(int left, int right) {
        int j = static_cast<int>(log2(right - left + 1));
        if (minTable[left][j].second <=
            minTable[right - (1 << j) + 1][j].second) {
            return minTable[left][j];
        } else {
            return minTable[right - (1 << j) + 1][j];
        }
    }

    pair<int, T> queryMax(int left, int right) {
        int j = static_cast<int>(log2(right - left + 1));
        if (maxTable[left][j].second >=
            maxTable[right - (1 << j) + 1][j].second) {
            return maxTable[left][j];
        } else {
            return maxTable[right - (1 << j) + 1][j];
        }
    }
};