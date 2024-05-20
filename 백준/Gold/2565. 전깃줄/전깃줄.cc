#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int N, ans = 0;
	vector<pair<int, int> > v;
	int dp[501] = {0,};
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	for(int k=0; k<N; k++){
		dp[k] = 1;
		
		for(int i=0; i<k; i++){
			if(v[i].second < v[k].second){
				dp[k] = max(dp[i] + 1, dp[k]);
			}
		}
		
		ans = max(ans, dp[k]);
	}
	
	cout << N - ans;
	
	return 0;
}