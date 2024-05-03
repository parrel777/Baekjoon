#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		
		if(v.empty() || v.back() < m) {
			v.push_back(m);
		}
		else {
			*lower_bound(v.begin(), v.end(), m) = m;
		}
	}
	
	cout << v.size();
	
	return 0;
}