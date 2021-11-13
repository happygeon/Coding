#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int q;
int n, m;
vector<pair<ll, ll>> a, b;
vector<pair<ll, ll>> conva, convb;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (res > 0) return 1;
	if (res)return -1;
	return 0;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

void f(vector<pair<ll, ll>>& v, vector<pair<ll, ll>>& hull) {
	for (auto& i : v) cin >> i.first >> i.second;
	swap(v[0], *min_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
		int cw = ccw(v[0], a, b);
		if (cw) return cw > 0;
		return dist(v[0], a) < dist(v[1], b);
		});
	for (auto i : v) {
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), i) <= 0) hull.pop_back();
		hull.push_back(i);
	}
}

bool chk(pair<ll, ll> now, const vector<pair<ll, ll>>& v) {
	int cnt = 0;
	pair<double, double> ii, jj;
	pair<double, double> q = { now.first, now.second };
	for (int i = 0; i < v.size(); i++) {
		int j = (i + 1) % v.size();
		ii = v[i];
		jj = v[j];
		if ((ii.second > q.second) != (jj.second > q.second)) {
			double first = (jj.first - ii.first) * (q.second - ii.second) / (jj.second - ii.second) + ii.first;
			if (q.first < first) cnt++;
		}
	}
	if (cnt % 2) return true;
	return false;
}

bool crash(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) { // 선분 교차
	int tmp1 = ccw(a, b, c) * ccw(a, b, d);
	int tmp2 = ccw(c, d, a) * ccw(c, d, b);
	if (tmp1 == 0 && tmp2 == 0) {// 일직선상
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		if (c <= b && a <= d)return true;
		return false;
	}
	else if(tmp1 <= 0 && tmp2 <= 0) return true;// 교차 되면 트루
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> q;
	while (q) {
		q--;

		// initalize
		a.clear();
		b.clear();
		conva.clear();
		convb.clear();

		// input
		cin >> n >> m;
		a.resize(n); 
		b.resize(m);
		f(a, conva); 
		f(b, convb);

		bool ans = false;

		// 각각의 conv가 만나는지 확인. 만나면 NO
		// 포함하는 경우도 고려해야함.

		if (chk(conva[0], convb) || chk(convb[0], conva)) ans = true;

		for (auto i : conva) if (chk(i, convb)) ans = true;
		for (auto i : convb) if (chk(i, conva)) ans = true;

		n = conva.size();
		m = convb.size();

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (crash(conva[i], conva[(i + 1) % n], convb[j], convb[(j + 1) % m])) ans = true;
		if (ans) cout << "NO\n";
		else cout << "YES\n";
	}
}