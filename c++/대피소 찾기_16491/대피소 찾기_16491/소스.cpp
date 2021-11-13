#include<bits/stdc++.h>
using namespace std;

int n;
int vis[20];
vector<int> fin;
bool e = false;
vector<pair<int, int>> a, b;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int value = a.first * b.second + b.first * c.second + c.first * a.second;
	value -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (value > 0)return 1; // �ݽð�
	else if (value == 0)return 0; // ����
	else return -1; // �ð�
}

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int tmp1 = ccw(a, b, c) * ccw(a, b, d);
	int tmp2 = ccw(c, d, a) * ccw(c, d, b);

	if (tmp1 == 0 && tmp2 == 0) { // ��������
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		if (c <= b && a <= d)return true;
		return false;
	}
	else if (tmp1 <= 0 && tmp2 <= 0) return true; // ���� �Ǹ� Ʈ��
	return false;
}

void dfs(int idx, vector<int> ans) {
	if (idx == n) {// ��� �� Ž�� �Ϸ� ��
		for (auto i : ans)fin.push_back(i);
		e = true;
		return;
	}
	pair<int, int> dot = a[idx]; // ó���� �κ�
	for (int i = 0; i < n; i++) {
		if (vis[i] == 1)continue;

		//�ٸ� ���� ��ġ���� Ȯ�� �ƴ϶��, 
		bool can = true;
		for (int j = 0; j < idx; j++) {
			if (check(dot, b[i], a[j], b[ans[j]])) can = false;
		}
		if (!can)continue;

		ans.push_back(i);
		vis[i] = 1;
		dfs(idx + 1, ans);
		if (e)return;
		vis[i] = 0;
		ans.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		b.push_back(tmp);
	}

	vector<int> ans;
	dfs(0, ans);

	for (auto i : fin)cout << i + 1 << endl;
}
