#include <bits/stdc++.h>
#define inf 987654321
#define add 500
using namespace std;

vector<int> adj[1010];
int c[1010][1010], f[1010][1010];
int n, p;

int main() {
	cin >> n >> p;

	for (int i = 1; i <= n; ++i) {
		// 정점 분할, 최대 유량은 1로
		adj[i].push_back(add + i);
		adj[add + i].push_back(i);
		c[i][add + i] = 1;
	}

	for (int i = 0; i < p; ++i) {
		// 입력으로 연결
		int a, b;
		cin >> a >> b;

		adj[add + a].push_back(b);
		adj[b].push_back(add + a);
		c[add + a][b] = 1;

		adj[add + b].push_back(a);
		adj[a].push_back(add + b);
		c[add + b][a] = 1;
	}

	int s = add + 1, e = 2;
	int ans = 0;

	while (1) {
		vector<int> visit(1010, -1);
		queue<int>q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < adj[x].size(); ++i) {
				int y = adj[x][i];
				if (visit[y] == -1 && c[x][y] - f[x][y] > 0) {
					visit[y] = x;
					q.push(y);
					if (y == e) break;
				}
			}
		}

		if (visit[e] == -1) break;

		int flow = inf;
		for (int i = e; i != s; i = visit[i]) flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		for (int i = e; i != s; i = visit[i]) f[visit[i]][i] += flow, f[i][visit[i]] -= flow;

		ans += flow;
	}
	cout << ans;
}