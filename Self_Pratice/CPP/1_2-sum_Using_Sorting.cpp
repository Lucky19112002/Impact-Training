#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void findPair(int nums[],int n,int targ){
    sort(nums,nums+n);
    int low = 0;
    int high = n-1;
    while (low < high)
    {
        if (nums[low] + nums[high] == targ)
        {
            cout << "Pair found (" << nums[low] << ", " << nums[high] << ")\n";
        }
        (nums[low] + nums[high] < targ)? low++: high--;
    }
}
int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int tar= 10;
    int n= sizeof(nums)/sizeof(nums[0]);
    findPair(nums,n,tar);
}