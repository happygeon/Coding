#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

int n, c, ex = 1;
vector<int> v[200100];
int d[200100];
int p[200100];
pair<int, int> ta[200100];
int seg[1100100];
int ne[200100];
int idx[200100];
int indexing = 1;

void dfs(int node, int depth, int par) {
	int s = indexing;
	idx[node] = indexing;
	ne[indexing] = node;
	indexing++;
	p[node] = par;
	d[node] = depth;
	for (auto i : v[node]) {
		if (i == par)continue;
		dfs(i, depth + 1, node);
	}
	int e = indexing;
	ta[node] = make_pair(s, e - 1);
}

ll sum(int s, int e, int node, int le, int ri) {
	if (e < le || s > ri)return 0;
	if (s <= le && ri <= e)return seg[node];

	int m = (le + ri) / 2;
	return sum(s, e, node * 2, le, m) + sum(s, e, node * 2 + 1, m + 1, ri);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> c;
	while (ex < n) ex <<= 1;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(c, 1, -1);

	int q;
	cin >> q;
	while (q){
		q--;

		int x, y;
		cin >> x >> y;
		if (x == 1) {
			int newidx = idx[y];
			for (int i = ex + newidx - 1; i > 0; i /= 2) seg[i]++;
		}
		else {
			ll ans = d[y];
			ll s = sum(ta[y].first - 1, ta[y].second - 1, 1, 0, ex - 1);
			ans *= s;
			cout << ans << "\n";
		}

	}
	
}