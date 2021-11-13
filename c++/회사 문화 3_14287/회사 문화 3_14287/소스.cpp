#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100100];
int seg[100100];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int query = 0; query < m; query++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int idx, w;
			scanf("%d %d", &idx, &w);

			int i = idx;
			while (i != -1){
				seg[i] += w;
				i = arr[i];
			}

		}
		else {
			int idx;
			scanf("%d", &idx);

			printf("%d\n", seg[idx]);

		}
	}
}