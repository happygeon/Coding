#include<bits/stdc++.h>
using namespace std;

int x, r, n, mod;
long long int ex[60][2][2];
long long int ans[60][2][2];

int main() {
	cin >> x >> r >> n >> mod;
	
	int a1[2][2] = { {1, 1}, {0, 0} };

	ex[1][0][0] = r;
	ex[1][0][1] = 0;
	ex[1][1][0] = 1;
	ex[1][1][1] = 1;

	for (int i = 2; i <60; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ex[i][j][k] += (ex[i - 1][j][0] * ex[i - 1][0][k]) % mod;
				ex[i][j][k] += (ex[i - 1][j][1] * ex[i - 1][1][k]) % mod;
			}
		}
	}

	ans[1][0][0] = 1;
	ans[1][0][1] = 1;
	ans[1][1][0] = 0;
	ans[1][1][1] = 0;

	n--;
	int a = 2;
	int idx = 1;
	while (n > 0){
		if (n % 2 == 1) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					ans[a][j][k] += (ans[a - 1][j][0] * ex[idx][0][k]) % mod;
					ans[a][j][k] += (ans[a - 1][j][1] * ex[idx][1][k]) % mod;
				}
			}
			a++;
		}
		n /= 2;
		idx++;
	}

	ans[a - 1][0][0] *= x;
	ans[a - 1][0][0] %= mod;

	cout << ans[a - 1][0][0];
}