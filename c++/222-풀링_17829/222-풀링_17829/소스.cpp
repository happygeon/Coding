#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1100][1100];

int f(int xs, int ys, int xe, int ye) {
	if (xe - xs == 1) {
		return arr[xs][ys];
	}
	int xm = (xs + xe) / 2;
	int ym = (ys + ye) / 2;
	
	int a[4];
	a[0] = f(xs, ys, xm, ym);
	a[1] = f(xs, ym, xm, ye);
	a[2] = f(xm, ys, xe, ym);
	a[3] = f(xm, ym, xe, ye);

	sort(a, a + 4);

	return a[2];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ans = f(0, 0, n, n);

	cout << ans;
}