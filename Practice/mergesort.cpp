// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int left, int middle, int right)
    {
        vector<int> helper;
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
    }

    void mergeSort(int arr[], int left, int right)
    {
        if (right <= left)
        {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
};

// { Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
} // } Driver Code Ends