#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l+r)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int left = m - l + 1;
    int right = r - m;

    int L[left], R[right];
    for (i=0; i<left; i++)
    {
        L[i] = arr[l+i];
    }
    for (j=0; j<right; j++)
    {
        R[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i < left && j < right)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < right)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int n, i;
    printf("How many numbers? ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);

    printf("The sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
