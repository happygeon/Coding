#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < testcase; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (r1 < r2)
			swap(r1, r2);

		if (len == 0) {
			if (r1 == r2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}

		else if (len > abs(r1 - r2) && len < r1 + r2)
			cout << 2 << endl;

		else if (len == r1 + r2 || len == abs(r1 - r2))
			cout << 1 << endl;

		else
			cout << 0 << endl;
	}
	return 0;
}