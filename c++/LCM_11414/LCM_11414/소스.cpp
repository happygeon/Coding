#include<bits/stdc++.h>
#define inf 9003372036854775807
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < b)return gcd(b, a);
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

long long int lcm(long long int a, long long int b) {
    return (a * b) / gcd(a, b);
}

long long int a, b;
long long int ans = inf;
long long int n = inf;

int main() {
    cin >> a >> b;
    if (a < b)swap(a, b);
    long long int ab = a - b;
    if (ab == 0) {
        cout << 1;
        return 0;
    }
    for (long long int i = 1; i * i <= ab; i++) {
        if (ab % i != 0)continue;
        // case 1
        long long int tmp1 = (-b % i) + i;
        if (n > lcm(a + tmp1, b + tmp1)) {
            n = lcm(a + tmp1, b + tmp1);
            ans = tmp1;
        }
        else if (n == lcm(a + tmp1, b + tmp1)) {
            ans = min(ans, tmp1);
        }
        // case 2
        long long int ii = ab / i;
        long long int tmp2 = (-b % ii) + ii;
        if (n > lcm(a + tmp2, b + tmp2)) {
            n = lcm(a + tmp2, b + tmp2);
            ans = tmp2;
        }
        else if (n == lcm(a + tmp2, b + tmp2)) {
            ans = min(ans, tmp2);
        }
    }

    cout << ans;

}