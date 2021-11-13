#include<bits/stdc++.h>
using namespace std;

int n;
int chk[3100], cnt[3100];
vector<int> fin;
bool e = false;
vector<pair<int, int>> a, b;
pair< pair<int, int>, pair<int, int>> arr[3100];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (value > 0)return 1; // 반시계
	else if (value == 0)return 0; // 평행
	else return -1; // 시계
}

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int tmp1 = ccw(a, b, c) * ccw(a, b, d);
	int tmp2 = ccw(c, d, a) * ccw(c, d, b);

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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
	}

	int idx = 0;
	vector<int> ans[3100];
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			idx++;
			chk[i] = 1;
			q.push(i);
		}
		while (!q.empty()){
			int tmp = q.front();
			q.pop();
			chk[tmp] = 1;
			ans[idx].push_back(tmp);

			for (int j = 1; j <= n; j++) {
				if (chk[j])continue;
				if (check(arr[tmp].first, arr[tmp].second, arr[j].first, arr[j].second))chk[j] = 1, q.push(j);
			}
		}
	}

	vector<int> out;
	for (int i = 0; i <= n; i++) {
		if (ans[i].size() == 0)continue;
		out.push_back(ans[i].size());
	}
	sort(out.begin(), out.end());
	cout << out.size() << endl;
	cout << out[out.size() - 1];

}
