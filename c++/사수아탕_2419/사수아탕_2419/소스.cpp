#include<bits/stdc++.h>
#define inf 2147483647
typedef long long int ll;
using namespace std;

ll n, m, x;
ll arr[400];
ll dp[400][400][2];

ll f(ll s, ll e, bool left, ll k) { // ������� ������ ���. ������°� �ּ�min�� �Ǿ�� ��.
	if (k == 0)return dp[s][e][left] = 0; // ���� ���ڰ� 0���̸�
	if (e < s)return inf; // �Ұ����� ���
	if (dp[s][e][left] != -1)return dp[s][e][left]; // �̹� ���ѰŶ��

	ll ret = inf;
	if (left) {
		if (e < n) { // ���������� �� �� ������ ��
			if (dp[s][e + 1][0] == -1)f(s, e + 1, 0, k - 1);
			ret = min(ret, dp[s][e + 1][0] + k * (arr[e + 1] - arr[s]));// �����ʿ��� �������� �̵�
		}
		if (s > 0) {// �������� �� �� ������
			if (dp[s - 1][e][1] == -1)f(s - 1, e, 1, k - 1);
			ret = min(ret, dp[s - 1][e][1] + k * (arr[s] - arr[s - 1]));// ���ʿ��� ��ĭ �� �������� �̵�
		}
	}
	else {
		if (e < n) { // ���������� �� �� ������ ��
			if (dp[s][e + 1][0] == -1)f(s, e + 1, 0, k - 1);
			ret = min(ret, dp[s][e + 1][0] + k * (arr[e + 1] - arr[e]));// �����ʿ��� �������� �̵�
		}
		if (s > 0) {// �������� �� �� ������
			if (dp[s - 1][e][1] == -1)f(s - 1, e, 1, k - 1);
			ret = min(ret, dp[s - 1][e][1] + k * (arr[e] - arr[s - 1]));// ���ʿ��� ��ĭ �� �������� �̵�
		}
	}

	dp[s][e][left] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> arr[i];

	// ����. arr[1]����, arr[0]�� 0
	sort(arr, arr + n + 1);

	// 0���� �̵�
	ll idx = lower_bound(arr, arr + n, 0) - arr;
	ll ans = 0;
	for (ll k = 0; k <= n; k++) {
		memset(dp, -1, sizeof dp);
		//cout << k * m - f(idx, idx, 0, k) << endl;
		ans = max(ans, k * m - f(idx, idx, 0, k));
	}

	cout << ans;
}