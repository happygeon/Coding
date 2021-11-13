#include<bits/stdc++.h>
using namespace std;

int n;
int arr[200200];

int gcd(int a, int b) {
	if (a < b)return gcd(b, a);

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int f(int s, int e) {
	if (e - s == 1)return arr[s];

	int m = (s + e) / 2;
	
	int a1 = f(s, m);
	int a2 = f(m, e);
	int g1, g2;
	if (e - m == 1) {
		g1 = arr[m];
	}
	else {
		g1 = gcd(arr[m], arr[m + 1]);
		for (int i = m + 2; i < e; i++) {
			g1 = gcd(g1, arr[i]);
		}
	}

	if (m - s == 1) {
		g2 = arr[s];
	}
	else {
		g2 = gcd(arr[s], arr[s + 1]);
		for (int i = s + 2; i < m; i++) {
			g2 = gcd(g2, arr[i]);
		}
	}

	return max(a1 + g1, a2 + g2);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << f(0, n);
}