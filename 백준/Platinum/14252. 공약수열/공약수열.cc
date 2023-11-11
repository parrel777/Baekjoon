#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int childex(int x, int y){
	if(x==1) return 0;
	
	for(int i=2; i<=x; i++){
		if(y % i == 0 && x % i == 0) return 1; //have child
	}
	
	return 0; //dont have child Or cant make child
}

int find(int x, int y){ //to find child
	for(int i=x+1; i<y; i++){
		if(!childex(x, i) && !childex(i, y)) return i;
	}
	
	return x+1; //if cant make child return it, ex) 2184 "2195 2199" 2200
}

int main(){
	vector<int> v;
	int N, a;
	
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	int roll = v.size();
	int i=0, total=0;
	
	while(roll > 1){
		if(!childex(v[i], v[i+1])){ //dont have child
			roll--;
			i++;
		}
		else{
			v.insert(v.begin() + i + 1, find(v[i], v[i+1]));
			i++;
			total++;
		}
	}
	
	cout << total;
}