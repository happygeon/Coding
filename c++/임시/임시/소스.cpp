#include<bits/stdc++.h>
using namespace std;

int n;
pair<double, double> gam;
vector<pair<double, double>> arr[2000];

int ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
	double value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (value > 0)return 1; // 반시계
	else if (value == 0)return 0; // 평행
	else return -1; // 시계
}

bool cmp(pair<double, double> a, pair<double, double> b) {// 각도로 정렬
	pair<double, double> tmp = make_pair(0, 0);
	int chk = ccw(tmp, a, b);
	if (chk == 0)return (a.first * a.first + a.second * a.second) <= (b.first * b.first + b.second + b.second);
	return chk == 1;
}

bool cmp2(pair<double, double> a, pair<double, double> b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
	cin >> n;
	cin >> gam.first >> gam.second;
	for (int i = 0; i < n; i++) {
		pair<double, double> tmp;
		cin >> tmp.first >> tmp.second;
		arr[0].push_back(tmp);
	}

	int ans;
	for (ans = 0; arr[ans].size() >= 3; ans++) {
		sort(arr[ans].begin(), arr[ans].end(), cmp2);

		pair<double, double> gamtmp = gam;
		gam.first -= arr[ans][0].first;
		gam.second -= arr[ans][0].second;
		for (int i = 1; i < arr[ans].size(); i++) {
			arr[ans][i].first -= arr[ans][0].first;
			arr[ans][i].second -= arr[ans][0].second;
		}
		arr[ans][0] = make_pair(0, 0);
		sort(arr[ans].begin() + 1, arr[ans].end(), cmp); // 기준이 되는 arr[0]을 제외하고 정렬, 반시계로 각도 정렬

		//for (auto i : arr[ans])cout << i.first << " " << i.second << endl;

		vector<pair<double, double>> conv;
		for (int i = 0; i < arr[ans].size(); i++) {
			while (conv.size() >= 2 && ccw(conv[conv.size() - 2], conv[conv.size() - 1], arr[ans][i]) <= 0) {
				arr[ans + 1].push_back(conv[conv.size() - 1]);
				conv.pop_back();
			}
			conv.push_back(arr[ans][i]);
		}
		//cout << endl << endl;
		//for (auto i : conv)cout << i.first << " " << i.second << endl;
		//cout << gam.first << " " <<  gam.second << endl;
		//cout << endl << endl;

		// 감옥이 안에있는지 확인.

		int chk = ccw(conv[conv.size() - 1], conv[0], gam);
		for (int i = 0; i < conv.size() - 1; i++) {
			//cout << ccw(conv[i - 1], conv[i], gamtmp) << endl;
			if (chk == ccw(conv[i], conv[i + 1], gam)) continue;
			cout << ans;
			return 0;

		}
	}
	cout << ans;
}
