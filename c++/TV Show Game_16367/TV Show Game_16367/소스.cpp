#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[30000];
stack<int> st;
vector<int> inv[30000];
int bid[30000];
int chk[30000];
int invchk[30000];

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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		char a, b, c;
		cin >> x >> a >> y >> b >> z >> c;
		x += n;
		y += n;
		z += n;

		if (a == 'R') x = (2 * n) - x;
		if (b == 'R') y = (2 * n) - y;
		if (c == 'R') z = (2 * n) - z;


		v[2 * n - x].push_back(y);
		v[2 * n - y].push_back(x);
		inv[y].push_back(2 * n - x);
		inv[x].push_back(2 * n - y);

		v[2 * n - z].push_back(y);
		v[2 * n - y].push_back(z);
		inv[y].push_back(2 * n - z);
		inv[z].push_back(2 * n - y);

		v[2 * n - x].push_back(z);
		v[2 * n - z].push_back(x);
		inv[z].push_back(2 * n - x);
		inv[x].push_back(2 * n - z);
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
			cout << -1;
			return 0;
		}
	}

	for (int i = n + 1; i <= 2 * n; i++) {
		int x = i;
		int y = 2 * n - i;

		if (bid[x] > bid[y]) {
			cout << 'B';
		}
		else {
			cout << 'R';
		}
	}

}