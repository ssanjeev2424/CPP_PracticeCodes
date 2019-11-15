	#include <bits/stdc++.h>
	using namespace std;
	#define lli long long int
	int supw(int*,int,int,int); void smartPhone(); void game();
	void tournament(); void variation(); void brackets(); void sequence();
	void matchedBr(int *arr,int idx,int len,int inside,int depth);
	int n,maxDep,maxDepIdx,maxBet,maxBetIdx; void gum();
	int dfs(int,vector<vector<int> > &v, int); void iplMain();
	bool matchK(vector<int> &v1,vector<int> &v, int);
	int ipl(int*,int,int,int); void table();
	int dinner(int*,int,int,int,int);
	
	int dp[200001][3], ans, dp_ipl[200001][3], dpTable[1000001][4];
	bool visited[301];

	int main()
	{
	gum();

	/*cin>>n;  //SUPW
	int arr[n];
	for(int i=0;i<n;i++) 
		{
		cin>>arr[i];
		dp[i][0] = dp[i][1] = dp[i][2] = -1;
		}
	ans=0;

	cout<<supw(arr,0,n,0);
	*/
	return 0;
	}

	void table()
	{
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		{
		cin>>arr[i];
		dpTable[i][0] = dpTable[i][1] = dpTable[i][2] = dpTable[i][3] = -1;
		}
	int ans = min(dinner(arr,1,n,0,0),arr[0]+dinner(arr,1,n,1,1) );
	cout<<ans<<endl;
	}
	
	int dinner(int *arr, int idx, int len, int prev, int arthur)
	{
	if(idx==len-1)
		{
		if(arthur==0 || prev==0) return arr[idx];
		return 0;
		}
	if(prev==0 && arthur==0 && dpTable[idx][0] != -1)
		return dpTable[idx][0];
	if(prev==0 && arthur==1 && dpTable[idx][1] != -1)
		return dpTable[idx][1];
	if(prev==1 && arthur==0 && dpTable[idx][2] != -1)
		return dpTable[idx][2];
	if(prev==1 && arthur==1 && dpTable[idx][3] != -1)
		return dpTable[idx][3];
	
	if(prev==0)
		{
		if(arthur==0)
		return dpTable[idx][0] = arr[idx]+dinner(arr,idx+1,len,1,arthur);
		//or simply put arthur in the 2nd index of dp
		return dpTable[idx][1] = arr[idx]+dinner(arr,idx+1,len,1,arthur);
		}
	
	return dpTable[idx][2+arthur] = min(dinner(arr,idx+1,len,0,arthur),arr[idx]+dinner(arr,idx+1,len,1,arthur) );
	}
	
	void sequence() //it's from INOI contest.. my bad
	{
	int n,k,num; cin>>n>>k;
	for(int i=0;i<n;i++) visited[i]=false;
	
	vector< vector<int> > vec;
	for(int j=0;j<n;j++)
		{
		cin>>num;
		vector<int> seq(num); //one sequence
		for(int k=0;k<num;k++)
			cin>>seq[k];
		
		sort(seq.begin(), seq.end());
		vec.push_back(seq);
		}
	
	visited[0] = true;
	cout<<dfs(0,vec,k)<<endl;
	}
	
	int dfs(int curr, vector<vector<int> > &vec, int k)
	{
	int count = 1;
	
	for(int i=1;i<vec.size();i++)
		{
		if( !visited[i] && matchK(vec[curr],vec[i],k) )
			{
			visited[i] = true;
			count += dfs(i,vec,k);
			}
		}
	return count;
	}
	
	bool matchK(vector<int> &a, vector<int> &b, int k)
	{
	int count=0;
	
	for(int i=0;i<a.size();i++)
		{
		if(count==k) return true;
		
		if(binary_search(b.begin(),b.end(),a[i]))
			count++;
		}
	
	return (count >= k);
	}
	
	void gum()
	{
	long long n,k; cin>>n>>k; long long arr[n], count=0, temp;
	int idx=0,i,j;
	for(i=0;i<n;i++)
		{
		scanf("%lld",&temp);
		
		if(temp<k) 
			arr[idx++] = temp;
		}
	
	sort(arr,arr+idx);
	
	int half;
	if(k&1) half = k/2 + 1;
	else half = k/2;
	
	for(i=0;i<idx;i++)
		{
		if(arr[i]>=half)
			break;
		}
	count += i*(i-1)/2;
	
	for(;i<idx;i++)
		{
		for(j=0;j<i;j++)
			if(arr[i]+arr[j]>=k) break;
		count += j;
		}
	cout<<count<<endl;
	}

	void brackets()
	{
	maxDep = maxBet = 0;
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	matchedBr(arr,0,n,0,0);
	
	cout<<maxDep<<" "<<maxDepIdx+1<<" "; //1 added coz of 0-indexing
	cout<<maxBet<<" "<<maxBetIdx-maxBet+1+1<<endl; //same
	}
	
	void matchedBr(int *arr,int idx,int len,int inside,int depth)
	{
	if(idx==len) return;
	
	if(arr[idx]==1)
		{
		depth++;
		if(depth>maxDep)
			{
			maxDep = depth;
			maxDepIdx = idx;
			}
		matchedBr(arr,idx+1,len,inside+1,depth);
		}
	else
		{
		depth--;
		inside++;
		if(depth==0)
			{
			if(inside>maxBet)
				{
				maxBet = inside;
				maxBetIdx = idx;
				}
			matchedBr(arr,idx+1,len,0,0);
			return;
			}
		matchedBr(arr,idx+1,len,inside,depth);
		}
	} 
	
	void variation()
	{
	int n,k; cin>>n>>k; int arr[n], count=0;
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
	sort(arr, arr+n);
	
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[j]-arr[i] >= k)
				{
				count += (n-j); // (n-1)-j+1
				break;
				}
	cout<<count<<endl;
	}
	
	void tournament()
	{
	int n; cin>>n; lli arr[n], rev=0;
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
		rev += arr[i]*i - (n-i-1)*arr[i];
	
	cout<<rev<<endl;
	}

	void game()
	{
	int n,h; scanf("%d %d",&n,&h);
	int arr[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int occupied=0, upon=0;
	int temp; cin>>temp;

	while(temp != 0)
		{
		if(temp==1)
			{
			if(upon==0) { cin>>temp; continue; }
			upon--;
			cin>>temp;
			}
		else if(temp==2)
			{
			if(upon==n-1) { cin>>temp; continue; }
			upon++;
			cin>>temp;
			}
		else if(temp==3)
			{
			if(occupied==1 || arr[upon]==0) { cin>>temp; continue; }
			arr[upon]--; occupied = 1;
			cin>>temp;
			}
		else
			{
			if(occupied==0 || arr[upon]==h) { cin>>temp; continue; }
			arr[upon]++; occupied = 0;
			cin>>temp;
			}
		}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	}

	void smartPhone()
	{
	int n1; cin>>n1;
	lli budget[n1], maxRev=0, temp;

	for(int i=0;i<n1;i++) scanf("%lld",&budget[i]);
	sort(budget, budget+n1);

	for(int i=0;i<n1;i++)
		{
		if(i != 0 && budget[i]==budget[i-1]) continue;
		if( (temp = budget[i]*(n1-i) ) > maxRev) maxRev = temp;
		}
	cout<<maxRev<<endl;
	}

	int supw(int *arr, int idx, int len, int skipped)
	{
	if(idx >= len) return 0;

	if(dp[idx][skipped] != -1) return dp[idx][skipped];

	if(skipped==2)
		return dp[idx][skipped] = arr[idx] + supw(arr,idx+1,len,0);

	return dp[idx][skipped] = min(arr[idx]+supw(arr,idx+1,len,0), supw(arr,idx+1,len,skipped+1));
	}
	
	void iplMain()
	{
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		{
		cin>>arr[i];
		dp_ipl[i][0] = dp_ipl[i][1] = dp_ipl[i][2] = -1;
		}
	cout<<ipl(arr,0,n,0)<<endl;
	}
	
	int ipl(int *arr, int idx, int len, int consecu)
	{
	if(idx == len) return 0;
	
	if(dp_ipl[idx][consecu] != -1) return dp_ipl[idx][consecu];
	
	if(consecu==2)
		return dp_ipl[idx][consecu] = ipl(arr,idx+1,len,0);
	
	return dp_ipl[idx][consecu] = max( ipl(arr,idx+1,len,0), arr[idx]+ipl(arr,idx+1,len,consecu+1) );
	}
