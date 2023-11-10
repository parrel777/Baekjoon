#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

int main(){
	int N, S;
	vector<pair<int, int> > v;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		int s, e;
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	
	sort(v.begin(), v.end());
	
	pq.push(v[0].second);
	
	S = v.size();
	
	for (int i=1; i<S; i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
	
	return 0;
}
