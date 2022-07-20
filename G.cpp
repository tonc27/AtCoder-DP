#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;

int n, m, in[MAXN], dp[MAXN], ans;
vector<int> adj[MAXN];
queue<int> q;

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		++in[v];
	}
	for(int i = 0; i < n; ++i){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int node = q.front(); q.pop();
		for(int x : adj[node]){
			dp[x] = max(dp[x], dp[node] + 1);
			--in[x];
			if(!in[x]) q.push(x);
		}
	}
	for(int i = 0; i < n; ++i) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}
