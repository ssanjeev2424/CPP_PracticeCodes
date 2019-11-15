#include<bits/stdc++.h> 
using namespace std;
int KnapSack(int *val, int *wt, int n, int W) { 
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat));  
    for(int i=0; i<n; i++) { 
        int j = 0;               // traverse all weights j <= W 
        if (i%2!=0) { 
            while (++j <= W)     // check for each value 
            { 
                if (wt[i] <= j)                //may include
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
                                    mat[0][j] ); 
                else                      
                    mat[1][j] = mat[0][j];     //exclude 
            } 
  
        } 
        else { 
            while(++j <= W) {
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
    } 
 
    return (n%2 != 0)? mat[0][W] : mat[1][W]; 
} 
int main()
{
    int W , n;
    cout<<"Total weight of knapsack: "; cin>>W;
    cout<<"Enter number of items: "; cin>>n;
    int val[n], wt[n];
    cout<<"Enter values and weights.."<<endl;
    for(int i=0;i<n;i++) cin>>val[i]>>wt[i];
    cout<<"Maximum possible profit: "<<KnapSack(val, wt, n, W)<<endl;
    return 0;
}
