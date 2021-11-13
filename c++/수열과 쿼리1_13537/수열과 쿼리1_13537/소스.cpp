#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

int arr[100100];
vector<int> seg[4100000];
ll n, m, k, ex = 1;

int sum(int x, int y, int z, int node, int le, int ri) {
	if (x > ri || y < le) return 0;
	if (x <= le && ri <= y) {
		int cnt = seg[node].size();
		int idx = upper_bound(seg[node].begin(), seg[node].end(), z) - seg[node].begin();
		return cnt - idx;
	}

	int m = (le + ri) / 2;
	return sum(x, y, z, node * 2, le, m) + sum(x, y, z, node * 2 + 1, m + 1, ri);

}

vector<int> mer(vector<int> a, vector<int> b) {
	vector<int> ret;
	int i = 0, j = 0;
	for (; i < a.size() && j < b.size();) {
		if (a[i] > b[j])ret.push_back(b[j]), j++;
		else ret.push_back(a[i]), i++;
	}

	for (; i < a.size(); i++) {
		ret.push_back(a[i]);
	}
	for (; j < b.size(); j++) {
		ret.push_back(b[j]);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (ex < n)ex <<= 1;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int j = ex + i;
		seg[j].push_back(arr[i]);
	}

	for (int i = ex - 1; i > 0; i--) {
		seg[i] = mer(seg[i * 2], seg[i * 2 + 1]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		x--;
		y--;
		cout << sum(x, y, z, 1, 0, ex - 1) << "\n";
	}
}