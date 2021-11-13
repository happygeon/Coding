#include<bits/stdc++.h>
using namespace std;

long long int n;
long long int arr[100100];
stack<long long int> st;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr[n] = 0;

	long long int ans = 0;
	st.push(-1);
	for (int i = 0; i <= n; i++) {
		while (st.size() > 1 && arr[st.top()] > arr[i]){
			long long int heigh = st.top();
			st.pop();
			ans = max(ans, arr[heigh] * (i - st.top() - 1));
		}
		st.push(i);
	}

	cout << ans;
}