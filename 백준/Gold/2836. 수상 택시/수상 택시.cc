#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N, M, s;
long long start=0, stop=0, total=0;
vector<pair<int, int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	total += M;
	
	for(int i=0; i<N; i++){
		int s, e;
		cin >> s >> e;
		if(s > e)
			v.push_back({e, s});
	}
	
	sort(v.begin(), v.end());
	
	s = v.size();
	
	for(int i=0; i<s; i++){
		//new
		if(v[i].first > stop){
			total += (stop - start) * 2;
			start = v[i].first;

		}
		//extend
		if(v[i].second > stop){
			stop = v[i].second;
		}
	}
	
	total += (stop - start) * 2;
	
	cout << total;
	
	return 0;
}
