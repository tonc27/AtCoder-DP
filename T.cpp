#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;
const int MOD = 1e9 + 7;

int ad(int a, int b){ return (a + b >= MOD) ? a + b - MOD : a + b; }

int n, dp[MAXN][MAXN], pre[MAXN][MAXN], suf[MAXN][MAXN], ans;
string s;

int main(){
	cin >> n >> s;
	dp[0][0] = pre[0][0] = suf[0][0] = 1;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= i; ++j){
			if(s[i - 1] == '<'){
				if(j) dp[i][j] = pre[i - 1][j - 1];
			}
			else{
				if(i != j) dp[i][j] = suf[i - 1][j];
			}
		}
		pre[i][0] = dp[i][0];
		suf[i][n - 1] = dp[i][n - 1];
		for(int j = 1; j < n; ++j){
			pre[i][j] = ad(pre[i][j - 1], dp[i][j]);
			suf[i][n - j - 1] = ad(suf[i][n - j], dp[i][n - j - 1]);
		}
	}
	for(int i = 0; i < n; ++i){
		ans = ad(ans, dp[n - 1][i]);
	}
	cout << ans;
	return 0;
}
