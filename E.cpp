#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
const int inf = (1 << 30);

int n, W, w[101], v[101], dp[101][MAXN];

int main(){
	cin >> n >> W;
	for(int i = 0; i < n; ++i){
		cin >> w[i] >> v[i];
	}
	dp[0][0] = 0;
	for(int i = 1; i <= v[0]; ++i) dp[0][i] = w[0];
	for(int i = v[0] + 1; i < MAXN; ++i) dp[0][i] = inf;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < MAXN; ++j){
			dp[i][j] = dp[i - 1][j];
			if(j >= v[i]){
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
		for(int j = MAXN - 2; j >= 0; --j) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
	}
	for(int i = 0; i < MAXN - 1; ++i){
		if(dp[n - 1][i] <= W && dp[n - 1][i + 1] > W){
			cout << i;
		}
	}
	return 0;
}
