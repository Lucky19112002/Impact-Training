#include<iostream>
using namespace std;

void find_Pair(int num[],int n,int target){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((num[i]+num[j]) == target)
            {
                cout<<"Pair found: ( "<<num[i]<<" , "<<num[j]<<" ) "<<endl;
            }
        }
    }
}
int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;

    int n = sizeof(nums)/sizeof(nums[0]);

    find_Pair(nums,n,target);
    return 0;

}