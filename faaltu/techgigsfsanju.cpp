#include<bits/stdc++.h>

typedef long long ll
using namespace std;

int n, m;
ll st[4*100001], lz[4 * 100001], r[100005], c[100005];

ll update(int node, int s, int e, int us, int ue) {

	if(lz[node] != 0) {
		st[node] += (e-s+1)*lz[node];
		if(s != e) {
			lz[node*2+1] += lz[node];
			lz[node*2+2] += lz[node];
		}
		lz[node] =0;
	}
	if(s>e || s>ue || e < s || st[node] < 0)
		return 0;
    if (s>=us && e<=ue){ 
        st[node] -= (e-s+1); 
        if (s != e) { 
            lz[node*2 + 1]--; 
            lz[node*2 + 2]--; 
        } 
        return st[node] >= 0; 
    } 
    int madhya = (s+e)/2; 
    int ret = update(node*2+1, s, madhya, us, ue) && 
    update(node*2+2, madhya+1, e, us, ue); 
    st[node] = st[node*2+1] + st[node*2+2]; 
	return ret;
}

void buildst(int s, int e, int node) { 
    if (s > e) 
        return ; 
    if (s == e) { 
        st[node] = c[s];
		lz[node] = 0; 
        return; 
    } 
    int madhya = (s + e)>>1; 
    buildst(s, madhya, node*2+1); 
    buildst(madhya+1, e, node*2+2); 
	lz[node] = 0;
    st[node] = st[node*2 + 1] + st[node*2 + 2]; 
}

int query(int node, int s, int e) {
	if (lz[node] != 0){ 
        st[node] += (long long)(e-s+1)*lz[node]; 
        if (s != e){ 
            lz[node*2 + 1]   += lz[node]; 
            lz[node*2 + 2]   += lz[node]; 
        } 
        lz[node] = 0; 
    }
	if(st[node] <= 0) return -1;
	if(s == e) return s;
	int mid = (s + e)/2;
	return query(2*node + 1, s, mid) == -1 ? query(2*node+2, mid+1, e) : x;
}

int main() {
	

}

