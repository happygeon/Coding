#include<bits/stdc++.h>
using namespace std;

long long int k;
long long int table[70];

int f(long long int k, int idx) {
	if (k == 1)return 0;
	if (k == 2)return 1;

	if (table[idx] >= k)return f(k, idx - 1);
	else return 1 - f(k - table[idx], idx - 1);

}


int main() {
	table[0] = 1;
	for (int i = 1; i < 70; i++)table[i] = table[i - 1] * 2;
	cin >> k;
	int idx;
	for (int i = 0; i < 70; i++) {
		if (k <= table[i]) {
			idx = i;
			break;
		}
	}

	cout << f(k, idx - 1);

}