#include<bits/stdc++.h>
using namespace std;

int n;
int main() {
	cin >> n;
	cout << n << " ";
	if (n == 1)return 0;
	for (int i = 1; i < n / 2; i++) {
		cout << i << " " << n - i << " ";
	}
	if (n % 2)cout << n / 2 << " " << n - (n / 2);
	else cout << n / 2;
}