#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
pair<ll, ll> a[1100], b[1100];
vector<pair<ll, ll>> v;
vector<pair<ll, ll>> conv;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (value > 0) return 1;
	if (value) return -1;
	return 0;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	int cw = ccw(v[0], a, b);
	if (cw) return cw > 0;
	return dist(v[0], a) < dist(v[0], b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) v.push_back(make_pair(a[i].first + b[j].first, a[i].second + b[j].second));

	// x, y축으로 정렬 ,v[0]만 사용
	sort(v.begin(), v.end());

	// 각도 정렬ㅍ[0] 빼고
	sort(v.begin() + 1, v.end(), cmp);

	// conv 만만들기
	for (auto i : v) {
		while (conv.size() >= 2 && ccw(conv[conv.size() - 2], conv.back(), i) <= 0) conv.pop_back();
		conv.push_back(i);
	}

	// 출력
	cout << conv.size() << "\n";
	for (auto i : conv) cout << i.first << " " << i.second << "\n";
}