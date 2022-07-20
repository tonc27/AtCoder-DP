#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;

int ad(int a, int b){ return (a + b >= MOD) ? a + b - MOD : a + b; }
int mul(int a, int b){ return (long long) a * b % MOD; }

int n, dp[MAXN][2];
bool bio[MAXN][2];
vector<int> adj[MAXN];

int dfs(int node, int anc, bool col){
	int &ref = dp[node][col];
	if(bio[node][col]) return ref;
	bio[node][col] = 1;
	ref = 1;
	for(int x : adj[node]){
		if(x == anc) continue;
		if(col) ref = mul(ref, dfs(x, node, !col));
		else ref = mul(ref, ad(dfs(x, node, 0), dfs(x, node, 1)));
	}
	return ref;
}

int main(){
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << ad(dfs(0, -1, 0), dfs(0, -1, 1));
	return 0;
}
