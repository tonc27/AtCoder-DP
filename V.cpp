#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int n, MOD, dp[MAXN], up[MAXN];
vector<int> adj[MAXN], tree[MAXN];

int ad(int a, int b){ return (a + b >= MOD)? a + b - MOD : a + b; }
int sub(int a, int b){ return (a - b < 0) ? a - b + MOD : a - b; }
int mul(int a, int b){ return (long long) a * b % MOD; }

int dfs(int node, int anc){
	dp[node] = 1;
	for(int x : adj[node]){
		if(x == anc) continue;
		tree[node].push_back(x);
		dp[node] = mul(dp[node], ad(dfs(x, node), 1));
	}
	return dp[node];
}
void calc(int node, int anc){
	up[node] = ad(up[node], 1);
	vector<int> pre(tree[node].size()), suf(tree[node].size());
	for(int i = 0; i < tree[node].size(); ++i){
		pre[i] = mul(i ? pre[i - 1] : 1, ad(1, dp[tree[node][i]]));
	}
	for(int i = tree[node].size() - 1; i >= 0; --i){
		suf[i] = mul((i == tree[node].size() - 1) ? 1 : suf[i + 1], ad(1, dp[tree[node][i]]));
	}
	for(int i = 0; i < tree[node].size(); ++i){
		int val = mul(i ? pre[i - 1] : 1, (i == tree[node].size() - 1) ? 1 : suf[i + 1]);
		val = mul(val, up[node]);
		up[tree[node][i]] = val;
		calc(tree[node][i], node);
	}
}

int main(){
	cin >> n >> MOD;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	calc(0, -1);

	for(int i = 0; i < n; ++i){
		cout << mul(dp[i], up[i]) << "\n";
	}
	return 0;
}
