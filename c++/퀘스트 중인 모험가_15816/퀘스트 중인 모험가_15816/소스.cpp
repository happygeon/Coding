#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[2000100];
int bit[2000100];
int sav[2000100][3];
int si;
vector<int> v;

void up(int i) {
	while (i <= si){
		bit[i]++;
		i += i & (-i);
	}
}


int sum(int i) {
	int ret = 0;
	while (i) {
		ret += bit[i];
		i -= i & (-i);
	}
	return ret;
}

int l(int idx) {
	return lower_bound(v.begin(), v.end(), idx) - v.begin() + 2;
}

int u(int idx) {
	return upper_bound(v.begin(), v.end(), idx) - v.begin() + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> sav[i][0] >> sav[i][1];
		if (sav[i][0] == 2) cin >> sav[i][2];
		else v.push_back(sav[i][1]);
	}

	// 압축
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	si = v.size() + 2;

	// 초기화
	for (int i = 0; i < n; i++) up(l(arr[i]));

	// 실행
	for (int i = 0; i < m; i++) {
		int tmp = l(sav[i][1]);
		if (sav[i][0] == 2) {
			int all = sav[i][2] - sav[i][1] + 1;
			int s = sum(u(sav[i][2])) - sum(tmp - 1);
			cout << all - s << '\n';
		}
		else up(tmp);
	}

}