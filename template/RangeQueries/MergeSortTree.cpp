struct Node {
    vector<int> vec;
 
    Node operator+(const Node& a2) {
        Node res;
        int p1 = 0, p2 = 0;
 
        while (p1 < vec.size() && p2 < a2.vec.size()) {
            if (vec[p1] < a2.vec[p2]) {
                res.vec.emplace_back(vec[p1]);
                ++p1;
            }
            else {
                res.vec.emplace_back(a2.vec[p2]);
                ++p2;
            }
        }
 
        while (p1 < vec.size()) {
            res.vec.emplace_back(vec[p1]);
            ++p1;
        }
        while (p2 < a2.vec.size()) {
            res.vec.emplace_back(a2.vec[p2]);
            ++p2;
        }
        return res;
    }
 
    void merge(const Node& a, const Node& b) {
        ranges::merge(a.vec, b.vec, inserter(vec, vec.begin()));
    }
};
 
struct MergeSortTree {
    vector<Node> tree;
    int n{};
 
    void init(int n) {
        this->n = n;
        tree.assign(n * 4, Node{});
    }
 
    void build(const int nd, const int nl, const int nr) {
        if (nl == nr) {
            tree[nd].vec.emplace_back(values[nl]);
            return;
        }
        int mid = nl + (nr - nl) / 2;
        build(2 * nd + 1, nl, mid);
        build(2 * nd + 2, mid + 1, nr);
        tree[nd].merge(tree[2 * nd + 1], tree[2 * nd + 2]);
    }
 
    void build() { build(0, 0, n - 1); }
 
    int query(const int nd, const int nl, const int nr, const int l, const int r, const int value) {
        if (nl > r || nr < l) return 0;
        if (nl >= l && nr <= r) {
            return ranges::upper_bound(tree[nd].vec, value) - tree[nd].vec.begin();
        }
 
        int mid = nl + (nr - nl) / 2;
        return query(2 * nd + 1, nl, mid, l, r, value) + query(2 * nd + 2, mid + 1, nr, l, r, value);
    }
 
    int query(const int& l, const int& r, const int& lb, const int& ub = INT32_MAX) {
        return query(0, 0, n - 1, l, r, ub) - query(0, 0, n - 1, l, r, lb);
    }
} mst;