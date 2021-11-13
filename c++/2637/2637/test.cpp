#include<bits/stdc++.h>
int a;
int f() {
	a++;

	return a;
}

int main() {
	for (int i = 0; i < 20; i++)f();
}