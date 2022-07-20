#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;

int n;
long double dp[MAXN][MAXN], p[MAXN], ans;

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);
		for(int j = 1; j <= i; ++j){
			dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
		}
	}
	for(int i = (n + 1) / 2; i <= n; ++i){
		ans += dp[n][i];
	}
	cout << setprecision(10) << ans;
	return 0;
}
