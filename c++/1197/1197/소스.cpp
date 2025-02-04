#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> pp;

int v, e;
long long ans;
int chk[11000];

vector<p> arr[11000]; //가중치, 연결노드

priority_queue <pp, vector<pp>, greater<pp>> q;// 가중치, 노드1, 노드2

int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		pp tmp;
		cin >> tmp.second.first >> tmp.second.second >> tmp.first;
		arr[tmp.second.first].push_back(make_pair(tmp.first, tmp.second.second));
		arr[tmp.second.second].push_back(make_pair(tmp.first, tmp.second.first));

		if (tmp.second.first == 1 || tmp.second.second == 1) q.push(tmp);
	}
	
	chk[1] = 1;
	
	while (!q.empty()) {
		pp tmp = q.top();
		q.pop();

		int node1 = tmp.second.first, node2 = tmp.second.second, w = tmp.first;
		if (chk[node1] == 1 && chk[node2] == 1) continue;
		else if (chk[node1] == 0 && chk[node2] == 0) cout << "??";
		else if (chk[node1] == 1) {
			int ttmmpp = node1;
			node1 = node2;
			node2 = ttmmpp;
		}
		//WLOG, node1 이 추가될 노드
		ans += w;
		chk[node1] = 1;
		for (auto i : arr[node1]) {
			pp ins = make_pair(i.first, make_pair(i.second, node1));
			q.push(ins);
		}
	}

	cout << ans;
}