#include<bits/stdc++.h>
#define inf 100000
using namespace std;

int V, E, dfsn[inf + 1];
vector<int> adj[inf + 1];
set<pair<int, int>> ans;
int cnt = 1;
int dfs(int node, int par) {
	dfsn[node] = cnt;
	cnt++;
	// �ö� �� �ִ� �ִ� dfsn  
	int ret = dfsn[node];
	for (auto child : adj[node]) {
		// �ٷ� �������� �� ���� ���ƺ��� �ʴ´�. 
		if (child == par) continue;
		if (dfsn[child]) {
			ret = min(ret, dfsn[child]);
			continue;
		}
		int prev = dfs(child, node);
		// par �� ���� ���� ���� ���� ������ prev = dfsn[node] �� ��� cycle �� ����� 
		if (prev > dfsn[node]) {
			int a = min(node, child);
			int b = max(node, child);
			if (!ans.count(pair<int, int>(a, b)))
				ans.insert(pair<int, int>(a, b));
		}
		ret = min(ret, prev);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> V >> E;
	if (V == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < E; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// root �� par �� 0���� ���� 
	for (int i = 1; i <= V; ++i) if (dfsn[i] == 0) dfs(i, 0);

	cout << ans.size() + 1 << '\n';
	for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
	
}