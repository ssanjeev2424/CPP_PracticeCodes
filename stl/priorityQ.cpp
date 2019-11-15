#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

struct Interval {
	int start;
	int end;
	
	public:
		Interval(int s, int e) {
		start = s;
		end = e;
		}
		
};

struct comp {
bool operator()(const Interval &l, const Interval &r) const {
if(l.start != r.start)
	return l.start < r.start;
return l.end > r.end;
}
};

int main()
{
priority_queue<Interval, vector<Interval>, comp> pq;
int n,x,y; cin>>n;
for(int i=0;i<n;i++)
	{
	cin>>x>>y;
	pq.push(Interval(x,y));
	}
cout<<"Size: "<<pq.size()<<endl;
while(!pq.empty()) {
Interval i = pq.top();
cout<<"("<<i.start<<","<<i.end<<")"<<endl;
pq.pop();
}
return 0;
}
