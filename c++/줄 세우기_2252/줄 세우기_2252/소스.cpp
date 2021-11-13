#include<bits/stdc++.h>
using namespace std;

int in[33000];
int out[33000];
int chk[33000];
int cnt;
vector<int>arr[33000];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		out[y]++;
		arr[x].push_back(y);
	}
	
	cnt = n;
	while (cnt){
		for (int i = 1; i <= n; i++) {
			if (out[i] == 0 && chk[i] == 0) {
				printf("%d ", i);
				chk[i] = 1;
				cnt--;
				for (int j = 0; j < arr[i].size(); j++) {
					out[arr[i][j]]--;
				}
			}
		}
	}
}