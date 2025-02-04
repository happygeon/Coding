#include<bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;

long long n, arr[310000], m[310000];
int main() {
	cin >> n;
	m[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[i + 1] = (m[i] * 2) % mod;
	}

	sort(arr, arr + n);

	long long plus = 0;
	long long minus = 0;
	for (int i = 0;i < n;i++) {
		plus += arr[i] * m[i];
		minus += arr[i] * m[n - i - 1];
		plus %= mod;
		minus %= mod;
	}
	long long ans = (plus - minus + mod) % mod;
	cout << ans%mod;

	return 0;
}