#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[1100];
int vis[1100];
int b[1100];

bool dfs(int node) {
	vis[node] = true;
	for (auto i : v[node]) {
		if (b[i] == 0 || (!vis[b[i]] && dfs(b[i]))) {
			b[i] = node;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 1; j <= tmp; j++) {
			int ttmp;
			cin >> ttmp;
			v[i].push_back(ttmp);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			memset(vis, 0, sizeof vis);
			if (dfs(i))ans++;
		}
	}
	cout << ans;
}