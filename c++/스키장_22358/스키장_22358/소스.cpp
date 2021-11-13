#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, m, k, s, t;
ll ans;
ll dp[15][100100];
vector<pair<int, int>> v[100100];

int main() {

	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back(make_pair(b, t));
		v[b].push_back(make_pair(a, -1));
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][s] = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			ll tmp = dp[i][j];
			if (tmp == -1)continue;
			for (auto x : v[j]) {
				if (x.second == -1) {
					dp[i + 1][x.first] = max(dp[i + 1][x.first], tmp);
				}
				else {
					dp[i][x.first] = max(dp[i][x.first], tmp + x.second);
				}
			}
		}
	}

	cout << dp[k][t];
}