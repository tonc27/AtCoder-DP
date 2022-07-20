#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1 << 21);
const int MOD = 1e9 + 7;

int n, dp[MAXN];
bool a[21][21];
vector<int> v[22];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	dp[0] = 1;
	for(int i = 1; i < (1 << n); ++i) v[__builtin_popcount(i)].push_back(i);
	for(int i = 1; i <= n; ++i){
		for(int x : v[i]){
			for(int j = 0; j < n; ++j){
				if(a[i - 1][j] && x & (1 << j)){
					dp[x] = (dp[x] + dp[x ^ (1 << j)]) % MOD;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1];
	return 0;
}
