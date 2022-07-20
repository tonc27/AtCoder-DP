#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int MOD = 1e9 + 7;

string k;
int d, n, dp[MAXN * MAXN][MAXN][2];

int main(){
	cin >> k >> d;
	k = '0' + k;
	n = k.length();
	dp[n][0][0] = dp[n][0][1] = 1;
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j < d; ++j){
			dp[i][j][1] = dp[i + 1][(j - (k[i] - '0') + 10*d) % d][1];
			for(int x = 0; x <= 9; ++x){
				dp[i][j][0] = (dp[i][j][0] + dp[i + 1][(j - x + 10*d) % d][0]) % MOD;
				if(x < k[i] - '0'){
					dp[i][j][1] = (dp[i][j][1] + dp[i + 1][(j - x + 10*d) % d][0]) % MOD;
				}
			}
		}
	}
	cout << (dp[0][0][1] - 1 + MOD) % MOD;
	return 0;
}
