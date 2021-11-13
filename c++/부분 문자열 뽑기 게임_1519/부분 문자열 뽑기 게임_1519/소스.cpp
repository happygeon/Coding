#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n;
int dp[1000100];
int ta[10];

vector<int> f(int a) {
	vector<int> ret;
	int idx;
	for (int i = 9; i >= 0; i--) {
		if (a >= ta[i]) {
			idx = i;
			break;
		}
	}
	idx++;

	for (int i = 1; i < idx; i++) {
		for (int j = idx - i; j >= 0; j--) {
			int x = a / ta[j];
			int y = x % ta[i];
			if(y)ret.push_back(y);
		}
	}

	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

int main() {
	ta[0] = 1;
	for (int i = 1; i < 10; i++) ta[i] = 10 * ta[i - 1];
	for (int i = 0; i < 10; i++) dp[i] = -1;
	cin >> n;

	for (int i = 10; i <= n; i++) {
		dp[i] = -1;
		vector<int> tmp = f(i);
		for (auto j : tmp) {
			if (dp[i - j] == -1) {
				dp[i] = j;
				break;
			}
		}
	}
	cout << dp[n];
	
}