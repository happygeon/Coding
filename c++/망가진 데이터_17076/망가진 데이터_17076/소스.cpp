#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

int arr[200100];
vector<int> seg[1100100];
int mseg[1100100];
ll n, m, k, ex = 1;

int sum(int x, int y, int z, int node, int le, int ri) {
	if (x > ri || y < le) return 0;
	if (x <= le && ri <= y) return upper_bound(seg[node].begin(), seg[node].end(), z) - seg[node].begin();

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

int segm(int s, int e, int node, int le, int ri) {
	if (s > ri || e < le) return 0;
	if (s <= le && ri <= e) return mseg[node];

	int m = (le + ri) / 2;
	return max(segm(s, e, node * 2, le, m), segm(s, e, node * 2 + 1, m + 1, ri));
}

pair<int, int> cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first)return a;
	if (a.first == b.first) {
		if (a.second > b.second)return a;
	}
	return b;
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
		mseg[j] = arr[i];
	}

	for (int i = ex - 1; i > 0; i--) {
		seg[i] = mer(seg[i * 2], seg[i * 2 + 1]);
		mseg[i] = max(mseg[i * 2], mseg[i * 2 + 1]);
	}
	
	pair<int, int> ans = make_pair(-1, -1);
	for (int i = 1; i < n; i++) {
		int idx = arr[i];
		int M = segm(0, i - 1, 1, 0, ex - 1);
		if (2 * idx <= sum(i + 1, ex - 1, M, 1, 0, ex - 1)) {
			pair<int, int> tmp = make_pair(M, idx);
			ans = cmp(ans, tmp);
		}
	}
	if (ans.first == -1) {
		cout << -1;
		return 0;
	}
	else {
		cout << ans.first << " " << ans.second;
	}
}