#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 401;
typedef long long ll;
const ll inf = (1LL << 60);

int n, a[MAXN];
ll dp[MAXN][MAXN], pre[MAXN];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	pre[0] = a[0];
	for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
	for(int off = 0; off < n; ++off){
		for(int i = 0; i < n - off; ++i){
			int j = i + off;
			dp[i][j] = (i == j) ? 0 : inf;
			for(int k = i; k < j; ++k){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j] - (i ? pre[i - 1] : 0));
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}
