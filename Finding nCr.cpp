#include <iostream>
using namespace std;
unsigned long long nCr(int n,int r,int m){
    if(n<=0 || r<0) return 0;
    
    if(r > n/2) r = n-r;
    
    unsigned long long val = 1;
    for(int i=0; i<r; i++){
        val = val * (n-i);
        val = val % m;
        val = val / (i+1);
    }
    return val;
}
int main() {
	cout<<"GfG!";
	int n,r,m;
	cin>>n>>r>>m;
	
	unsigned long long val = nCr(n,r,m);
	cout<<val<<"\n";
	
	return 0;
}
