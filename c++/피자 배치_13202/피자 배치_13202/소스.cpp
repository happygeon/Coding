#include <bits/stdc++.h>
#define pi 3.141592653589
using namespace std;

int main() {
	int q;
	cin >> q;

	while (q) {
		q--;

		long double a, b, k;
		cin >> a >> b >> k;

		long double first = (a * b) / (a + b + sqrt(a * a + b * b));
		long double tmp1 = first;
		long double tmp2 = first;
		long double tmp3 = first;
		long double ans = first * first * pi;

		long double r1 = sqrt((tmp1 * tmp1) + (tmp1 * tmp1));
		long double r2 = sqrt((tmp2 * tmp2) + (b - tmp2) * (b - tmp2));
		long double r3 = sqrt((tmp3 * tmp3) + (a - tmp3) * (a - tmp3));

		for (int j = 0; j < k - 1; j++) {
			long double cir1, cir2, cir3;
			long double rad1, rad2, rad3;

			rad1 = (tmp1 * (r1 - tmp1)) / (tmp1 + r1);
			cir1 = rad1 * rad1 * pi;

			rad2 = (tmp2 * (r2 - tmp2)) / (tmp2 + r2);
			cir2 = rad2 * rad2 * pi;

			rad3 = (tmp3 * (r3 - tmp3)) / (tmp3 + r3);
			cir3 = rad3 * rad3 * pi;

			if (cir2 < cir1 && cir3 < cir1) {
				ans = cir1;
				r1 -= (tmp1 + rad1);
				tmp1 = rad1;
			}

			else if (cir1 < cir2 && cir3 < cir2) {
				ans = cir2;
				r2 -= (tmp2 + rad2);
				tmp2 = rad2;
			}

			else if (cir1 == cir2) {
				ans = cir1;
				r1 -= (tmp1 + rad1);
				tmp1 = rad1;
			}

			else {
				ans = cir3;
				r3 -= (tmp3 + rad3);
				tmp3 = rad3;
			}
		}
		printf("%.8Lf\n", ans);
	}
}