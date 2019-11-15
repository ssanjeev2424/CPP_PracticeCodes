#include<bits/stdc++.h>
using namespace std;

struct lis
	{
	int len,latest;
	};
	
void ugly(); int min(int,int,int); void maxSqSubMatrix();
struct lis* longIncSubseq(int*,int,int); int lcs(string,string,int,int);
int lcs2(string,string); int minCostPath(int,int,int,int);
int min(int,int,int); int coins(int,int*,int,int);
int editDis(string,string,int,int); int lonPalSubseq(string,int,int);
int abcPath(char *,int,int,int,int,int);
int coins2(int*,int,int,int); void rodCut(int*,int,int,int,int);
int rodCut2(int*,int,int,int);

map<int,struct lis*> m; int lcsDP[50][50]; int costDP[50][50],h,w;
vector<int> cost[50]; int coinDP[100][100]; int abcDP[51][51];
bool abcVisited[51][51]; int lpsDP[100][100]; int rodDP[100][100];
int rodProfit;

int main()
{
/*int cost[3][3] = { {1,2,3},
		     {4,8,2},
		     {1,5,3} };*/
//ugly();	
//maxSqSubMatrix();

int lis[] = {10,22,9,33,21,50,41,60,80};
int lsize = sizeof(lis)/sizeof(lis[0]);
for(int i=lsize-1;i>=0;i--)//{
	m.insert({i,longIncSubseq(lis,lsize,i)});
	//cout<<m[i]->len<<" "<<m[i]->latest<<endl; }
cout<<"Max LongestIncSubseq len:"<<m[0]->len<<" and latest:"<<m[0]->latest;
cout<<endl;

memset(lcsDP,-1,sizeof(lcsDP));
cout<<"LCS length: "<<lcs("AGGTAB","GXTXAYB",0,0)<<endl;
cout<<"LCS : "<<lcs2("AGGTAB","GXTXAYB")<<endl;

memset(costDP,-1,sizeof(costDP));
cost[0].push_back(1); cost[0].push_back(2); cost[0].push_back(3);
cost[1].push_back(4); cost[1].push_back(8); cost[1].push_back(2);
cost[2].push_back(1); cost[2].push_back(5); cost[2].push_back(3);
cout<<"Min Cost Path: "<<minCostPath(2,2,0,0)<<endl;

memset(coinDP,-1,sizeof(coinDP));
int coinArr[] = {2,5,3,6};  //1,2,3-->4
int coinLen = sizeof(coinArr)/sizeof(coinArr[0]);
cout<<"Coins exchange #ways: "<<coins(10,coinArr,coinLen,0)<<endl;
cout<<"Coins #ways(DP): "<<coins2(coinArr,coinLen,0,10)<<endl;

string s1 = "sunday", s2 = "saturday+";
int editL1 = s1.length(), editL2 = s2.length();
cout<<"Min Edit Distance: "<<editDis(s1,s2,editL1,editL2)<<endl;
//cout<<m[8]<<" "<<m[2]<<" "<<m[45]; //returns 0 if key is not present

memset(abcDP,-1,sizeof(abcDP));
memset(abcVisited,false,sizeof(abcVisited));
/*char n;
cin>>n;
cout<<n+1;*/
h=4; w=3;
char abc[h][w] = {{'A','B','E'},
		          {'C','O','G'},
		          {'B','D','E'},
		          {'A','B','C'}};
/*for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
		cin>>abc[i][j];
for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
		cout<<abc[i][j]<<"*";*/

cout<<abcPath((char*)abc, 0, 0, 4, 3, 1)<<endl;

memset(lpsDP,-1,sizeof(lpsDP));
string lpsS = "BBABCBCAB"; int lpsL = lpsS.length();
cout<<"Longest Palin Subseq len: "<<lonPalSubseq(lpsS,0,lpsL-1)<<endl;

memset(rodDP,-1,sizeof(rodDP)); rodProfit = 0;
int rod[] = {1,5,8,9,10,17,17,20};
int rodLen = sizeof(rod)/sizeof(rod[0]);
cout<<"Maxm rod rokda: "; rodCut(rod,rodLen,0,0,0); cout<<rodProfit<<endl;
cout<<"Maxm rod rokda(DP): "<<rodCut2(rod,rodLen,0,rodLen-1)<<endl;
return 0;
}

int rodCut2(int *arr, int remSize, int idx, int end) //using DP
{
if(remSize==0 || idx>end) return 0;

if(remSize < 0) return INT_MIN;

if(rodDP[idx][remSize]!=-1) return rodDP[idx][remSize];

int smallAns1 = rodCut2(arr,remSize,idx+1,end);
int smallAns2 = arr[idx]+rodCut2(arr, remSize-(idx+1),idx,end);

return rodDP[idx][remSize]=(smallAns1>=smallAns2)?smallAns1:smallAns2;
}

void rodCut(int *arr, int len, int size, int idx, int sum) //no DP
{
if(idx>=len || size==len)
	{
	if(sum>rodProfit)
		rodProfit = sum;
	return;
	}
if(size > len)
	return;

rodCut(arr,len,size+idx+1,idx,sum+arr[idx]);
rodCut(arr,len,size,idx+1,sum);
}

int coins2(int *arr, int len, int idx, int sum)
{
if(sum==0) return 1;

if(idx>=len || sum<0) return 0;

if(coinDP[idx][sum] != -1) return coinDP[idx][sum];

return coinDP[idx][sum] = coins2(arr,len,idx,sum-arr[idx]) + coins2(arr,len,idx+1,sum);
}

int lonPalSubseq(string str, int l, int r)
{
if(l==r) return lpsDP[l][r] = 1;

if(lpsDP[l][r]!=-1) return lpsDP[l][r];

if(str[l] != str[r])
	return lpsDP[l][r]=max(lonPalSubseq(str,l+1,r),lonPalSubseq(str,l,r-1));

if(r == l+1) return lpsDP[l][r] = 2;

return lpsDP[l][r] = 2 + lonPalSubseq(str,l+1,r-1);
return 0;
}

int abcPath(char *arr,int l, int r, int row, int col,int path)
{
if(l>=row || r>=col || l<0 || r<0)
	return path;
if(abcDP[l][r]!=-1)
	return abcDP[l][r];
if(abcVisited[l][r])
	return INT_MIN;

int temp=INT_MIN, temp2, flag=1; abcVisited[l][r] = true;

if(r-1>=0 && *((arr+l*w)+r-1)==*((arr+l*w)+r)+1)//left
	{
	temp2 = abcPath(arr,l,r-1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}
if(l-1>=0 && r-1>=0 && *((arr+(l-1)*w)+r-1)==*((arr+l*w)+r)+1)//north west
	{
	temp2 = abcPath(arr,l-1,r-1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}
if(l-1>=0 && *((arr+(l-1)*w)+r)==*((arr+l*w)+r)+1)//north
	{
	temp2 = abcPath(arr,l-1,r,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}
if(l-1>=0 && r+1<=col && *((arr+(l-1)*w)+r+1)==*((arr+l*w)+r)+1)
	{
	temp2 = abcPath(arr,l-1,r+1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}//north east
if(r+1<=col && *((arr+l*w)+r+1)==*((arr+l*w)+r)+1)
	{
	temp2 = abcPath(arr,l,r+1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}//east
if(l+1<=row && r+1<=col && *((arr+(l+1)*w)+r+1)==*((arr+l*w)+r)+1)
	{
	temp2 = abcPath(arr,l+1,r+1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}//south east
if(l+1<=row && *((arr+(l+1)*w)+r)==*((arr+l*w)+r)+1)
	{
	temp2 = abcPath(arr,l+1,r,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}//south
if(l+1<=row && r-1>=0 && *((arr+(l+1)*w)+r-1)==*((arr+l*w)+r)+1)
	{
	temp2 = abcPath(arr,l+1,r-1,row,col,path+1); flag = 0;
	if(temp2>temp) temp = temp2;
	}//south west

if(flag) abcDP[l][r] = path;
else abcDP[l][r] = temp;
return abcDP[l][r];
}

int editDis(string str1,string str2, int len1, int len2)
{
//https://www.geeksforgeeks.org/edit-distance-dp-5/

int dp[len1+1][len2+1];

for(int i=0;i<=len1;i++)
{
	for(int j=0;j<=len2;j++)
	{
	if(i==0) dp[i][j]=j;
	
	else if(j==0) dp[i][j]=i;
	
	else
		{
		if(str1[i-1]==str2[j-1])
			dp[i][j] = dp[i-1][j-1];
		else
			dp[i][j] = 1 + min(dp[i][j-1],      //Insert in str1
							   dp[i-1][j],     //Delete
							   dp[i-1][j-1]); //Replace
		}
	}
}
return dp[len1][len2];
}

int coins(int n, int *arr, int len, int idx) //naive
{
if(n<0) return 0;

if(n==0)
	{
	if(idx==0) return 0;  //means initially
	
	if(idx<len) return 1;  // in the middle of traversal
	}
if(idx==len-1)  //last element
	{
	if(n%arr[idx]==0) return 1;
	return 0;
	}

int multiples = n/arr[idx],ans=0;
while(multiples>=0)  //choosing the current in freq 0,1,2,3,...
	{
	ans += coins(n-multiples*arr[idx],arr,len,idx+1);
	multiples--;
	}
return ans;
}

int minCostPath(int row,int col,int idx1,int idx2)
{
//https://www.geeksforgeeks.org/min-cost-path-dp-6/
if(idx1>row || idx2>col) return 1000;

if(costDP[idx1][idx2] != -1) return costDP[idx1][idx2];

if(idx1==row && idx2==col) return cost[idx1][idx2];

int smallAns1 = cost[idx1][idx2]+minCostPath(row,col,idx1,idx2+1);
int smallAns2 = cost[idx1][idx2]+minCostPath(row,col,idx1+1,idx2+1);
int smallAns3 = cost[idx1][idx2]+minCostPath(row,col,idx1+1,idx2);

int ans = min(smallAns1,smallAns2,smallAns3);
//cout<<idx1<<","<<idx2<<" = "<<ans<<endl;
return costDP[idx1][idx2]=ans;
}

int max(int a,int b,int c)
{
if(a<=b && a<=c) return a;
return (b<=c)?b:c;
}

int lcs2(string str1, string str2) // tabular method using DP
{
int len1 = str1.length(), len2 = str2.length();
if(len1==0 || len2==0)
	return 0;

int lcs[len1+1][len2+1]; char sign[len1+1][len2+1];

for(int i=0;i<=len1;i++)
	{
	for(int j=0;j<=len2;j++)
		{
		if(i==0 || j==0)
			lcs[i][j]=0;
		else if(str1[i-1]==str2[j-1])
			{
			lcs[i][j] = lcs[i-1][j-1]+1;
			sign[i][j] = '+';
			}
		else
			{
			lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
			
			if(lcs[i-1][j]>=lcs[i][j-1])
				sign[i][j] = '|';
			else
				sign[i][j] = '-';
			}
		}
	}
string str = ""; int len = lcs[len1][len2],idx1=len1,idx2=len2;
/*cout<<endl;
for(int i=1;i<=len1;i++)
	{
	for(int j=1;j<=len2;j++)
		cout<<sign[i][j]<<" ";
	cout<<endl;
	}
*/
while(len)
	{
	if(sign[idx1][idx2]=='+')
		{
		str = str1[idx1-1] + str;
		len--; idx1--; idx2--;
		}
	else if(sign[idx1][idx2]=='|')
		idx1--;
	else
		idx2--;
	}
cout<<str<<" and the length is ";
return lcs[len1][len2];
}

int lcs(string str1, string str2,int idx1,int idx2)  //recursive
{
int len1 = str1.length(), len2 = str2.length();

if(len1==0 || len2==0 || idx1>=len1 || idx2>=len2)
	return 0;

/*if(lcsDP[idx1][idx2]!=-1)
	return lcs[idx1][idx2]; */

if(str1[idx1]==str2[idx2])
	return /*lcs[idx1][idx2] =*/ (1 + lcs(str1,str2,idx1+1,idx2+1));

int smallAns1 = lcs(str1,str2,idx1+1,idx2);
int smallAns2 = lcs(str1,str2,idx1,idx2+1);

return /*lcs[idx1][idx2] =*/ (smallAns1>=smallAns2)?smallAns1:smallAns2;
}


struct lis* longIncSubseq(int *arr,int len,int idx)  //using bottom up approach, first calling the fn from the right side to left side, 
{						// then storing their ans in MAP, then using those values in the bigger fn calls
if(idx >= len) return NULL;

if(idx == len-1)  //only 1 element
	{
	struct lis *t = (struct lis*)malloc(sizeof(struct lis));
	t->len = 1; t->latest = arr[idx];
	return t;
	}
int largestF = 1,i;
struct lis *far;
for(i=idx+1;i<len;i++)
	{
	if(m[i]->latest >= arr[idx])
		{
		largestF=0;
		far = (struct lis*)malloc(sizeof(struct lis));
		far->len = m[i]->len+1; far->latest = arr[idx];
		break;
		}
	}
if(largestF==1)  //to check if there is no element lesser than this one, on its right side. so it won't be included then
	{
	struct lis *t = m[idx+1];
	return t;
	}
if(i==idx+1 || far->len > m[idx+1]->len)  //arr[idx+1] is bigger than arr[idx], so current can be included to the idx+1 answer
	return far;			// OR if (some other index's answer + current) is greater than idx+1's answer 

if(m[idx+1]->len > far->len)  //inclusion(at suitable position) of current is lesser than idx+1's answer
	return m[idx+1];

if(far->latest >= m[idx+1]->latest)  // if equal length, then we check latest, nd take the one with the larger latest value
	return far;

return m[idx+1];
}

void maxSqSubMatrix()
{
int row,col;
cin>>row>>col;
int arr[row][col];

for(int i=0;i<row;i++)
	for(int j=0;j<col;j++)
		cin>>arr[i][j];
int dp[row][col],max=0;

for(int i=0;i<row;i++)
	{
	for(int j=0;j<col;j++)
		{
		if(i==0 || j==0) 
			{
			dp[i][j] = arr[i][j]; continue;
			}
		if(arr[i][j] == 1)  
        		dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1; 
    		else
        		dp[i][j] = 0; 
		}
	}

for(int i=0;i<row;i++)
	for(int j=0;j<col;j++)
		if(dp[i][j]>max) max = dp[i][j];

cout<<"Max Size of SubMATRIX: "<<max<<endl;

/*for(int i=0;i<row;i++){
	for(int j=0;j<col;j++)
		cout<<dp[i][j]<<" ";
	cout<<endl;}
*/
}

void ugly()
{
int n;
cin>>n;

int ugly[n+1];
ugly[0]=1;

int i2=0,i3=0,i5=0;
int no2=2,no3=3,no5=5;

for(int i=1;i<n;i++)
{
int temp = min(no2,no3,no5);
ugly[i]=temp;

if(temp==no2) {i2++; no2 = ugly[i2]*2; }
if(temp==no3) { i3++; no3 = ugly[i3]*3; }
if(temp==no5) { i5++; no5 = ugly[i5]*5; }

}
cout<<n<<"th ugly no: "<<ugly[n-1]<<endl;
}

int min(int a,int b,int c)
{
if(a<=b && a<=c) return a;

return (b<=c)?b:c;
}
