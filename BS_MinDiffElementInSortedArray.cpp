#include<bits/stdc++.h>

int SearchMinDiffElement(int a[],int n,int key){
  int l=0,h=n-1;
  int mindiff= INT_MAX, res = -1;

  while(l<=h){
    int mid = l + (h-l)/2;
    if(a[mid] == key) return mid;

    int diff = abs(a[mid] - key);
    if(diff < mindiff){
      mindiff = diff;
      res = mid; 
    }

    if(a[mid] < key)  l = mid+1;
    else h = mid-1;
  }
return res;
}
int main(){
  int a[] = {1,3,8,10,15};
  SearchMinDiffElement(a,5,12);
  return 0;
}
