#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string a, string b){
	return a+b > b+a;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	vector<string> v;
	int N, M;
	bool allzero = true;
	string ans = "";
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> M;
		if(M != 0) 
			allzero = false;
		v.push_back(to_string(M));
	}
	
	if(allzero){
		cout << 0;
		return 0;	
	}
	
	sort(v.begin(), v.end(), compare);
	
	for(int i=0; i<v.size(); i++){
		ans += v[i];
	}
	
	cout << ans;
	
	return 0;
}