#include<bits/stdc++.h>
using namespace std;

int n;
long long int b;
int mat[100][10][10];

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[1][i][j];
		}
	}

	// mul
	for (int x = 2; x < 80; x++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int k = 0; k < n; k++) {
					sum += (mat[x - 1][i][k] * mat[x - 1][k][j]) % 1000;
				}
				mat[x][i][j] = sum % 1000;
			}
		}
	}

	int a = 0;
	int ans[100][10][10] = {};
	for (int i = 0; i < n; i++)ans[0][i][i] = 1;
	int idx = 1;

	while (b != 0){
		if (b % 2 == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int sum = 0;
					for (int k = 0; k < n; k++) {
						sum += (mat[idx][i][k] * ans[a][k][j]) % 1000;
					}
					ans[a + 1][i][j] = sum % 1000;
				}
			}
			a++;
		}
		idx++;
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[a][i][j]);
		}
		cout << endl;
	}


}