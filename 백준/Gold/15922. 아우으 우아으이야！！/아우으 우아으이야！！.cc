#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s, e; 
int len = 0;
vector <pair<int, int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	s = e = -1000000001;
	
	for(int i=0; i<N; i++){
		// 1. include
		// 2. new
		if(v[i].first > e){
			len += e - s;
			s = v[i].first;
		}
		// 3. extend
		if(v[i].second > e){
			e = v[i].second;
		}
	}
	
	len += e - s;
	
	cout << len;
	
	return 0;
}