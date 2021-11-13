#include <bits/stdc++.h>
#define pi 3.14159265358979
using namespace std;
typedef long long ll;
ll l, n;
vector<pair<ll, ll>> v, conv;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (value > 0) return 1;
	if (value) return -1;
	return 0;
}

double dist(pair<ll, ll> a, pair<ll, ll> b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

ll dot(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first * b.first + a.second * b.second;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	int cw = ccw(v[0], a, b);
	if (cw) return cw > 0;
	return dist(v[0], a) < dist(v[0], b);
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		pair<ll, ll> tmp;
		cin >> tmp.first >> tmp.second;
		v.push_back(tmp);
	}

	// conv ¸¸µé±â
	sort(v.begin(), v.end());
	sort(v.begin() + 1, v.end(), cmp);

	for (auto i : v) {
		while (conv.size() >= 2 && ccw(conv[conv.size() - 2], conv.back(), i) <= 0) conv.pop_back();
		conv.push_back(i);
	}

	double ans = 0;
	n = conv.size();
	for (int i = 0; i < n; i++) ans += dist(conv[i], conv[(i + 1) % n]);
	ans += 2 * pi * l;

	printf("%.0lf", ans);
}