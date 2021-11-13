#include<bits/stdc++.h>
#define counting 10000
using namespace std;

int n, m;
vector<int> v[counting];
stack<int> st;
vector<int> inv[counting];
int bid[counting];
int chk[counting];
int invchk[counting];

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
	int tot = n + m;
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

	for (int i = 0; i < n; i++) {
		char tmp[1100];
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			char ttmp = tmp[j];
			if (ttmp == '.')continue;
			int x = j + 1, y = i + m + 1;

			//cout << x << " " << y << endl;
			x += tot;
			y += tot;
			if (ttmp == '#') y = 2 * tot - y;
			v[2 * tot - x].push_back(y);
			v[2 * tot - y].push_back(x);
			inv[y].push_back(2 * tot - x);
			inv[x].push_back(2 * tot - y);

			v[x].push_back(2 * tot - y);
			v[y].push_back(2 * tot - x);
			inv[2 * tot - y].push_back(x);
			inv[2 * tot - x].push_back(y);
		}
	}
	for (int i = 0; i <= 2 * tot; i++) if (i != tot) if (chk[i] == 0)dfs(i);

	int i = 1;
	while (!st.empty()) {
		int idx = st.top();
		st.pop();
		if (invchk[idx] == 1)continue;
		invdfs(idx, i);
		i++;
	}

	for (int i = 0; i < tot; i++) {
		int x = i;
		int y = 2 * tot - i;
		if (bid[x] == bid[y]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	/*
	for (int i = tot + 1; i <= 2 * tot; i++) {
		int x = i;
		int y = 2 * tot - i;

		if (bid[x] > bid[y]) {
			cout << 0 << " ";
		}
		else {
			cout << 1 << " ";
		}
	}
	*/	

}