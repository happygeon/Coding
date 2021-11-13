#include <bits/stdc++.h>
#define inf 1000000001
typedef long long int ll;
using namespace std;
int n;

pair<ll, ll> arr[10100], brr[4], s, e;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll value = a.first * b.second + b.first * c.second + c.first * a.second;
    value -= b.first * a.second + c.first * b.second + a.first * c.second;
    if (value > 0) return 1;
    if (value) return -1;
    return 0;
}

bool chk(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
    int tmp1 = ccw(a, b, c) * ccw(a, b, d);
    int tmp2 = ccw(c, d, a) * ccw(c, d, b);
    if (tmp1 <= 0 && tmp2 <= 0) {
        if (tmp1 == 0 && tmp2 == 0) {
            if (b <= a) swap(a, b);
            if (d <= c) swap(c, d);
            return a <= d && c <= b;
        }
        else return true;
    }
    else return false;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;

    for (int i = 1; i <= 3; i++) cin >> brr[i].first >> brr[i].second;

    for (int i = 1; i <= 3; i++) {
        s = brr[i];
        e.first = inf;
        e.second = brr[i].second + 1;

        bool is_same = false;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            pair<ll, ll> first = arr[j];
            pair<ll, ll> second = arr[j + 1];
            if (j == n) second = arr[1];
            
            if (s.first == first.first && s.second == first.second) is_same = true;
            else if (chk(s, s, first, second))is_same = true;
            if (is_same) {
                cout << 1 << endl;
                break;
            }         
            if (chk(s, e, first, second)) cnt++; // °ãÄ¥ ¶§ +1
        }
        if (is_same) continue;
        cout << (cnt % 2) << endl;
    }
}