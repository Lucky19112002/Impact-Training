from collections import Counter
import pdb

def print_counter(a):
    arr = Counter(a)
    print(arr)

    maxnum = float('-inf')  # Initialize maxnum with a very small value

    for i in range(len(arr) - 1):  # Iterate up to the second-to-last index
        pdb.set_trace()  # Add a breakpoint
        maxnum = max(maxnum, arr[i] + arr[1 + i])  # Compare and update maxnum

    print("Max sum of consecutive elements:", maxnum)

arr = list(map(int, input("Enter: ").split(" ")))
print_counter(arr)
