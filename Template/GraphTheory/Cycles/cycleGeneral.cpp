// general algorithm for both directed and undirected
bool cyc[NODES_SIZE];

bool dfs(const int& node, const int& par) {
    bool ans = false;
    
	vis[node] = cyc[node] = true;
	
    for (auto &ch : adj[node]) {
        if (par == ch) continue;
        if (!vis[ch]) ans |= dfs(ch, node);
        else if (cyc[ch]) ans = true;
    }
	
    cyc[node] = false;
    return ans;
}