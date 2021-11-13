#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

ll arr[1100000];
pair<ll, ll> seg[4100000];
ll n, m, k, ex = 1;

pair<ll, ll> cmp(pair<ll, ll> a, pair<ll, ll> b) {
	ll arr[4];
	arr[0] = a.first;
	arr[1] = a.second;
	arr[2] = b.first;
	arr[3] = b.second;
	sort(arr, arr + 4);
	return make_pair(arr[3], arr[2]);
}

pair<ll, ll> sum(ll s, ll e, ll node, ll le, ll ri) {
	if (le > e || ri < s) return make_pair(0, 0);
	if (s <= le && ri <= e)return seg[node];

	ll m = (le + ri) / 2;
	node <<= 1;
	return cmp(sum(s, e, node, le, m), sum(s, e, node + 1, m + 1, ri));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (ex < n)ex <<= 1;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int j = ex + i;
		seg[j] = make_pair(arr[i], 0);
		j >>= 1;

		for (; j > 0; j /= 2) {
			seg[j] = cmp(seg[j * 2], seg[j * 2 + 1]);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			y--;

			int j = ex + y;
			seg[j] = make_pair(z, 0);
			j >>= 1;

			for (; j > 0; j /= 2) {
				seg[j] = cmp(seg[j * 2], seg[j * 2 + 1]);
			}
		}
		else {
			y--;
			z--;

			pair<ll, ll> ans = sum(y, z, 1, 0, ex - 1);
			cout << ans.first + ans.second << "\n";
		}
	}
}