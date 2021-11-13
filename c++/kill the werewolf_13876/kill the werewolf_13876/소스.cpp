#include <bits/stdc++.h>
#define inf 2100000000
using namespace std;
int n, m;
int arr[101][2];
int brr[301][301];
vector<int> v[301];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i][0] = a - 1;
		arr[i][1] = b - 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int get = 0;
		bool visit[110] = {};
		int res[110][110] = {};
		int s = 0;
		int x = 105;

		memset(res, 0, sizeof res);
		memset(visit, 0, sizeof visit);

		// 늑대 방문
		visit[i] = 1;

		for (int j = 0; j < n; j++) if (arr[j][0] == i || arr[j][1] == i)get++, visit[j] = 1;

		//1표 이하면 끝
		if (get < 2) {
			ans++;
			continue;
		}

		// 유량 설정
		for (int j = 0; j < n; j++) {
			res[s][j + 1] = get - 1;
			if (arr[i][0] == j || arr[i][1] == j)res[s][j + 1]--;
		}

		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (!visit[j]) {
				res[arr[j][0] + 1][n + j + 1] = 1;
				res[arr[j][1] + 1][n + j + 1] = 1;
				res[n + j + 1][x] = 1;
				tmp++;
			}
		}

		int flow = 0;
		while (1) {
			bool visited[110] = {};
			int from[110];
			memset(from, -1, sizeof(from));

			queue <int> q;
			q.push(s);
			visited[s] = 1;

			int node;

			while (!q.empty()) {
				node = q.front();
				q.pop();

				if (node == x) break;

				for (int i = 0; i < 110; i++) {
					if (res[node][i] > 0 && !visited[i]) {
						q.push(i);
						visited[i] = 1;
						from[i] = node;
					}
				}
			}

			int path_cap = inf;
			for (int node = x, prev = from[node]; from[node] >= 0; node = prev, prev = from[node])path_cap = min(path_cap, res[prev][node]);
			for (int node = x, prev = from[node]; from[node] >= 0; node = prev, prev = from[node])res[prev][node] -= path_cap, res[node][prev] += path_cap;

			if (path_cap == inf) break;
			else flow += path_cap;
		}
		if (flow != tmp)ans++;
	}
	cout << ans;
}