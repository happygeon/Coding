#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[101];
double w[101][101];

double dist(int a, int b, int c)
{
    double area2 = arr[a].first * arr[b].second - arr[b].first * arr[a].second + arr[b].first * arr[c].second - arr[c].first * arr[b].second + arr[c].first * arr[a].second - arr[a].first * arr[c].second;
    return area2 / w[a][b];
}

int main()
{
    int q = 0;
    cin >> n;
    while (n) {
        for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
        for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
            w[i][j] = w[j][i] = hypot((double)(arr[i].first - arr[j].second), (double)(arr[i].first - arr[j].second));
        double ans = 1e16;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double mn = 0, mx = 0;
                for (int k = 1; k <= n; k++) {
                    double v = dist(i, j, k);
                    mn = min(mn, v);
                    mx = max(mx, v);
                }
                ans = min(ans, mx - mn);
            }
        }

        // 올림하기
        q++;
        printf("Case %d: %.2lf\n", q, ans + 0.005);

        cin >> n;
    }
}