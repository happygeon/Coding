#include <bits/stdc++.h>
#define inf 1987654321
using namespace std;

typedef pair<int, int> p;
p ma = make_pair(inf, inf);
vector<p> arr;
int base;

p mini(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return ma; // 범위 바깥
    if (start <= left && right <= end) return arr[node]; // 완전히 포함
    int mid = (left + right) / 2;
    return min(
        mini(node * 2, left, mid, start, end),
        mini(node * 2 + 1, mid + 1, right, start, end)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    base = 1;
    while (base < n) base *= 2;
    arr.resize(2 * base, ma);

    for (int i = 0; i < n; i++) {
        cin >> arr[i + base].first;
        arr[i + base].second = i + 1;
    }

    for (int i = base - 1; i >= 1; i--) {
        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b + base - 1].first = c;
            for (int i = (b + base - 1) / 2; i >= 1; i /= 2) {
                arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
            }
        }
        else {
            cout << mini(1, 1, base, b, c).second << '\n';
        }
    }
    return 0;
}
