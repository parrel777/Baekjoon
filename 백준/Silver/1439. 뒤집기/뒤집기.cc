#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    bool inst = false;
    string a;
    int zero = 0;
    int one = 0;

    cin >> a;

    if(a[0] == '0'){
        inst = false;
    }
    else{
        inst = true;
    }

    for(int i=0; i<a.size(); i++){
        if(inst == false){
            if(a[i] == '0'){
                zero += 1;
                inst = true;
            }
        }
        if(inst == true){
            if(a[i] == '1'){
                one += 1;
                inst = false;
            }
        }

    }

    cout << ((zero > one)? one : zero);


}
