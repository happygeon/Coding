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

        // 각 간선에 대해 확인
        // 각 간선의 시작과 끝으로 flow
        // 추가로 흘려줄 수 있거나, 다른 길이 존재해서 용량이 줄어도 괜찮으면 무시
        // 아니면 ans++
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
                    if (prev[i] == -1 && c[node][i] > f[node][i]){// 유량이 최대일때 배제 ==>s에서 e로 바로 가는거도 따로 생각 안해ㅗㄷ 됨
                        prev[i] = node;
                        q.push(i);
                    }
                }
                if (prev[e] != -1)break;
            }
            // s에서 e로 갈 방법이 없을때
            if (prev[e] == -1)ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}