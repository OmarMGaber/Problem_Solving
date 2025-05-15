// undirected graphs only
bool dfs(const int& node, const int& par) {
	bool ans = false;
    vis[node] = true;
	
    for (auto &ch : adj[node]) {
        if (!vis[ch]) ans |= dfs(ch, node);
        else if (par != ch) ans = true;
    }
	
    return ans;
}