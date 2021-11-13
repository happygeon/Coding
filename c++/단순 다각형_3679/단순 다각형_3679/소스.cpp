#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct sibal {
	ll first, second, idx;
	bool operator < (const sibal& t) const {
		return first == t.first ? second < t.second : first < t.first;
	}
};

int ccw(sibal a, sibal b, sibal c) {
	ll res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (res > 0) return 1;
	if (res == 0) return 0;
	return -1;
}

ll dist(sibal a, sibal b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int n;
vector<sibal> arr;

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t;
	while (t) {
		t--;

		cin >> n; arr.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].idx = i;
		}
		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), [&](sibal& a, sibal& b) {
			int cw = ccw(arr[0], a, b);
			if (cw) return cw > 0;
			return dist(arr[0], a) < dist(arr[0], b);
			});
		int pt = arr.size() - 1;
		for (int i = arr.size() - 1; i >= 1; i--) {
			if (ccw(arr[0], arr[pt], arr[pt - 1]) == 0) pt--;
			else break;
		}
		reverse(arr.begin() + pt, arr.end());

		for (auto i : arr) cout << i.idx << " ";
		cout << "\n";
	}
}