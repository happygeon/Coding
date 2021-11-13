#include <bits/stdc++.h>
#define inf 30100
using namespace std;

int n, m;
int arr[inf], brr[inf], crr[inf], idx;
int dfn[inf], low[inf], ts;
int root, ans;

void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    int tree_cnt = 0;
    for (int i = arr[u]; ~i; i = crr[i]) {
        int j = brr[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j]) tree_cnt++;
        }
        else low[u] = min(low[u], dfn[j]);
    }
    if (u != root && tree_cnt) tree_cnt++;
    ans = max(ans, tree_cnt);
}

int main() {
    cin >> n >> m;
    while (n != 0 || m != 0) {

        // 초기화
        memset(dfn, 0, sizeof dfn);
        memset(arr, -1, sizeof arr);

        idx = ts = 0;
        ans = 0;

        // 입력
        while (m--) {
            int a, b;
            cin >> a >> b;

            brr[idx] = b;
            crr[idx] = arr[a];
            arr[a] = idx++;

            brr[idx] = a;
            crr[idx] = arr[b];
            arr[b] = idx++;
        }

        int cnt = 0;
        for (root = 0; root < n; root++)
            if (!dfn[root]) {
                cnt++;
                tarjan(root);
            }
        cout << ans + cnt - 1 << endl;


        cin >> n >> m;
    }
    return 0;
}