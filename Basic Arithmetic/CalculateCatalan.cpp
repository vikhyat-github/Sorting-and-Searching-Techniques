/*
Catalan number  : 
Catalan numbers is a number sequence, which is found useful in a number of combinatorial problems, often involving recursively-defined objects.

The first few numbers Catalan numbers, Cn (starting from zero):
1,1,2,5,14,42,132,429,1430,…

Variations:
1. No. of unique BSTs
2. Count Valleys and Mountain
3. Count Brackets
4. Circle and chords
5. Number of ways of Triangulations
6. Maximum score of Triagulations
7. unlabled tree
8. N paranthesis (with or without letters)
9. dyck of words
10. convex polygon
 */
#include <bits/stdc++.h>
using namespace std;

//Using Recusion
long long catalan(int n)
{
    if(n<=1)
        return 1;
    long long res = 0;
    for(int i=0;i<n;i++)
    {
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

//Using Dynamic Programming
long long catalanDP(int n)
{
    long long cat[n+1];
    cat[0] = cat[1] = 1;
    for(int i=2;i<=n;i++)
    {
        cat[i] = 0;
        for(int j=0;j<i;j++)
            cat[i] += cat[j]*cat[i-j-1];
    }
    return cat[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    cin>>number;
    cout<<catalan(number)<<endl;
    cout<<catalanDP(number)<<endl;
    return 0;
}