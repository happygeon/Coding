#include <bits/stdc++.h>
#define inf 2100000000
using namespace std;
int n, m;
int arr[301][301];
int brr[301][301];
vector<int> v[301];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		arr[a][b] += cost;
		arr[b][a] += cost;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans = 0;
	while (1) {
		int prev[301];
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto i : v[node]) {
				if (prev[i] == -1 && arr[node][i] > brr[node][i]) {
					q.push(i);
					prev[i] = node;
					if (i == n) {
						break;
					}
				}
			}
		}
		if (prev[n] == -1) {
			break;
		}
		int flow = inf;
		for (int i = n; i != 1; i = prev[i]) flow = min(flow, arr[prev[i]][i] - brr[prev[i]][i]);
		for (int i = n; i != 1; i = prev[i]) brr[prev[i]][i] += flow, brr[i][prev[i]] -= flow;
		ans += flow;
	}
	cout << ans;

}