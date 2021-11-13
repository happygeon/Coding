#include<bits/stdc++.h>
using namespace std;

int n;
int p[2100100];
int arr[1100];
int ta[2100100];
int mi;

vector<int> v;

void init() {
	int idx = 0;
	for (int i = 1; i <= 1000000; i++)p[i] = i;
	for (int i = 2; i <= 1000000; i++) {
		if (p[i] == i) {
			idx++;
			v.push_back(i);
			for (int j = i; j <= 1000000; j += i) {
				if (p[j] == j)p[j] = i;
			}
		}
	}
	//cout << idx;
}
int main() {
	init();

	cin >> n;
	mi = (n + 1) / 2;
	for (int i = 0; i < n; i++)cin >> arr[i];
	//int ch = arr[n - 1] - arr[0];
	
	for (auto i : v) {
		if (i > arr[n - 1] / mi)break;
		for (int j = 0; j < n; j++) {
			ta[arr[j] % i]++;
			mi = max(mi, ta[arr[j] % i]);
		}
		for (int j = 0; j < n; j++)ta[arr[j] % i]--;
	}

	cout << mi;
}