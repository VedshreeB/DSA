#include <iostream>
using namespace std;

bool isPrime(int num){
    for(int i=2; i<=num/2 ; i++){
        if(num%i==0)    
            return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    
    //print all prime factors of n
    //1 is neither prime nor a composite
   
    for(int i=2; i<=n ; i++){
        if(isPrime(i) && n%i == 0)
            cout<<i<<" ";
    }
    
    return 0;
}
