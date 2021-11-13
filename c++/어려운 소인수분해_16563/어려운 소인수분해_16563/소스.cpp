#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5100100];
int ta[5100100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i <= 5000000; i++)ta[i] = i;

	for (int i = 2; i * i <= 5000000; i++) {
		if (ta[i] == i) {
			for (int j = i * i; j <= 5000000; j += i)if (ta[j] == j)ta[j] = i;
		}
		//cout << ta[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j != 1;) {
			printf("%d ", ta[j]);
			j /= ta[j];
		}
		printf("\n");
	}
}