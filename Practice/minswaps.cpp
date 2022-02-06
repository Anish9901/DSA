// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void merge(vector<pair<int,int>> &arr, int left, int middle, int right)
    {
        vector<pair<int,int>> helper;
        int i = left, j = middle + 1;
        while (i <= middle && j <= right)
        {
            if (arr[i] < arr[j])
            {
                helper.push_back(arr[i]);
                i++;
            }
            else
            {
                helper.push_back(arr[j]);
                j++;
            }
        }
        while (i <= middle)
        {
            helper.push_back(arr[i]);
            i++;
        }
        while (j <= right)
        {
            helper.push_back(arr[j]);
            j++;
        }
        for (int k = left; k <= right; k++)
        {
            arr[k] = helper[k - left];
        }
        /* for (int i = left; i <= middle; i++)
        {
            if (middle + i + 1 <= right)
            {
                if (arr[i] > arr[middle + i + 1])
                {
                    helper.push_back(arr[middle + i + 1]);
                }
            }

                helper.push_back(arr[i]);

        }
        for(int i = left;i <= right;i++)
        {
            arr[i] = helper[i];
        } */
    }
    void mergesort(vector<pair<int,int>> &arr, int left, int right)
    {
        if (right <= left)
        {
            return;
        }
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        vector<pair<int,int>> unsorted;
        for(int i = 0; i < nums.size();i++)
        {
            unsorted.push_back({nums[i],i});
        }
        float swaps = 0;
        mergesort(unsorted, 0, unsorted.size() - 1);
        int i = 0;
        while(i < unsorted.size())
        {
            if(i == unsorted[i].second)
            {
                i++;
                continue;
            }
            else
            {
                swaps++;
                swap(unsorted[i],unsorted[unsorted[i].second]);//brings the sorted element to its original pos i.e unsorted pos so that the index before and after match as it is.
            }
        }
        /* for (int i = unsorted.size() - 1; i >= 0; i--)
        {
            if (nums[i] != unsorted[i])
            {
                swaps++;
            }
        }
        if (swaps >= 2)
        {
            swaps = ceil(swaps / 2);
        } */
        return swaps;
        // Code here
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends