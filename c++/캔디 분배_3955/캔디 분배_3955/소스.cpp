#include<bits/stdc++.h>
using namespace std;

long long int query;
long long int k, c;

void f(long long int r1, long long int r2, long long int t1, long long int t2) {
	if (r2 == 0) {
		if (r1 != 1) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		long long int ans = (t1 + k) % k;
		while (c * ans <= k)ans += k;
		if (ans > 1000000000) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		cout << ans << endl;
		return;
	}

	long long int q = r1 / r2;
	long long int r = r1 % r2;
	long long int t = t1 - t2 * q;

	f(r2, r, t2, t);

	return;
}

int main() {
	cin >> query;
	while (query){
		query--;
		
		cin >> k >> c;

		if (c == 1) {
			if (k + 1 > 1000000000) {
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			cout << k + 1 << endl;
			continue;
		}
		if (k == 1) {
			cout << 1 << endl;
			continue;
		}
		
		f(k, c, 0, 1);
	}
}