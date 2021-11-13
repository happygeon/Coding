#include<bits/stdc++.h>
#define inf 210000000000000
typedef long long int ll;
using namespace std;

ll n, a, q;
ll arr[120];
ll pri[120];
ll dp[120][120][2];

ll f(ll s, ll e, bool left) {
	if (dp[s][e][left] != -1)return dp[s][e][left];
	if (s == 1 && e == n)return dp[s][e][left] = 0;

	ll ret = inf;
	ll now = e;
	if (!left)now = s;
	ll rem = n - e + s - 1;
	
	if (1 < s) {
		if (dp[s - 1][e][0] == -1)f(s - 1, e, 0);
		ret = min(ret, rem * (pri[now - 1] - pri[s - 2]) + dp[s - 1][e][0]);
	}
	if (n > e) {
		if (dp[s][e + 1][1] == -1)f(s, e + 1, 1);
		ret = min(ret, rem * (pri[e] - pri[now - 1]) + dp[s][e + 1][1]);
	}

	dp[s][e][left] = ret;
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> q;
	while (q){
		q--;
		memset(dp, -1, sizeof dp);

		cin >> n;
		cin >> a;
		for (ll i = 1; i < n; i++) cin >> arr[i];
		pri[1] = arr[1];
		for (ll i = 2; i < n; i++)pri[i] = pri[i - 1] + arr[i];

		cout << min(f(a, a, false), f(a, a, true)) << "\n";

	}

}