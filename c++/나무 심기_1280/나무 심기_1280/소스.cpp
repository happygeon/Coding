#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

ll arr[200100];
ll segsum[1000100];
ll segcnt[1000100];
ll n, ex = 1;

ll sumseg(ll s, ll e, ll node, ll le, ll ri) {
	if (le > e || ri < s) return 0;
	if (s <= le && ri <= e)return segsum[node];

	ll m = (le + ri) / 2;
	node <<= 1;
	return (sumseg(s, e, node, le, m) + sumseg(s, e, node + 1, m + 1, ri)) % mod;
}

ll cntseg(ll s, ll e, ll node, ll le, ll ri) {
	if (le > e || ri < s) return 0;
	if (s <= le && ri <= e)return segcnt[node];

	ll m = (le + ri) / 2;
	node <<= 1;
	return (cntseg(s, e, node, le, m) + cntseg(s, e, node + 1, m + 1, ri)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (ex < 400100)ex <<= 1;
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ll tmp = 0;

		cin >> arr[i];
		ll x = arr[i];
		
		// cal
		tmp -= sumseg(0, x - 1, 1, 0, ex - 1);
		tmp += (x * cntseg(0, x - 1, 1, 0, ex - 1));
		tmp += sumseg(x + 1, ex - 1, 1, 0, ex - 1);
		tmp -= (x * cntseg(x + 1, ex - 1, 1, 0, ex - 1));

		// init
		for (int j = ex + x; j > 0; j /= 2) {
			segsum[j] += x;
			segcnt[j]++;
		}

		if (i > 0) {
			tmp %= mod;
			tmp = (tmp + mod) % mod;
			ans *= tmp;
			ans %= mod;
			ans = (ans + mod) % mod;
			if (tmp < 0 || ans < 0) {
				arr[999999999]++;
			}
		}
	}

	cout << ans << endl;
}