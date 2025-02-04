#include<bits/stdc++.h>
using namespace std;

int n;
int arr[11000];
int sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i + 1] > arr[i + 2]) {
			int c = min(arr[i], arr[i + 1] - arr[i + 2]);
			sum += c * 5;
			arr[i] -= c;
			arr[i + 1] -= c;
		}

		int min2 = min(arr[i], arr[i + 1]);
		int min3 = min(min2, arr[i + 2]);

		sum += min3 * 7;
		arr[i] -= min3;
		arr[i + 1] -= min3;
		arr[i + 2] -= min3;

		min2 -= min3;
		sum += min2 * 5;
		arr[i] -= min2;
		arr[i + 1] -= min2;

		sum += arr[i] * 3;
		arr[i] = 0;

	}
	cout << sum;
}