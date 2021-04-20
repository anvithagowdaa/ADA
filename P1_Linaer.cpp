#include <iostream>
using namespace std;
int arr[100];

int search(int arr[], int n, int x)
{
        int i;
        for(i=0; i<n; i++){
        if(arr[i] ==x)
        return 1;
        }
        return -1;
}

int main()
{
    int test;
    int n, i,j,k;
    cin>>test;
    for(j=0; j<test; j++)
    {

    cin>>n;
    cin>>k;

    for (i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<search(arr,n,k);

    }
    return 0;

}
