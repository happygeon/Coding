#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[100100];

int d(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool cmpy(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)return true;
	if (a.second == b.second)return a.first < b.first;
	else return false;
}

int f(int s, int e) {
	if (e - s == 2) return d(arr[s], arr[s + 1]);
	if (e - s == 3) return min(min(d(arr[s], arr[s + 1]), d(arr[s], arr[s + 2])), d(arr[s + 2], arr[s + 1]));

	int m = (s + e) / 2;
	int li = (arr[m - 1].first + arr[m].first) / 2;

	int le = f(s, m);
	int ri = f(m, e);
	int mi = min(le, ri);

	vector<pair<int, int>> band;
	for (int i = s; i < e; i++) {
		int tmp = arr[i].first - li;
		if (tmp * tmp < mi) {
			band.push_back(arr[i]);
		}
	}

	sort(band.begin(), band.end(), cmpy);

	for (int i = 0; i < band.size(); i++) {
		for (int j = i + 1; j < band.size() ; j++) {
			if ((band[i].second - band[j].second) * (band[i].second - band[j].second) > mi)break;
			mi = min(mi, d(band[i], band[j]));
		}
	}

	return mi;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	cout << f(0, n);
}