#include <stdio.h>
#include <stdlib.h>
int Partition(int a[], int low, int high);
void Swap(int *a, int *b);

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int paridx = Partition(a, low, high);
        QuickSort(a, low, paridx - 1);
        QuickSort(a, paridx + 1, high);
    }
}
int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1) i++;
        while (a[j] > pivot && j >= low + 1)  j--;
        if (i < j) Swap(&a[i], &a[j]);
    }
    Swap(&a[low], &a[j]);
    return j;
}
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

/*
#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int st = lb;
    int ed = ub;

    while (st < ed)
    {
        while(a[st] <= pivot)
        {
            st++;
        }
        while (a[ed] > pivot)
        {
            ed--;
        }
        if (st < ed)
        {
            Swap (&a[st], &a[ed]);
        }
    }
    Swap(&a[lb], &a[ed]);
    return ed;
}

void QuickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        QuickSort(a, lb, loc-1);
        QuickSort(a, loc+1, ub);
    }
}


int main()
{
    int n, i;
    printf("How many numbers? ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for (i=0; i<n; i++) scanf("%d", &a[i]);

    QuickSort(a, 0, n-1);
    printf("The sorted array: ");
    for (i=0; i<n; i++) printf("%d ", a[i]);
}

*/