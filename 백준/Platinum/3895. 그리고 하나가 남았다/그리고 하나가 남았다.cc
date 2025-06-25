#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	while(1){
		int n, k, m;
		vector<int> v;
		
		cin >> n >> k >> m;
		if(n==0 && k==0 && m==0) break;
		
		for(int i=0; i<n; i++) v.push_back(i+1);
		
		int pt = m - 1; //eraser pointer
		
		while(v.size() > 1){
			v.erase(v.begin() + pt);
			pt = (pt + k - 1) % v.size();
		}
		
		cout << v[0] << "\n";
	}
	return 0;
}