#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;

int n, k, h[MAXN], dp[MAXN];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> h[i];
	for(int i = 1; i < n; ++i){
		dp[i] = 1e9;
		for(int j = max(0, i - k); j < i; ++j){
			dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
		}
	}
	cout << dp[n - 1];
	return 0;
}
