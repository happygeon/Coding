#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

int n, ex = 1;
int arr[3][500100];
int seg[1200100];
pair<int, pair<int, int>> ta[500100];

int cmp(int a, int b) {
	if (a == 0)return b;
	if (b == 0) return a;
	return a < b ? a : b;
}

int findm(int s, int e, int node, int le, int ri) {
	if (le > e || ri < s)return 0;
	if (s <= le && ri <= e) return seg[node];

	int m = (le + ri) / 2;
	return cmp(findm(s, e, node * 2, le, m), findm(s, e, node * 2 + 1, m + 1, ri));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (ex < n) ex <<= 1;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			tmp--;
			arr[k][tmp] = i;
		}
	}
	
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp = make_pair(arr[1][i], arr[2][i]);
		pair<int, pair<int, int>> ttmp = make_pair(arr[0][i], tmp);
		ta[i] = ttmp;
	}

	sort(ta, ta + n);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp = ta[i].second;
		int se = tmp.first;
		int th = tmp.second + 1;

		int m = findm(0, se - 1, 1, 0, ex - 1);
		if (m == 0 || th < m) ans++;

		int j = ex + se;
		seg[j] = th;
		j /= 2;
		for (;  j > 0; j /= 2) {
			seg[j] = cmp(seg[j * 2], seg[j * 2 + 1]);
		}
	}


	cout << ans;

}