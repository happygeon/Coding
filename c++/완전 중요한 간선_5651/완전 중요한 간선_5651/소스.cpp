#include <bits/stdc++.h>
#define inf 987654321
using namespace std;
int f[500][500];
int c[500][500];

int main(){
    int query;
    cin >> query;

    while (query){
        query--;
        int n, m;
        cin >> n >> m;
        vector<int> v[500];
        memset(f, 0, sizeof f);
        memset(c, 0, sizeof c);

        vector<pair<int, int>> arr;

        for (int i = 0; i < m; i++){
            int a, b, cost;
            cin >> a >> b >> cost;
            v[a].push_back(b);
            v[b].push_back(a);
            c[a][b] += cost;
            arr.push_back(make_pair(a, b));
        }

        int tot = 0, s = 1, e = n;
        while (1){
            int prev[500];
            memset(prev, -1, sizeof(prev));
            queue<int> q;
            q.push(s);
            while (!q.empty()){
                int node = q.front();
                q.pop();
                for (auto i : v[node]){
                    if (prev[i] == -1 && c[node][i] > f[node][i]){
                        q.push(i);
                        prev[i] = node;
                    }
                }
                if (prev[e] != -1)break;
            }
            if (prev[e] == -1)break;
            int flow = inf;
            for (int i = e; i != s; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
            for (int i = e; i != s; i = prev[i]) f[prev[i]][i] += flow, f[i][prev[i]] -= flow;
            tot += flow;
        }

        // �� ������ ���� Ȯ��
        // �� ������ ���۰� ������ flow
        // �߰��� ����� �� �ְų�, �ٸ� ���� �����ؼ� �뷮�� �پ �������� ����
        // �ƴϸ� ans++
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){
            int s = arr[i].first;
            int e = arr[i].second;

            int prev[500];
            memset(prev, -1, sizeof(prev));
            queue<int> q;
            q.push(s);
            while (!q.empty()){
                int node = q.front();
                q.pop();
                for (auto i : v[node]){
                    if (prev[i] == -1 && c[node][i] > f[node][i]){// ������ �ִ��϶� ���� ==>s���� e�� �ٷ� ���°ŵ� ���� ���� ���ؤǤ� ��
                        prev[i] = node;
                        q.push(i);
                    }
                }
                if (prev[e] != -1)break;
            }
            // s���� e�� �� ����� ������
            if (prev[e] == -1)ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}