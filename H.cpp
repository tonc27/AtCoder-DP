#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MOD = 1e9 + 7;
int h, w, dp[MAXN][MAXN];
char c[MAXN][MAXN];

int main(){
	cin >> h >> w;
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j) cin >> c[i][j];
	}
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			if(i == 1 && j == 1) dp[i][j] = 1;
			else if(c[i][j] == '.'){
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[h][w];
	return 0;
}
