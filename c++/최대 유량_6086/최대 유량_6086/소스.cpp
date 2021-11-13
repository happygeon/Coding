#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int n;
int ans;
int arr[60];
int brr[60][60];
int crr[60][60];
vector<int> v[60];

char to_int(char x)
{
	if (x <= 'Z') {
		return x - 'A';
	}
	return x - 'a' + 26;
}

int main(int argc, char* argv[]){

	cin >> n;

	for (int i = 0; i < n; ++i) {
		char a, b;
		int num;

		cin >> a >> b >> num;

		a = to_int(a);
		b = to_int(b);

		brr[a][b] += num;
		brr[b][a] += num;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int s = to_int('A');
	int e = to_int('Z');

	// bfs
	while (1) {
		memset(arr, -1, sizeof(arr));
		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (cur == e) break;

			for (int i = 0; i < v[cur].size(); ++i) {
				int next = v[cur][i];

				if (arr[next] == -1 && brr[cur][next] - crr[cur][next] > 0) {
					q.push(next);
					arr[next] = cur;
				}
			}
		}

		if (arr[e] == -1) break;

		int m = inf;

		for (int i = e; i != s; i = arr[i]) m = min(m, brr[arr[i]][i] - crr[arr[i]][i]);

		for (int i = e; i != s; i = arr[i]) crr[arr[i]][i] += m, crr[i][arr[i]] -= m;

		ans += m;
	}

	cout << ans;
}