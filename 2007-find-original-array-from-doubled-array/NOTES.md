1. n = array.size()
2. if n == odd cannot be doubled array
3. if n == even then check these
4. half of elements are twice of other half
5. count elements and check cnt == n/2
t.c = O(nlogn)
s.c = O(n)
​
dp : partition a subset into 2 such that
1. equal size partitons
2. sum(s1) == Sum(s2)/2;
​
​