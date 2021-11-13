#include<bits/stdc++.h>
using namespace std;

int n, wh, bl;
int arr[150][150];

void f(int xs, int ys, int xe, int ye) {
	int chk = arr[xe][ye] + arr[xs][ys] - arr[xe][ys] - arr[xs][ye];
	int width = xe - xs;
	if (width * width == chk) {
		bl++;
		return;
	}
	if (0 == chk) {
		wh++;
		return;
	}
	int xm = (xe + xs) / 2;
	int ym = (ye + ys) / 2;
	f(xs, ys, xm, ym);
	f(xs, ym, xm, ye);
	f(xm, ys, xe, ym);
	f(xm, ym, xe, ye);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + tmp;
		}
	}

	f(0, 0, n, n);

	cout << wh << endl;
	cout << bl;
}