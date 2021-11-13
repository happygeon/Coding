#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, k;
char arr[30][100];
int de[100];
ll dp[1 << 15][200];
int idx = 1;
int ans, all;
ll fu[40];
ll len[40];

ll cnt = 0;

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

void init() {
	de[0] = 1;
	for (int i = 1; i < 100; i++)de[i] = (de[i - 1] * 10) % k;
	for (int i = 0; i < n; i++)idx <<= 1;
	for (int i = 0; i < 1 << 15; i++) for (int j = 0; j < 200; j++) dp[i][j] = -1;
	for (int j = 0; j < n; j++) {
		char* str = arr[j];
		int t = 0;
		for (int kk = 0; kk < strlen(str); kk++) {
			int tmp = str[kk] - '0';
			t *= 10;
			t += tmp;
			t %= k;
		}
		fu[j] = t;
		len[j] = strlen(str);
	}
}

ll f(int bit, int re) {
	ll val = dp[bit][re];
	if (val != -1) return val;

	if (bit == idx - 1) {
		if (re == 0)return 1;
		return 0;
	}

	val = 0;
	for (int i = 1, j = 0; i < idx; i <<= 1, j++) {
		if (bit & i)continue;
		int pa = (re * de[len[j]]) % k;
		pa = (pa + fu[j]) % k;
		if (dp[bit + i][pa] == -1)dp[bit + i][pa] = f(bit + i, pa);
		val += dp[bit + i][pa];
	}
	return val;

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	
	init();

	ll ans = f(0, 0), all = 1;
	for (int i = 1; i <= n; i++) all *= i;

	ll g = gcd(all, ans);
	cout << ans / g << "/" << all / g;

}