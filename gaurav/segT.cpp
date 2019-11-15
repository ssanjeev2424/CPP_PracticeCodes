#include <bits/stdc++.h>
using namespace std;

/* SEGMENT TREES...
it's a complete binary tree

if the array size is not a power of 2, we may need to add few dummy values
to the array(which won't affect the ans) to make it a proper power of 2
eg. we want to find sumHeads(l,r), we can add tails(it's called empty value)

time to build the tree-->O(4N)-->O(N)
update takes O(logN)
range query takes O(logN)...remember how query call is transfered to childs

technique of passing info from children to parent only when required is 
called LAZY propagation

*****************Persistent Segment Trees****************
persistent DS-->> can be queried for different times, at t=2 and t=3,    					answer may change. 
in update query, we don't update the old data, we just add the pointer from
that place to a new node with the new value

*/

int main()
{

return 0;
}
/* flipping Coins..array containing 0s(tails) and 1s(heads). 
sum(l,r)--> sum of all heads between l and r
*/

//see Prefix Sum applications-->> sum of elements from index i to j. but it's an O(N) update , but sum(i,j) is O(1) after building the prefixSum arr

//update Ranges-->update(l,r) 
