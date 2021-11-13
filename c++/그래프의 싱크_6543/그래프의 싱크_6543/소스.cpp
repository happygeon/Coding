#include<bits/stdc++.h>
using namespace std;

int n, m;
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
	cin >> n;
	while (n != 0){
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			arr[x].push_back(y);
			rev[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0)dfs(i);
		}

		int idx = 0;
		while (!st.empty()) {
			int i = st.top();
			st.pop();
			if (rvis[i] == 0) {
				rdfs(i, idx);
				idx++;
			}
		}

		int chk[10100] = {};
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				int tmp = ans[i][j];
				chk[tmp] = i + 1;
			}
		}

		int chk2[10100] = {};
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				if (chk[arr[i][j]] != chk[i]) {
					chk2[chk[i]] = 1;
				}
			}
		}

		/*
		for (int i = 0; i < 10; i++) {
			cout << chk2[i] << endl;
		}
		*/
		vector<int>fi;
		for (int i = 0; i < idx; i++) {
			if (chk2[i + 1] != 0)continue;
			for (int j = 0; j < ans[i].size(); j++) {
				fi.push_back(ans[i][j]);
			}
		}
		sort(fi.begin(), fi.end());
		for (int i = 0; i < fi.size(); i++) {
			printf("%d ", fi[i]);
		}
		cout << endl;

		cin >> n;
		
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			rvis[i] = 0;
			arr[i].resize(0);
			rev[i].resize(0);
			ans[i].resize(0);
		}

	}
}