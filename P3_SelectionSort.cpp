#include<iostream>
using namespace std;
int a[10];
int k=0;
void binsearch(int low,int high,int arr[],int key){
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == key){
            a[k++]=mid+1;
           binsearch(low,mid-1,arr,key);
           binsearch(mid+1,high,arr,key);
           break;
        }
        else if(arr[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
}

int main(){
    int result,key,n,i;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<endl<<"Enter array: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter key element: ";
    cin>>key;
    binsearch(0,n-1,arr,key);
    int max=a[0];
    int min=a[0];
    for(i=1; i<k; i++){
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    cout<<"Total occurence: "<<k<<endl;
    cout<<"First occurance: "<<min<<endl<<"Last occurence: "<<max<<endl;
    return 0;
}
