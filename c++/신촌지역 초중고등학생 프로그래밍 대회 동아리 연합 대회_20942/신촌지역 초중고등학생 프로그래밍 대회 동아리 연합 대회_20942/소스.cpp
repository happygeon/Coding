#include<bits/stdc++.h>
#define counting 100100
using namespace std;

int n, m;
vector<pair<int, int>> v[counting][7];
stack<pair<int, int>> st;
vector<pair<int, int>> inv[counting][7];
int bid[counting][7];
int chk[counting][7];
int invchk[counting][7];
int inp[counting];
int inpbit[counting][7];

void dfs(int node, int bit) {
	chk[node][bit] = 1;
	pair<int, int> pu = make_pair(node, bit);
	for (auto i : v[node][bit])if (chk[i.first][i.second] == 0) dfs(i.first, i.second);
	st.push(pu);
}

void invdfs(pair<int, int> node, int idx) {
 	invchk[node.first][node.second] = 1;
	bid[node.first][node.second] = idx;
	for (auto i : inv[node.first][node.second])if (invchk[i.first][i.second] == 0)invdfs(i, idx);
}

void put(pair<int, int> x, pair<int, int> y) {
	x.first += n;
	y.first += n;
	int invx = 2 * n - x.first;
	int invy = 2 * n - y.first;

	v[invx][x.second].push_back(y);
	v[invy][y.second].push_back(x);
	inv[y.first][y.second].push_back(make_pair(invx, x.second));
	inv[x.first][x.second].push_back(make_pair(invy, y.second));
}

void is(pair<int, int> x, int y) {
	if (y == 0)x.first *= -1;
	put(x, x);
}

void and0(pair<int, int> x, pair<int, int> y) {
	x.first *= -1;
	y.first *= -1;
	put(x, y);
}

void and1(pair<int, int> x, pair<int, int> y) {
	put(x, x);
	put(y, y);
}

void or0(pair<int, int> x, pair<int, int> y) {
	x.first *= -1;
	y.first *= -1;
	put(x, x);
	put(y, y);
}

void or1(pair<int, int> x, pair<int, int> y) {
	put(x, y);
}

void init(pair<int, int> x, pair<int, int> y, pair<int, int> z) {// 4 3 2
	y.first *= -1;
	put(x, y);

	y.first *= -1;
	x.first *= -1;
	put(x, y);
	put(x, z);
}

int main() {
	// 입력 미구현

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
		int w = inp[i];
		for (int j = 0; j < 5; j++) {
			if (w % 2 == 1)inpbit[i][j] = 1;
			w >>= 1;
		}
	}
	
	for (int i = 1; i <= 2 * n; i++) {
		if (i == n)continue;
		if (inp[i] != 0)continue;
		pair<int, int> p4 = make_pair(i, 4);
		pair<int, int> p3 = make_pair(i, 3);
		pair<int, int> p2 = make_pair(i, 2);
		init(p4, p3, p2);	
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		char x;
		int y, z, w;
		cin >> x >> y >> z >> w;

		int inparr[5] = {};
		for (int j = 0; j < 5; j++) {
			if (w % 2 == 1)inparr[j] = 1;
			w >>= 1;
		}

		if (inp[z] != 0 && inp[y] != 0) {
			for (int j = 0; j < 5; j++) {
				if (x == '&') {
					if ((inpbit[y][j] & inpbit[z][j]) == inparr[j])continue;
					cout << 0;
					return 0;
				}
				if (x == '|') {
					if ((inpbit[y][j] | inpbit[z][j]) == inparr[j])continue;
					cout << 0;
					return 0;
				}
			}
			continue;
		}
		/*
		else if (inp[y] != 0) {
			for (int j = 0; j < 5; j++) {
				if (x == '&') {
					
				}
				if (x == '|') {
					
				}
			}
			continue;
		}
		*/

		if (x == '&') {
			for (int j = 0; j < 5; j++) {
				if (inparr[j] == 0) {
					and0(make_pair(y, j), make_pair(z, j));
				}
				else {
					and1(make_pair(y, j), make_pair(z, j));
				}
			}
		}
		if (x == '|') {
			for (int j = 0; j < 5; j++) {
				if (inparr[j] == 0) {
					or0(make_pair(y, j), make_pair(z, j));
				}
				else {
					or1(make_pair(y, j), make_pair(z, j));
				}
			}
		}
		
	}

	// 구현 완료
	for (int i = 0; i <= 2 * n; i++) {
		if (i != n) {
			for (int j = 0; j < 5; j++) {
				if (chk[i][j] == 0)dfs(i, j);
			}
		}
	}

	int i = 1;
	while (!st.empty()) {
		pair<int, int> idx = st.top();
		st.pop();
		if (invchk[idx.first][idx.second] == 1)continue;
		invdfs(idx, i);
		i++;
	}

	for (int i = 0; i < n; i++) {
		int x = i;
		int y = 2 * n - i;
		for (int j = 0; j < 5; j++) {
			if (bid[x][j] == bid[y][j]) {
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1 << "\n";

	
	for (int i = n + 1; i <= 2 * n; i++) {
		int x = i;
		int y = 2 * n - i;

		for (int j = 0; j < 5; j++) {
			if (bid[x][j] > bid[y][j]) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	
}