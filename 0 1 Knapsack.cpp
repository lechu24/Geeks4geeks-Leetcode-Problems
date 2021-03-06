//for problem statement ,refer:https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
//For writing the top-down approach, we just need to convert the recursive code to iterative code after initialisation
//The matrix we created has the value of its different cells as answers to various subproblems in dp
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int w;
        cin>>w;
        int val[n+1],wt[n+1];
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        int t[n+1][w+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                //Converting base condition of recursion to iterative code or INITIALISATION in other words
                //Value 0 as when there are no items or weight of bag is 0, no profit gained
                if(i==0||j==0)
                    t[i][j]=0;
                //The same recursive code just the term n is replaced by i and w is replaced by j
                else if(wt[i-1]<=j)
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }
        }
        //using the subproblems like t[n-2][w] etc etc, answer to the main problem is computed
        cout<<t[n][w]<<endl;
    }
