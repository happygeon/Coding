#include<bits/stdc++.h>
using namespace std;

int n;
long long int ans;

int main() {
	cin >> n;
	n--;

	for (int i = n + 1; i > 0;) {
		int tmp = n / ((n / i) + 1);
		ans += ((n / i) + 1) * (i - tmp);
		i = tmp;
	}

	cout << ans;
}