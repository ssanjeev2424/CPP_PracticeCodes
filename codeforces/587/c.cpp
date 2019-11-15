#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef pair<int,int> pii;
#define x first
#define y second

//https://codeforces.com/blog/entry/69954

pair<pii, pii> intersection(pii a, pii b, pii c, pii d) {
	int x1, y1, x2, y2;
	
	bool c1 = false, c2 = false, c3 = false, c4 = false;
	
	if(a.x >= d.x || c.x >= b.x) //right
		c1 = true;
	if(b.x <= c.x || d.x <= a.x) //left
		c2 = true;
	if(a.y >= d.y || c.y >= b.y) //up
		c3 = true; 
	if(b.y <= c.y || d.y <= a.y) //down
		c4 = true;
	
	if(c1 || c2 || c3 || c4) // no intersection
		return { {0, 0}, {0, 0} };
	
	x1 = max(a.x, c.x);
	y1 = max(a.y, c.y);
	
	x2 = min(b.x, d.x);
	y2 = min(b.y, d.y);
	
	return { {x1, y1}, {x2, y2} };
}

ll square(pii a, pii b) {
	return 1ll*abs(a.x - b.x)*abs(a.y - b.y);
}

int main() {
	fast;
	vector<pii> p(6);
	for(int i=0; i<6; i++) cin>>p[i].x>>p[i].y;
	
	pair<pii, pii> wb1 = intersection(p[0], p[1], p[2], p[3]); //intersetion of white and b1
	//cout<<"wb1: "<<wb1.x.x<<" "<<wb1.x.y<<", "<<wb1.y.x<<" "<<wb1.y.y<<endl;
	
	pair<pii, pii> wb2 = intersection(p[0], p[1], p[4], p[5]); //intersetion of white and b2
	//cout<<"wb2: "<<wb2.x.x<<" "<<wb2.x.y<<", "<<wb2.y.x<<" "<<wb2.y.y<<endl;
	
	pair<pii, pii> Wb1Wb2 = intersection(wb1.x, wb1.y, wb2.x, wb2.y); //intersetion of wb1 and wb2
	//cout<<"Wb1Wb2: "<<Wb1Wb2.x.x<<" "<<Wb1Wb2.x.y<<", "<<Wb1Wb2.y.x<<" "<<Wb1Wb2.y.y<<endl;
	
	
	
	
	ll w_Area = square(p[0], p[1]); //area
	ll wb1_Area = square(wb1.x, wb1.y);
	ll wb2_Area = square(wb2.x, wb2.y);
	ll Wb1Wb2_Area = square(Wb1Wb2.x, Wb1Wb2.y);
	
	//cout<<"\nwhite: "<<w_Area<<"  wb1: "<<wb1_Area<<"  wb2: "<<wb2_Area<<" Wb1Wb2: "<<Wb1Wb2_Area<<endl;
	
	if(w_Area > wb1_Area + wb2_Area - Wb1Wb2_Area) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}

/*

struct Points {
	int a, b;
	int c, d;
	
	Points(int q, int w, int e, int r) {
		a = q; b = w;
		c = e; d = r;
	}
};

int main() {
	fast;
	int x1,y1,x2,y2;
	int p1[2], p2[2], p3[2], p4[2];
	cin>>x1>>y1>>x2>>y2;
	cin>>p1[0]>>p2[0]>>p3[0]>>p4[0]>>p1[1]>>p2[1]>>p3[1]>>p4[1];
	
	vector<Points> sheet;
	sheet.push_back(Points(x1,y1,x2,y2));
	
	for(int i=0; i<2; i++) {
		if(!sheet.size()) break;
		
		vector<Points> del;
		for(auto x: sheet) {
			if(p3[i]<=x.a || p1[i]>=x.c || p2[i]>=x.d || p4[i]<=x.b) //black sheet completely outside
				continue;
			
			if(p3[i]<x.c || p1[i]>x.a || p2[i]>x.b || p4[i]<x.d) { // completely inside
				
			}
		}
		
		for(auto x: del)
			sheet.erase(x);
	}
	
	if(sheet.size()) cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}

*/
