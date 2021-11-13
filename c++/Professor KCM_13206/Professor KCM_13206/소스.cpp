#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int query;

int main() {
	//init
	int e[1100] = {};
	int pri[1100] = {};
	int rev[1100] = {};
	int idx = 1;//idx = 168, 1 = 2, 2 = 3, 3 = 5...
	for (int i = 1; i <= 1000; i++) e[i] = i;
	for (int i = 2; i <= 1000; i++) {
		if (e[i] == i) {
			pri[idx] = i;
			rev[i] = idx;
			idx++;
			for (int j = i; j <= 1000; j += i) if (e[j] > i)e[j] = i;
		}
	}
	int chk[1100][200] = {};
	for (int i = 1; i <= 1000; i++) {
		int x = i;
		while (e[x] != x){
			chk[i][rev[e[x]]]++;
			x /= e[x];
		}
		chk[i][rev[x]]++;
	}
	
	// cal
	cin >> query;
	while (query){
		query--;

		int n;
		int arr[1100] = {};
		int out[200] = {};
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp] = 1;
		}

		for (int i = 1; i <= 1000; i++) {
			if (arr[i] == 0)continue;
			for (int j = 1; j <= idx; j++) {
				if (out[j] < chk[i][j])out[j] = chk[i][j];
			}
		}
		
		long long int ans = 1;
		for (int j = 1; j <= idx; j++) {
			if (out[j] == 0)continue;
			for (int k = 0; k < out[j]; k++) {
				ans = (ans * pri[j]) % mod;
			}
		}
		cout << ans << endl;
	}
}