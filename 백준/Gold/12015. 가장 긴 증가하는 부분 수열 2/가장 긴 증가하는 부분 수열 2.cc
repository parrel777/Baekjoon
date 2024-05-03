#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int main(){
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