#include<bits/stdc++.h>
using namespace std;

int n;
int arr[2100100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	long long int ans = 0;
	for (int i = 1; i <= 2000000; i++) {
		long long int cnt = 0;
		for (int j = i; j <= 2000000; j += i) {
			cnt += arr[j];
		}
		if (cnt <= 1) continue;
		ans = max(ans, cnt * i);
		
	}

	cout << ans;

}