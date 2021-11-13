#include<bits/stdc++.h>
using namespace std;

long long int m, x0, x1, x2;

long long int inv(long long int n) {
	long long int ret = 1;
	long long int idx = m - 2;
	long long int a = n;
	while (idx){
		if (idx % 2 == 1) {
			ret = (ret * a) % m;
		}
		idx >>= 1;
		a = (a * a) % m;
	}

	return ret;
}

int main() {
	cin >> m >> x0 >> x1 >> x2;

	if (x1 == x2) {
		cout << 1 << " " << 0;
		return 0;
	}

	//cal c
	long long int c = (x0 * x2) % m;
	c = (c - x1 * x1) % m;
	c = (c * inv(x0 - x1)) % m;
	c = (c + m) % m;

	// cal a
	long long int a = ((x1 - c) * inv(x0)) % m;
	a = (a + m) % m;
	

	cout << a << " " << c;
}