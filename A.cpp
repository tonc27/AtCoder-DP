#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int n, h[MAXN], dp[MAXN];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> h[i];
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; ++i) dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	cout << dp[n-1];
	return 0;
}
