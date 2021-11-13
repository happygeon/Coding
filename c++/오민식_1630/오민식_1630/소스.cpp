#include<bits/stdc++.h>
#define mod 987654321
using namespace std;

int n;
int p[1100100];
int ans[1100100];

void init() {
	for (int i = 1; i <= 1000000; i++)p[i] = i;
	for (int i = 2; i <= 1000000; i++) {
		if (p[i] == i) {
			for (int j = i; j <= 1000000; j += i) {
				if (p[j] == j)p[j] = i;
			}
		}
	}
}
int main() {
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (p[tmp] != 1){
			int a = p[tmp];
			int cnt = 0;
			while (p[tmp] == a){
				cnt++;
				tmp /= a;
			}
			if (ans[a] < cnt)ans[a] = cnt;
		}
	}
	long long int op = 1;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0)continue;
		for (int j = 0; j < ans[i]; j++) {
			op *= i;
			op %= mod;
		}
	}
	cout << op;
}