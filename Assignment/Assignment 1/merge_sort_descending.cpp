#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];
void merge(int arr1[], int arr2[], int a, int b)
{
    arr1[a] = INT_MIN;
    arr2[b] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = 0; i <= a + b; i++)
    {
        if (arr1[lp] >= arr2[rp])
        {
            nums[i] = arr1[lp];
            lp++;
        }
        else
        {
            nums[i] = arr2[rp];
            rp++;
        }
    }
}
int main()
{
    int a;
    cin >> a;
    int arr1[a + 1];
    for (int i = 0; i < a; i++)
    {
        cin >> arr1[i];
    }
    int b;
    cin >> b;
    int arr2[b + 1];
    for (int i = 0; i < b; i++)
    {
        cin >> arr2[i];
    }
    merge(arr1, arr2, a, b);
    for (int i = 0; i < a + b; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
