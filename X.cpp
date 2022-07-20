#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define first X
#define second Y

const int MAXN = 1001;
typedef long long ll;

int n;
ll dp[MAXN][20*MAXN], ans;

struct Item{
	int w, s, v;
	inline void load(){
		int _w, _s, _v;
		cin >> _w >> _s >> _v;
		w = _w, s = _s, v = _v;
	}
} a[MAXN];

const bool cmp(Item& a, Item& b){
	return (a.w + a.s < b.w + b.s);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		a[i].load();
	}
	sort(a, a + n, cmp);
	dp[0][a[0].w] = a[0].v;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < MAXN * 20; ++j){
			dp[i][j] = dp[i-1][j];
			if(a[i].w <= j && j <= a[i].s + a[i].w){
				dp[i][j] = max(dp[i][j], dp[i-1][j - a[i].w] + a[i].v);
			}
		}
	}
	for(int j = 0; j < MAXN * 20; ++j){
		ans = max(ans, dp[n-1][j]);
	}
	cout << ans;
	return 0;
}
