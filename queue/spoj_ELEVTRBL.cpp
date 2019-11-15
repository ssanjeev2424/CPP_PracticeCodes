#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

struct State {
	int val;
	int curr;
	
	State(int v, int c) {
		val = v;
		curr = c;
	}
};

bool visited[1000003];

int main() {
	int total, s, goal, up, down, ans = 100000001;
	cin>>total>>s>>goal>>up>>down;
	memset(visited, false, sizeof(visited));
	
	queue<State> q;
	q.push(State(0, s));
	
	while(!q.empty()) {
		State temp = q.front();
		q.pop();
		
		if(visited[temp.curr]) continue;
		
		visited[temp.curr] = true;
		
		if(temp.curr == goal) {
			cout<<temp.val<<endl;
			return 0;
		}
		
		if(temp.curr + up <= total)
			q.push(State(temp.val+1, temp.curr+up));
		
		if(temp.curr - down > 0)
			q.push(State(temp.val+1, temp.curr-down));
	}
	
	cout << "use the stairs" << endl;
	return 0;
}

/*
if(!up) {
		if(s < goal)
			cout<<"use the stair\n";
		else if(s==goal)
			cout<<0<<endl;
		else
			(down && (s-goal)%down==0)? cout<<(s-goal)/down : cout<<"use the stairs\n";
		
		return 0;
	}	
	
	if(!down) {
		if(s > goal)
			cout<<"use the stairs\n";
		else if(s==goal)
			cout<<0<<endl;
		else
			(up && (goal-s)%up==0)? cout<<(goal-s)/up : cout<<"use the stairs\n";
		
		return 0;
	}	
	
	
	
	queue<State> q;
	//struct state x = {2,3};
	
	//q.push(State(0, s));
	//State x = q.front();
	//cout<<x.curr<<endl;
	
	q.push(State(0, s));
	
	while(!q.empty()) {
		State temp = q.front();
		q.pop();
		
		if(temp.val >= ans) continue;
		
		if(temp.curr <= goal) {
			if((goal-temp.curr)%up == 0) {
				temp.val += (goal-temp.curr)/up;
				temp.curr = goal;
				if(temp.val < ans) ans = temp.val;
			}
			else if((goal-temp.curr) < up) {
				if(temp.curr - down > 0) {
					temp.curr -= down;
					temp.val++;
					q.push(temp);
				}
			}
			else {
				int x = (goal-temp.curr)/up;
				temp.val += x;
				temp.curr += x*up;
				q.push(temp);
			}
		}
		else {                                 //curr > goal
			if((temp.curr - goal)%down == 0) {
				temp.val += (temp.curr-goal)/down;
				temp.curr = goal;
				if(temp.val < ans) ans = temp.val;
			}
			else if((temp.curr-goal) < down) {
				if(temp.curr + up <= total) {
					temp.curr += up;
					temp.val++;
					q.push(temp);
				}
			}
			else {
				int x = (temp.curr-goal)/down;
				temp.val += x;
				temp.curr -= x*down;
				q.push(temp);
			}
		}
	}
	
	if(ans == INT_MAX) cout<<"use the stairs\n";
	else cout<<ans<<endl;

*/

