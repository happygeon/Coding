#include<bits/stdc++.h>
using namespace std;

int n, m;
int dp[110][110];
vector<pair<int, int>> arr[110];
int chk[110];
vector<pair<int, int>> ans;

void f(int x) {
	int m = dp[x][0];

	if (arr[x].size() == 0) {
		ans.push_back(make_pair(x, m));
		return;
	}


	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i].first;
		int z = arr[x][i].second;

		dp[y][0] += m * z;
		chk[y]--;

		if(chk[y] == 0)f(arr[x][i].first);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x].push_back(make_pair(y, z));
		chk[y]++;
	}

	dp[n][0] = 1;
	f(n);

	sort(ans.begin(), ans.end());

	for (auto i : ans) {
		cout << i.first << " " << i.second << '\n';
	}
}