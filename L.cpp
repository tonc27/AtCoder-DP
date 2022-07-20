#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;

int n, a[MAXN];
long long dp[MAXN][MAXN];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int off = 0; off < n; ++off){
		for(int i = 0; i < n - off; ++i){
			int j = i + off;
			if((n + off) & 1){
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
			}
			else{
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}
