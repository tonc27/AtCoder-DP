#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
typedef long long ll;

int n, W, w[MAXN], v[MAXN];
ll dp[MAXN][10*MAXN*MAXN], ans;

int main(){
	cin >> n >> W;
	for(int i = 0; i < n; ++i){
		cin >> w[i] >> v[i];
	}
	dp[0][w[0]] = v[0];
	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= W; ++j){
			dp[i][j] = dp[i-1][j];
			if(j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
			}
		}
	}
	for(int i = 0; i <= W; ++i){
		ans = max(ans, dp[n-1][i]);
	}
	cout << ans;
	return 0;
}
