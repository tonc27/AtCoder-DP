#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;

int n, k, a[101];
bool dp[MAXN][2];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i <= k; ++i){
		dp[i][0] = 1;
		for(int j = 0; j < n; ++j){
			if(i - a[j] >= 0){
				dp[i][0] &= dp[i - a[j]][1];
				dp[i][1] |= dp[i - a[j]][0];
			}
		}
	}
	cout << (dp[k][0]? "Second" : "First");
	return 0;
}
