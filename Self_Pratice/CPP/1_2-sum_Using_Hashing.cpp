#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to find a pair in an array with a given sum using hashing
void findPair(int nums[], int n, int target)
{
    // create an empty map
    unordered_map<int, int> map;
 
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair (nums[i], target - nums[i]) exists
 
        // if the difference is seen before, print the pair
        if (map.find(target - nums[i]) != map.end())
        {
            cout << "Pair found (" << nums[map[target - nums[i]]] << ", "
                 << nums[i] << ")\n";
        }
 
        // store index of the current element in the map
        map[nums[i]] = i;
    }
 
    // we reach here if the pair is not found
}
int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    findPair(nums, n, target);
 
    return 0;
}