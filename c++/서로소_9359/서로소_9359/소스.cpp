#include<bits/stdc++.h>
using namespace std;

int query, q;
int p[100100];
vector<int> pri;

// 서로소가 아닌것들 개수(1~x)
long long int f(long long int x, vector<int> v) {
	long long int ret = 0;
	int bit = 1 << v.size();
	for (int i = 1; i < bit; i++) {
		bool is_plus = false;
		int idx = i;
		int j = 0;
		int tmp = 1;
		while (idx >= 1){
			if (idx % 2 == 1) {
				is_plus = !is_plus;
				tmp *= v[j];
			}
			j++;
			idx >>= 1;
		}
		if (is_plus) {
			ret += x / tmp;
		}
		else {
			ret -= x / tmp;
		}
	}
	return ret;
}

int main() {
	//init
	for (int i = 1; i <= 100000; i++)p[i] = i;
	for (int i = 2; i <= 100000; i++) {
		if (p[i] == i) {
			pri.push_back(i);
			for (int j = i; j <= 100000; j += i) {
				if (p[j] == j)p[j] = i;
			}
		}
	}

	//cal
	cin >> query;
	while (query != q){
		q++;

		long long int a, b, n;
		cin >> a >> b >> n;

		long long int tmp = n;
		vector<int> so;
		for (auto i : pri) {
			if (tmp % i != 0)continue;
			so.push_back(i);
			while (tmp % i == 0)tmp /= i;
		}
		if (tmp > 100000)so.push_back(tmp);

		long long int x = f(a - 1, so), y = f(b, so);
		long long int ans = b - a + 1;
		printf("Case #%d: %lld\n", q, ans - y + x);
	}
}