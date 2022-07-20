#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;

int ad(int a, int b){ return (a + b >= MOD) ? a + b - MOD : a + b; }
int sub(int a, int b){ return (a - b < 0) ? a - b + MOD : a - b; }

int n, k, a[101], dp[101][MAXN], pre[101][MAXN];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i <= a[0]; ++i) dp[0][i] = 1;
	pre[0][0] = dp[0][0];
	for(int i = 1; i <= k; ++i) pre[0][i] = pre[0][i - 1] + dp[0][i];
	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= k; ++j){
			dp[i][j] = sub(pre[i - 1][j], (j - a[i] <= 0) ? 0 : pre[i - 1][j - a[i] - 1]);
		}
		pre[i][0] = dp[i][0];
		for(int j = 1; j <= k; ++j) pre[i][j] = ad(pre[i][j - 1], dp[i][j]);
	}
	cout << dp[n - 1][k];
	return 0;
}
