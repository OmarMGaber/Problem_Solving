const int N = 3e5 + 5;
// const int N = 0;
int n, q;
int val[N];
int sz[N], par[N], dep[N], id[N], top[N];
 
vector<int> adj[N], values(N);
 
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
 
int dfs_size(const int& node, const int& parent) {
    sz[node] = 1;
    par[node] = parent;
    for (const int& ch : adj[node]) {
        if (ch == parent) continue;
        dep[ch] = dep[node] + 1;
        par[ch] = node;
        sz[node] += dfs_size(ch, node);
    }
    return sz[node];
}
 
int curId = 0;
 
void dfs_hld(const int& cur, const int& parent, const int& curTop) {
    id[cur] = curId++;
    top[cur] = curTop;
 
    values[id[cur]] = val[cur];
 
    int heavyChild = -1, heavyMax = -1;
    for (const int& ch : adj[cur]) {
        if (ch == parent) continue;
        if (sz[ch] > heavyMax) {
            heavyMax = sz[ch];
            heavyChild = ch;
        }
    }
 
    if (heavyChild == -1) return;
    dfs_hld(heavyChild, cur, curTop);
    for (int ch : adj[cur]) {
        if (ch == parent || ch == heavyChild) continue;
 
        dfs_hld(ch, cur, ch);
    }
}
 
int path(int u, int v, int k) {
    int ans = 0;
 
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += mst.query(id[top[u]], id[u], k);
        u = par[top[u]];
    }
 
    if (dep[u] > dep[v]) swap(u, v);
    ans += mst.query(id[u], id[v], k);
 
    return ans;
}
 
void init() {
    mst.init(n);
 
    dep[1] = 1;
    dep[0] = 0;
 
    dfs_size(1, 1);
    dfs_hld(1, 1, 1);
 
    mst.build();
}
 
void finalize() {
    for (int i = 1; i <= n; i++) adj[i].clear();
    curId = 0;
}


int main(void) {
	// read & process input
	
	init(); // don't forget init;
	
	/*
	
		process queries
	
	*/
	
	finalize(); // also don't forget finalize for multiple testcases
	
	return 0;
}