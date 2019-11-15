#include <bits/stdc++.h>
using namespace std;

/* Segment Trees-->> DS used on arrays to answer range queries faster in
 just logN time.
 ex: sum(idx1 to idx2), update(idx i to value 10)

Brute force: sum(i,j)-->> O(N),  update(i,val)-->>O(1)
Seg Tree: sum(i,j) nd update in O(logN)

so if we r having lots of updates md very less sum operations, brute force
could be chosen.             And if lots of updates nd lots of sum queries
go for Segment trees.

In Seg trees, leaf nodes(values) are exactly the array elements..
Internal nodes is the sum of its children node's values.
i.e every node is storing the values of some segment of the array
we can distinguish the segments using starting nd ending index of array

as we move up, segment size increases by 2 at each lvl
height of tree is logN
#nodes = 2N-1, i.e O(N)
*/
int main()
{

return 0;
}
