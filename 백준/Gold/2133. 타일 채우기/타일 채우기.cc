#include <iostream>
using namespace std;

int main()
{

    int N;
    cin >> N;

    int d[31];
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;

    for (int i = 3; i <= N; i++){
        if (i % 2 != 0) 
			d[i] = 0;
        
        else{
            for (int j = 2; j <= N; j += 2){
                if (j == 2) 
					d[i] = d[i - j] * d[2];
                else if((i-j) >= 0) 
					d[i] += d[i - j] * 2;
            }
        }
    }
    cout << d[N];
}