#include<bits/stdc++.h>
using namespace std;

long long int n;
long long int vis[20];
vector<long long int> fin;
bool e = false;
vector<pair<long long int, long long int>> a, b;

long long int ccw(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c) {
	long long int value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (value > 0)return 1; // 반시계
	else if (value == 0)return 0; // 평행
	else return -1; // 시계
}

bool check(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c, pair<long long int, long long int> d) {
	long long int tmp1 = ccw(a, b, c) * ccw(a, b, d);
	long long int tmp2 = ccw(c, d, a) * ccw(c, d, b);

	if (tmp1 == 0 && tmp2 == 0) { // 일직선상
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		if (c <= b && a <= d)return true;
		return false;
	}
	else if (tmp1 <= 0 && tmp2 <= 0) return true; // 교차 되면 트루
	return false;
}

int main() {
	pair<long long int, long long int> a, b, c, d;
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	if (check(a, b, c, d))cout << 1;
	else cout << 0;

}
