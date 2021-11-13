#include <bits/stdc++.h>
#define inf 987654321
using namespace std;

int w[500][500];
int c[500][500];
int f[500][500];
int d[500];
int dist[500];
int n, p;
bool chk[500];
vector<int> v[500];


int main(){
    cin >> n >> p;

    for (int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

        // 유량이 1
        // 역방향은 -1
        w[a][b] = 1;
        w[b][a] = -1;

        c[a][b] = 1;
    }
    

    int ans = 0;

    while (1) {
        queue<int> q;

        // 초기화
        memset(d, -1, sizeof d);
        dist[1] = 0;
        for (int i = 2; i < 500; i++)dist[i] = inf;

        chk[1] = true;
        q.push(1);

        while (!q.empty()) {
            int size = q.size();

            while (size) {
                size--;

                int tmp = q.front();

                q.pop();

                chk[tmp] = false;

                for (auto i : v[tmp])
                    if (c[tmp][i] - f[tmp][i] > 0 && dist[i] > dist[tmp] + w[tmp][i]) {
                        dist[i] = dist[tmp] + w[tmp][i];
                        d[i] = tmp;
                        if (chk[i])continue;
                        chk[i] = true;
                        q.push(i);

                        if (i == 2) break;
                    }
            }
        }
        if (d[2] == -1) break;

        int m = inf;

        for (int i = 2; i != 1; i = d[i]) m = min(m, c[d[i]][i] - f[d[i]][i]);

        for (int i = 2; i != 1; i = d[i]) f[d[i]][i] += m, f[i][d[i]] -= m;

        ans++;
    }
    cout << ans;
}
