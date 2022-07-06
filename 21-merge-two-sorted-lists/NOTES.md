Brute force:
L1 ->n L2->m
T.C = O((n+m)log(n+m))
Better:
h1
1->2->4
1->3->4->5->6
h2
1->1->2->3->4->4->5->6;
T.C = O(n+m)
S.C = O(n+m)
Optimized:
res/   t
1     2->4
|     /  |     h1
|  /
1       3->4->5
h2
T.C = O(