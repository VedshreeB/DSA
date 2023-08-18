#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    //print all factors of n
    //1 and n are factors of n always
    cout<<"1 ";
    
    for(int i=2; i<=n ; i++){
        if(n%i == 0)
            cout<<i<<" ";
    }
    
    return 0;
}
