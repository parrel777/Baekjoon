#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int arr[1001];
	int dp[1001];
	int a[1001];
	int ans = 0;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int k=0; k<N; k++){
		dp[k] = 1;
		for(int i=0; i<k; i++){
			if(arr[i] < arr[k]){
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
		
		ans = max(dp[k], ans);
	}
	
	cout << ans << '\n';
	
	int temp = ans;
	
	for(int i=N; i>=0; i--){
		if(dp[i] == temp){
			a[temp-1] = arr[i];
			temp--;
		}
		if(temp == -1) break;
	}
	
	for(int i=0; i<ans; i++){
		cout << a[i] << ' ';
	}
	
	return 0;
}