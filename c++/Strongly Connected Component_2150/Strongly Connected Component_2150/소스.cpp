#include<bits/stdc++.h>
using namespace std;

int v, e;
int vis[10100];
int rvis[10100];
vector<int> arr[10100];
vector<int> rev[10100];
stack<int> st;
vector<int> ans[10100];

void dfs(int node) {
	vis[node] = 1;
	

	for (int i = 0; i < arr[node].size(); i++) {
		if (vis[arr[node][i]] == 0)dfs(arr[node][i]);
	}

	st.push(node);
}

void rdfs(int node, int idx) {
	rvis[node] = 1;
	ans[idx].push_back(node);
	for (int i = 0; i < rev[node].size(); i++) {
		if (rvis[rev[node][i]] == 0)rdfs(rev[node][i], idx);
	}
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		rev[y].push_back(x);
	}

	for (int i = 1; i <= v; i++) {
		if (vis[i] == 0)dfs(i);
	}

	int idx = 0;
	while (!st.empty()){
		int i = st.top();
		st.pop();
		if (rvis[i] == 0) {
			rdfs(i, idx);
			idx++;
		}
	}

	cout << idx << endl;
	for (int i = 0; i < idx; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans, ans + idx);
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < ans[i].size(); j++)printf("%d ", ans[i][j]);
		printf("-1\n");
	}
}