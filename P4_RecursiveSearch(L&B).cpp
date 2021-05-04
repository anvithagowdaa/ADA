#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double cpu_time1, cpu_time2;
clock_t start1, start2, end1, end2;

int linear_search(int arr[], int high, int low, int flag)
{
    if (low<high)
        return -1;
    if (arr[high] == flag)
        return high;
    if (arr[low] == flag)
        return low;
    return linear_search(arr,high+1,low-1,flag);
}

int binary_search(int arr[],int high, int low, int flag)
{
    if (low>=high)
    {
        int mid = (high+low)/2;


        if (arr[mid]==flag)
            return mid;


        if (arr[mid]>flag)
            return binary_search(arr,high,mid-1,flag);


        return binary_search(arr, mid + 1, low, flag);
    }


    return -1;
}

int main()
{

    int k,pos;
    int c,d;
    int i,n,a;
    int choice,flag,j;
    srand(time(0));
    while (1)
    {
        printf("1:Linear_Search\n2:Binary_Search\n3:Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the No: of elements:\n");
            scanf("%d", &n);
            int arr[n];
            printf("Enter elements:");
            for (k = 1; k <= n; k++)
            {
               scanf("%d", &arr[k]);
               printf("%d\t",arr[k]);
            }
            printf("\nEnter the Element to be Searched : \n");
            scanf("%d", &flag);
            start1 = clock();
            pos = linear_search(arr, 0, n-1, flag);
            for (c = 1; c <= 5000; c++) for (d = 1; d <= 5000; d++) { }
            end1 = clock();
            cpu_time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
            if(pos == -1)
            {
             printf("Element is not present in the Array\n");
            }
            else
            {
             printf("Element is present at the Position %d\n", pos);
            }
            printf("Time taken: %f\n",cpu_time1);
        }

        else if (choice == 2)
        {
            printf("Enter the No: of elements:");
            scanf("%d", &n);
            int arr[n];
            printf("Enter elements:");
            for (int k =1; k<=n; k++)
            {
               scanf("%d", &arr[k]);
               printf("%d\t",arr[k]);
            }
           for (i=1; i <=n;i++)
        {
            for (j = i + 1; j <= n; ++j)
            {
                if (arr[i] >arr[j])
                {
                    a =arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }

            }

        }
         for (int k =1; k <=n; k++)
            {
               printf("%d\t",arr[k]);
            }
            printf("\nEnter the element to be Searched :\n");
            scanf("%d", &flag);
            start2 = clock();
            pos = binary_search(arr, 0, n - 1, flag);
            for (c = 1; c <= 5000; c++) for (d = 1; d <=5000; d++) { }
            end2 = clock();
            cpu_time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
            if(pos == -1)
            {
			 printf("Element is not present in array\n");
			}
			else
			{
		     printf("Element is present at the Position %d\n", pos);
			}
            printf("Time taken: %f\n", cpu_time2);
        }
        else
            break;
    }
    return 0;
}
