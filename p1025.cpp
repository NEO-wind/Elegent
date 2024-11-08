#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

const int N = 210;

int n, k, ans;
void dfs(int last, int sum, int cur) {
	if (cur == k) {
		if (sum == n) ans++;
		return;
	}
	for (int i = last; sum + i * (k - cur) <= n; i++) {
		dfs(i, sum + i, cur + i);
	}
}

int main() {
	scanf_s("%d %d", &n, &k);
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}