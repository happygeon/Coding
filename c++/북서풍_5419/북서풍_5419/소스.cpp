#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

ll seg[100][80000];
ll n, m, k, ex = 1;

ll sum(int idx, int q) {
	ll ans = 0;
	while (idx) {
		ans += seg[q][idx];
		idx -= idx & (-idx);
	}
	return ans;
}

void update(int idx, int q) {
	while (idx <= n){
		seg[q][idx] ++;
		idx += idx & (-idx);
	}
	return;
}

bool cmp(pair<ll, ll > a, pair<ll, ll > b) {
	if (a.first < b.first)return true;
	else if (a.first == b.first) {
		if (a.second > b.second)return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int query;
	cin >> query;
	while (query){
		query--;
		cin >> n;
		vector<pair<ll, ll>> v;
		vector<ll> zip;
		ll ans = 0;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			zip.push_back(y);
			v.push_back(make_pair(x, y));
		}

		sort(zip.begin(), zip.end());
		zip.erase(unique(zip.begin(), zip.end()), zip.end());

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++) {
			ll x = v[i].first;
			ll y = v[i].second;
			int idx = zip.size() - (lower_bound(zip.begin(), zip.end(), y) - zip.begin());

			ans += sum(idx, query);

			update(idx, query);

		}

		cout << ans << "\n";
	}
}