#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define BLK 174
int cnt[1000001], arr[30011], n;

// using MO's algo
//https://blog.anudeep2011.com/mos-algorithm/

typedef struct query {
	int l;
	int r;
	int idx;
} Q;

Q qr[200005];
int ans[200005] = {0};

int cmp(const void *f, const void *s) {
	int a = ((struct query*)f)->l;
	int b = ((struct query*)f)->r;
	int c = ((struct query*)s)->l;
	int d = ((struct query*)s)->r;
	
	if(a/BLK == c/BLK) return (b - d);
	
	return (a - c);
}


int cmp1(const void *f, const void *s) {
	int a = ((struct query*)f)->idx;
	int b = ((struct query*)s)->idx;
	return a - b;
}

int curL = 0, curR = 0, Ans = 0;

void add(int idx) {
	if(cnt[arr[idx]] == 0)
		Ans++;
	cnt[arr[idx]]++;
}

void remove(int idx) {
	if(cnt[arr[idx]] == 1)
		Ans--;
	cnt[arr[idx]]--;
}

int solve(int l, int r) {
	while(curL < l) {
		remove(curL);
		curL++;
	}
	while(curL > l) {
		add(--curL);
	}
	while(curR <= r) {
		add(curR++);
	}
	while(curR > r+1) {
		remove(curR-1);
		curR--;
	}
	return Ans;
}

int Scanf(){
    	int num = 0;
       	char c = getchar_unlocked();
       	int flag = 0;
       	while(!((c>='0' & c<='9') || c == '-'))
       	    c=getchar_unlocked();
       	if(c == '-') {
       	    flag = 1;
       	    c=getchar_unlocked();
       	}
       	while(c>='0' && c<='9') {
       	    num = (num<<1)+(num<<3)+c-'0';
       	    c=getchar_unlocked();
       	}
       	if(flag==0)
       	    return num;
       	else
       	    return -1*num;
}

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	n = Scanf();
	for(int i=0; i<n; i++) 
		arr[i]=Scanf();
	q= Scanf();
	
	for(int i=0; i<q; i++) {
		qr[i].l = Scanf(); 
		qr[i].r = Scanf();
		qr[i].l--;
		qr[i].r--;
		qr[i].idx = i;
	}
	qsort(qr, q, sizeof(Q), cmp);
	
	for(int i=0; i<q; i++)
		ans[qr[i].idx] = solve(qr[i].l, qr[i].r);
		
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
	
	return 0;
}
