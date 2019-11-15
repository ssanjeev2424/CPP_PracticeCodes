#include<bits/stdc++.h>

#define N 100002
using namespace std;
int n, m;
long long r[N], c[N];
long long tree[4 * N], lazy[4*N];

int update(int si, int ss, int se, int us, int ue, int diff) { 
    if (lazy[si] != 0){ 
        tree[si] += (long long)(se-ss+1)*lazy[si]; 
        if (ss != se){ 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>ue || se<us || tree[si] < 0) 
        return 0; 
    if (ss>=us && se<=ue){ 
        tree[si] += (se-ss+1)*diff; 
        if (ss != se) { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return tree[si] >= 0; 
    } 
    int mid = (ss+se)/2; 
    int ret = update(si*2+1, ss, mid, us, ue, diff) && 
    update(si*2+2, mid+1, se, us, ue, diff); 
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
	return ret;
}

int query(int si, int ss, int se) {
	if (lazy[si] != 0){ 
        tree[si] += (long long)(se-ss+1)*lazy[si]; 
        if (ss != se){ 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
        lazy[si] = 0; 
    }
	if(tree[si] <= 0)
		return -1;
	if(ss == se)
		return ss;
	int mid = (ss + se)/2;
	int x = query(2*si + 1, ss, mid);
	if(x == -1)
		x = query(2*si+2, mid+1, se);
	return x;
}

void construct(long long arr[], int ss, int se, int si) { 
    if (ss > se) 
        return ; 
    if (ss == se) { 
        tree[si] = arr[ss];
		lazy[si] = 0; 
        return; 
    } 
    int mid = (ss + se)/2; 
    construct(arr, ss, mid, si*2+1); 
    construct(arr, mid+1, se, si*2+2); 
	lazy[si] = 0;
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long rs=0, cs=0, mr = 0, mc = 0;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++){
			scanf("%lld",&r[i]);
			mr = max(mr, r[i]);
			rs += (long long)r[i];
		}
		sort(r, r+n, greater<>());
		for(int i=0; i<m; i++){
			scanf("%lld",&c[i]);
			mc = max(mc, c[i]);
			cs += (long long)c[i];
		}	
		if(rs != cs) {
			printf("NO\n");
			continue;
		}
		sort(c, c+m);
		construct(c, 0, m-1, 0);

		int flag = 1;
		for(int i = 0; i<n; i++){
			if(r[i] == 0) continue;
			int idx = query(0, 0, m-1);
			//printf("idx: %d\n",idx);
			if(idx == -1 || idx + r[i] > m){
				flag = 0;
				break;
			}
			
			update(0, 0, m-1, idx, idx+r[i]-1, -1);
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}		
	return 0;
}
