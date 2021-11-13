#include<bits/stdc++.h>
using namespace std;

int n;
int arr[200100]; 
int in[200100];
int seg[1050000];
int e = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)cin >> in[i];
	while (e < n) e <<= 1;
	
	//make sum seg
	for (int i = e; i < n + e; i++) {
		for (int j = i; j > 0; j /= 2)seg[j] += arr[i - e];
	}

	for (int i = 0; i < n; i++) {
		int idx = in[i];
		int j = 1;
		for (; j < e;) {
			if (seg[j * 2] >= idx) j *= 2;
			else {
				idx -= seg[j * 2];
				j = j * 2 + 1;
			}
		}

		int ans = j - e;
		cout << ans + 1 << ' ';

		for (int j = ans + e; j > 0; j /= 2)seg[j] -= arr[ans];
	}

}