#include<bits/stdc++.h>
#define mod 1000000007
#define nax 4000000
using namespace std;

int query;
long long int fact[4100100];
long long int inv[4100100];

void f(int n, int k) {
	long long int ans = fact[n];

}

int main() {
	scanf("%d", &query);
	
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= nax; i++)fact[i] = (fact[i - 1] * i) % mod;

	long long int idx = mod - 2;
	long long int a = fact[nax];
	inv[nax] = 1;
	while (idx){
		if (idx % 2 == 1) {
			inv[nax] *= a;
			inv[nax] %= mod;
		}
		idx >>= 1;
		a = (a * a) % mod;
	}

	for (int i = nax - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;

	while (query){
		query--;
		int n, k;
		scanf("%d %d", &n, &k);

		long long int ans = fact[n];
		ans = (ans * inv[k]) % mod;
		ans = (ans * inv[n - k]) % mod;

		printf("%lld\n", ans);
	}
}