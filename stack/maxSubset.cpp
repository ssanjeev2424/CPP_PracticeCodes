#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
// print max of each subArray of size K.
int main()
{
	int t; cin>>t;
	while(t--) {
	
		int n,k; cin>>n>>k;
		int arr[n+1]; for(int i=1;i<=n;i++) cin>>arr[i];

		int stock[n+1], end;
		stack<int> stk;
		stk.push(-1); stk.push(1); stock[1] = 1;

		while(!stk.empty()) stk.pop();

		stk.push(-1); stk.push(1); stock[n] = 1;

		for(int i=n-1;i>=1;i--)
			{
			int ans = 1, idx = i+1, cnt = 0;
			while(arr[idx] <= arr[i] && idx <= n)
				{
				ans += stock[idx];
				cnt++;
				idx += stock[idx];
				}
			
			for(int j=0;j<cnt;j++)
				stk.pop();
			stk.push(ans);
			stock[i] = ans;
			}

		//cout<<"<==From right==>\n";
		//for(int i=1;i<=n;i++) cout<<stock[i]<<" "; cout<<endl; 

		int total = n - k + 1; // numbers of output elements
		int winSize = 0, spanR = 0, spanL = 0, span, winStart = 1;
		for(int i=1; i<=n; i++) {
			//cout<<"\n****index: "<<i<<" winStart: "<<winStart<<" winSize: "<<winSize<<" ***********\n";
			if(!total) break;
			
			if(stock[i]-1 > k - (winSize+1)) {
				spanR = (stock[i]-1) - (k - (winSize+1));
				spanL = i - winStart;
				span = min(spanL, spanR);
				
				int item = arr[i];
				cout<<item<<" "; total--;
				if(!total) break;
				
				for(int j=0; j<span; j++) {
					cout<<item<<" "; total--;
					if(!total) break;
				}
				
				winStart += span + 1;
				if(span != spanL) {
					i += (k - (winSize+1)) + span;
					winSize = i + 1 - winStart;
				}
				else
					winSize = 0;
			}
			else if(stock[i]-1 == k - (winSize+1)) {
			
				cout<<arr[i]<<" "; total--;
				if(!total) break;
				
				i += stock[i] - 1; winSize = k-1;
				winStart++;
			}
			else
				winSize++;
			//cout<<"\n-----------index: "<<i<<" winStart: "<<winStart<<" winSize: "<<winSize<<" ----------\n";
		}
		cout<<endl;
	}
	return 0;
	}
