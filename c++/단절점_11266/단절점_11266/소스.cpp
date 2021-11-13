#include<bits/stdc++.h>
#define inf 20000
using namespace std;
int v, e;
vector<vector<int>> vec;
int arr[inf];
int cnt = 0;
bool bcc[inf];

int dfs(int here, bool isRoot){
	arr[here] = ++cnt;
	int child = 0;
	int ret = arr[here];

	for (int i = 0; i < (int)vec[here].size(); i++)
	{
		int there = vec[here][i];

		if (arr[there] == 0)
		{
			child++;

			int subtree = dfs(there, false);

			//������
			if (!isRoot && subtree >= arr[here])
			{
				bcc[here] = true;
			}

			ret = min(ret, subtree);
		}

		//������ �����϶�
		else
		{
			ret = min(ret, arr[there]);
		}
	}

	//��Ʈ�϶�
	if (isRoot && child > 1) bcc[here] = true;

	return ret;
}


int main(){
	cin >> v >> e;
	vec.resize(v + 2);

	//make vec, ����� ������
	int first, second;
	int M = 0;
	for (int i = 0; i < e; i++)
	{
		cin >> first >> second;
		vec[first].push_back(second);
		vec[second].push_back(first);

		M = max(M, first);
		M = max(M, second);
	}

	for (int i = 1; i <= M; i++)if (arr[i] == 0)dfs(i, true);

	vector<int > result;
	for (int i = 1; i <= M; i++) if (bcc[i] == true) result.push_back(i);

	cout << result.size() << '\n';

	for (auto& out : result)
		cout << out << ' ';

	return 0;
}