#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 15;
int n;
int dp[N][N][N];
int map[N][N];

int max4(int x, int y, int z, int w) {
	return max(max(x, y), max(z, w));
}
int main() {
	cin >> n;
	memset(map, 0, sizeof(map));
	while (true) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) break;
		map[x][y] = z;
	}
	dp[0][1][1] = map[1][1];
	for (int i = 1; i <= 2 * (n - 1); i++) {
		for (int x1 = 1; x1 <= n; x1++) {
			for (int x2 = 1; x2 <= n; x2++) {
				int y1 = i + 2 - x1, y2 = i + 2 - x2;
				if (y1 < 1 || y2 < 1)continue;
				dp[i][x1][x2] = map[x1][y1]+map[x2][y2]+max4(dp[i - 1][x1][x2], dp[i - 1][x1 - 1][x2], dp[i - 1][x1][x2 - 1], dp[i - 1][x1 - 1][x2 - 1]);
				if (x1 == x2) dp[i][x1][x2] -= map[x1][y1];
			}
		}
	}
	cout << dp[2 * (n - 1)][n][n] << endl;
	return 0;
}