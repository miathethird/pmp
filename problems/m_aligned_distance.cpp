/** Snippet from stackoverflow (I also encountered this problem in one of my interviews)

I've got an array of integer numbers (positive and negative) representing points in space, the distance between two points is defined as abs(A[i]-A[j]) and I need to check that that distance is divisible by a given integer M.

So this is the situation :

Array : [-3 -2 1 0 8 7 1]

M = 3

abs(A[1]-A[2]) = 3 (for example and it's divisible by the integer)

The complexity should be O(N+M) and the space O(M)
**/

#include <iostream>

int solve(int arr[], int size, int M)
{
    int ans = 0;
    int mod_arr[size] = {0};

    for(int i = 0; i<size; i++)
    {
        mod_arr[arr[i]%M]++;
    }

    return ans;
}

int main()
{
    int arr[] = {-3,-2,1,0,8,7,1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int ans = solve(arr, size, 3); //M=3
    std::cout << "Answer is: " << ans << std::endl;
    return 0;
}