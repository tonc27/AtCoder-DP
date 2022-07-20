#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;

int n, a[MAXN][3], dp[MAXN][3];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j) cin >> a[i][j];
	}
	for(int i = 0; i < 3; ++i) dp[0][i] = a[0][i];
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			dp[i][j] = a[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	return 0;
}
