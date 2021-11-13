#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

ll arr[1100000];
ll seg[4100000];
ll n, m, k, ex = 1;

ll inv(ll a) {
	ll idx = mod - 2, ret = 1, tmp = a;
	while (idx){
		if (idx % 2 == 1) ret = (ret * tmp) % mod;
		idx >>= 1;
		tmp = (tmp * tmp) % mod;
	}

	return ret;
}

ll sum(ll s, ll e, ll node, ll le, ll ri) {
	if (le > e || ri < s) return 1;
	if (s <= le && ri <= e)return seg[node];

	ll m = (le + ri) / 2;
	node <<= 1;
	return (sum(s, e, node, le, m) * sum(s, e, node + 1, m + 1, ri)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	while (ex < n)ex <<= 1;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < 2 * ex; i++)seg[i] = 1;

	for (int i = 0; i < n; i++) for (int j = ex + i; j > 0; j /= 2) seg[j] = (seg[j] * arr[i]) % mod;

	for (int i = 0; i < m + k; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			y--;

			seg[ex + y] = z;
			for (int i = (ex + y) / 2; i > 0; i /= 2) seg[i] = (seg[i * 2] * seg[i * 2 + 1]) % mod;


			//ll tmp = (inv(arr[y]) * z) % mod;
			//for (int i = ex + y; i > 0; i /= 2)	seg[i] = (seg[i] * tmp) % mod;
			
		}
		else {
			ll ans = sum(y - 1, z - 1, 1, 0, ex - 1);
			cout << ans << "\n";
		}
	}
}