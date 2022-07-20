#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;

string s, t, ans;
int dp[MAXN][MAXN];

int main(){
	cin >> s >> t;
	for(int i = 1; i <= s.length(); ++i){
		for(int j = 1; j <= t.length(); ++j){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	int i = s.length(), j = t.length();
	while(dp[i][j]){
		assert(i >= 0 && j >= 0);
		if(dp[i][j] == dp[i - 1][j]) i -= 1;
		else if(dp[i][j] == dp[i][j - 1]) j -= 1;
		else{
			ans += s[i - 1];
			i -= 1; j -= 1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
