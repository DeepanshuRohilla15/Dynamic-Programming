#include <bits/stdc++.h> 

long long int maximumNonAdjacentSum(vector< int> &nums){
    // Write your code here.
    long long  n = nums.size();
    long long  prev = nums[0];
    long long  prev2 = 0;

    for(int i=1; i<n; i++)
    {
        long long take = nums[i];
        if(i>1) take += prev2;

         long long noTake = 0 + prev;
         long long curi = max(take, noTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
     int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector< int> temp1, temp2;
    for(int i=0; i<n; i++)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!= n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}
