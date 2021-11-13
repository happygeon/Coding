#include<bits/stdc++.h>
#define counting 200200
using namespace std;

int n, m;
vector<int> v[counting];
stack<int> st;
vector<int> inv[counting];
int bid[counting];
int chk[counting];
int invchk[counting];
int room[counting];
vector<int> swi[counting];

void dfs(int node) {
	chk[node] = 1;
	for (auto i : v[node])if (chk[i] == 0)dfs(i);
	st.push(node);
}

void invdfs(int node, int idx) {
	invchk[node] = 1;
	bid[node] = idx;
	for (auto i : inv[node])if (invchk[i] == 0)invdfs(i, idx);
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> room[i];
	/*
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x += n;
		y += n;
		v[2 * n - x].push_back(y);
		v[2 * n - y].push_back(x);
		inv[y].push_back(2 * n - x);
		inv[x].push_back(2 * n - y);
	}
	*/
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int tmp;
			cin >> tmp;
			tmp--;
			swi[tmp].push_back(i);
		}
	}

	for (int i = 0; i < m; i++) {
		int x = swi[i][0];
		int y = swi[i][1];
		x += n;
		y += n;

		if (room[i] == 1)y = 2 * n - y;

		v[2 * n - x].push_back(y);
		v[2 * n - y].push_back(x);
		inv[y].push_back(2 * n - x);
		inv[x].push_back(2 * n - y);

		v[x].push_back(2 * n - y);
		v[y].push_back(2 * n - x);
		inv[2 * n - y].push_back(x);
		inv[2 * n - x].push_back(y);
	}

	for (int i = 0; i <= 2 * n; i++) if (i != n) if (chk[i] == 0)dfs(i);

	int i = 1;
	while (!st.empty()) {
		int idx = st.top();
		st.pop();
		if (invchk[idx] == 1)continue;
		invdfs(idx, i);
		i++;
	}

	for (int i = 0; i < n; i++) {
		int x = i;
		int y = 2 * n - i;
		if (bid[x] == bid[y]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;


}