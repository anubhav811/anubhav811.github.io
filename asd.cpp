/*
You are given a 0-indexed integer array nums of size n and a positive integer k.

We call an index i in the range k <= i < n - k good if the following conditions are satisfied:

The k elements that are just before the index i are in non-increasing order.
The k elements that are just after the index i are in non-decreasing order.
Return an array of all good indices sorted in increasing order
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> goodIndices(vector<int> &nums, int k)
{
    int N = nums.size();
    vector<int> prefix(N), suffix(N);
    vector<int> ans;

    /*Form the prefix[] array where prefix[i] represents the number of elements before i which obeys non-increasing order.
Form the suffix[] array where suffix[i] represents the number of elements after i which obeys non-decreasing order.
*/

    prefix[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (nums[i] >= nums[i - 1])
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = 1;
    }
    suffix[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (nums[i] <= nums[i + 1])
            suffix[i] = suffix[i + 1] + 1;
        else
            suffix[i] = 1;
    }

    /*If prefix[i] >= k and suffix[i] >= k, then i is a good index.
     */
    for (int i = k; i < N - k; i++)
    {
        if (prefix[i] >= k && suffix[i] >= k)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 2;
    vector<int> ans = goodIndices(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}