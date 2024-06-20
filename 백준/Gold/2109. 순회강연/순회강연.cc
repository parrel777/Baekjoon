#include <iostream>
#include <queue>
#include <cmath>
#define p pair<int, int>

using namespace std;

int N;
bool dcnt[10002] = {0,};
int total=0;
priority_queue<p, vector<p> > pq;

int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		pq.push({a, b});
	}
	
	while(!pq.empty()){
		int day = pq.top().second;
		bool find = 0;
		
		for(int i=day; i>0; i--){
			if(!dcnt[i]){
				day = i;
				dcnt[i] = 1;
				find = 1;
				break;
			}
		}
		
		if(!find){
			pq.pop();
			continue;
		}
		
		total += pq.top().first;
		pq.pop();
	}
	
	cout << total;
	
	return 0;
}