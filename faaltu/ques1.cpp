#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

string solution(int a, int b, int c)
{
string ans="";

vector<pair<lli,char> > vec;
vec.push_back({a,'a'});
vec.push_back({b,'b'});
vec.push_back({c,'c'});

sort(vec.begin(), vec.end(), greater<pair<int,char> >());

lli gap = (vec[0].first)/2 + (vec[0].first)%2 - 1;

if(vec[0].first<=2)
	{
	//cout<<"Possible string: ";
	for(auto x:vec)
		{
		for(int i=0;i<x.first;i++)
			ans += x.second;
		}
	return ans;
	}
else if(gap > vec[1].first + vec[2].first)
	{
	if((vec[0].first)%2==0)
		vec[0].first -= 2;
	else
		vec[0].first -= 1;
	gap--;
	while(gap > vec[1].first + vec[2].first)
		{
		vec[0].first -= 2;
		gap--;
		}
	}
	lli bFreq[gap+1]={0}, cFreq[gap+1]={0};
	lli idx = 0, cnt = 0;
	lli temp = vec[1].first;
	
	while(cnt<2*gap && temp)
		{
		for(lli i=0;i<gap && temp; i++,temp--,cnt++)
			bFreq[i]++;
		}
	if(temp)
		bFreq[gap] = temp;
	
	cnt = 0, temp = vec[2].first;
	while(cnt<2*gap && temp)
		{
		for(lli i=gap-1;i>=0 && temp; i--,temp--,cnt++)
			cFreq[i]++;
		}
	if(temp)
		cFreq[gap] = temp;
	
	idx = gap; lli i=0;
		while(idx)
		{
		ans += vec[0].second; ans += vec[0].second;
		for(int y=0;y<bFreq[i];y++)
			ans += vec[1].second;
		for(int y=0;y<cFreq[i];y++)
			ans += vec[2].second;
			
		idx--; i++;
		vec[0].first -= 2;
		}
		if(vec[0].first)
			{
			for(int y=0;y<vec[0].first;y++)
			ans += vec[0].second;
			}
		if(bFreq[gap])
			{
			for(int y=0;y<bFreq[gap];y++)
			ans += vec[1].second;
			}
		if(cFreq[gap])
			{
			for(int y=0;y<cFreq[gap];y++)
			ans += vec[2].second;
			}
		return ans;
}

int main()
{
/*lli a,b,c; //frequencies
cout<<"Enter Frequencies: ";
cin>>a>>b>>c;

string ans="";

vector<pair<lli,char> > vec;
vec.push_back({a,'a'});
vec.push_back({b,'b'});
vec.push_back({c,'c'});

sort(vec.begin(), vec.end(), greater<pair<int,char> >());

lli gap = (vec[0].first)/2 + (vec[0].first)%2 - 1;

if(vec[0].first<=2)
	{
	cout<<"Possible string: ";
	for(auto x:vec)
		{
		for(int i=0;i<x.first;i++)
			cout<<x.second;
		}
	cout<<endl;
	}
else if(gap > vec[1].first + vec[2].first)
	{
	if((vec[0].first)%2==0)
		vec[0].first -= 2;
	else
		vec[0].first -= 2;
	gap--;
	while(gap > vec[1].first + vec[2].first)
		{
		vec[0].first -= 2;
		gap--;
		}
	}
else
	{
	lli bFreq[gap+1]={0}, cFreq[gap+1]={0};
	lli idx = 0, cnt = 0;
	lli temp = vec[1].first;
	
	while(cnt<2*gap && temp)
		{
		for(lli i=0;i<gap && temp; i++,temp--,cnt++)
			bFreq[i]++;
		}
	if(temp)
		bFreq[gap] = temp;
	
	cnt = 0, temp = vec[2].first;
	while(cnt<2*gap && temp)
		{
		for(lli i=gap-1;i>=0 && temp; i--,temp--,cnt++)
			cFreq[i]++;
		}
	if(temp)
		cFreq[gap] = temp;
	
	cout<<"Possible string is: ";
	idx = gap; lli i=0;
		while(idx)
		{
		cout<<vec[0].second<<vec[0].second;
		for(int y=0;y<bFreq[i];y++)
			cout<<vec[1].second;
		for(int y=0;y<cFreq[i];y++)
			cout<<vec[2].second;
			
		idx--; i++;
		vec[0].first -= 2;
		}
		if(vec[0].first)
			{
			for(int y=0;y<vec[0].first;y++)
			cout<<vec[0].second;
			}
		if(bFreq[gap])
			{
			for(int y=0;y<bFreq[gap];y++)
			cout<<vec[1].second;
			}
		if(cFreq[gap])
			{
			for(int y=0;y<cFreq[gap];y++)
			cout<<vec[2].second;
			}
		cout<<endl;
	}*/
int a,b,c; cin>>a>>b>>c;
cout<<solution(a,b,c)<<endl;

return 0;
}
