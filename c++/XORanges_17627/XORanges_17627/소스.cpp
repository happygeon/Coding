#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;

int arr[200100];
int seg2[1010000];
int seg1[1010000];
ll n, m, k, ex1 = 1, ex2 = 1, n1, n2;


int sum1(int x, int y, int node, int le, int ri) {
	if (x > ri || y < le) return 0;
	if (x <= le && ri <= y) {
		return seg1[node];
	}

	int m = (le + ri) / 2;
	return sum1(x, y, node * 2, le, m) ^ sum1(x, y, node * 2 + 1, m + 1, ri);

}

int sum2(int x, int y, int node, int le, int ri) {
	if (x > ri || y < le) return 0;
	if (x <= le && ri <= y) {
		return seg2[node];
	}

	int m = (le + ri) / 2;
	return sum2(x, y, node * 2, le, m) ^ sum2(x, y, node * 2 + 1, m + 1, ri);

}

vector<int> mer(vector<int> a, vector<int> b) {
	vector<int> ret;
	int i = 0, j = 0;
	for (; i < a.size() && j < b.size();) {
		if (a[i] > b[j])ret.push_back(b[j]), j++;
		else ret.push_back(a[i]), i++;
	}

	for (; i < a.size(); i++) {
		ret.push_back(a[i]);
	}
	for (; j < b.size(); j++) {
		ret.push_back(b[j]);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	n2 = n / 2; // È¦¼ö
	n1 = n - n2; // Â¦¼ö
	while (ex1 < n1)ex1 <<= 1;
	while (ex2 < n2)ex2 <<= 1;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i < n; i += 2) {
		int j = ex2 + i / 2;
		seg2[j] = arr[i];
	}
	for (int i = 0; i < n; i += 2) {
		int j = ex1 + i / 2;
		seg1[j] = arr[i];
	}

	for (int i = ex1 - 1; i > 0; i--) {
		seg1[i] = seg1[i * 2] ^ seg1[i * 2 + 1];
	}
	for (int i = ex2 - 1; i > 0; i--) {
		seg2[i] = seg2[i * 2] ^ seg2[i * 2 + 1];
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			y--;
			if (y % 2 == 0) {
				int tmp = z ^ seg1[ex1 + y / 2];
				for (int i = ex1 + y / 2; i > 0; i /= 2) {
					seg1[i] = seg1[i] ^ tmp;
				}
			}
			else {
				int tmp = z ^ seg2[ex2 + y / 2];
				for (int i = ex2 + y / 2; i > 0; i /= 2) {
					seg2[i] = seg2[i] ^ tmp;
				}
			}
		}
		else{
			if ((y - z) % 2 != 0) {
				cout << 0 << "\n";
				continue;
			}
			y--;
			z--;
			if (y % 2 == 0) {
				cout << sum1(y / 2, z / 2, 1, 0, ex1 - 1) << "\n";
			}
			else {
				cout << sum2(y / 2, z / 2, 1, 0, ex2 - 1) << "\n";
			}
		}
	}
	
}