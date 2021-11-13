#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
vector<int> v[100100];
int arr[100005];
int cnt[100005];
int ans = 0;

int cactus(int node, int par) {
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < v[node].size(); i++) {
		int tmp = v[node][i];
		if (par != tmp) {
			if (arr[tmp] == 0) {
				arr[tmp] = arr[node] + 1;
				ret1 += cactus(tmp, node);
			}
			else if (arr[node] > arr[tmp]) ret1++;
			else if (arr[node] < arr[tmp]) ret2--;
		}
	}
	cnt[node] = ret1;
	if (cnt[node] >= 2) ans = 1;
	return ret1 + ret2;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	arr[1] = 1;
	cactus(1, 0);
	if (ans)cout << "Not cactus";
	else cout << "Cactus";
}