#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	int j=1;
	for(int i=0; i<s.length(); i++){
	    if(j==1 && s[0] == '9'){
	        j++;
	        continue;
	    }
	    if(s[i]-'0' <= 4) continue;
	    
	    int x = 9 - (s[i]-'0');
	    s[i] = char(x) + '0';
	}
	cout<<s<<endl;
	return 0;
}
/*
91730629
Output
91730629
Answer
91230320

*/
