#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
typedef long double ld;

int n, c[3];
ld dp[MAXN][MAXN][MAXN], ans;

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		++c[a - 1];
	}
	for(int k = 0; k <= n; ++k){
		for(int j = 0; j <= n; ++j){
			for(int i = 0; i <= n; ++i){
				if(i + j + k > 0) dp[i][j][k] = (ld) n / (i + j + k);
				if(i > 0) dp[i][j][k] += (ld) i / (i + j + k) * dp[i - 1][j][k];
				if(j > 0) dp[i][j][k] += (ld) j / (i + j + k) * dp[i + 1][j - 1][k];
				if(k > 0) dp[i][j][k] += (ld) k / (i + j + k) * dp[i][j + 1][k - 1];
			}
		}
	}
	cout << setprecision(10) << dp[c[0]][c[1]][c[2]];
	return 0;
}
