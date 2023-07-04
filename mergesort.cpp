#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int si,int mid,int ei){
    int n1=mid-si+1;
    int n2=ei-mid;
    int left[n1];
    int right[n2];
    int i=0;
    int j=0;
    int l=si;
    for(int o=0;o<n1;o++){
        left[o]=a[si+o];
    }
    for(int o=0;o<n2;o++){
        right[o]=a[mid+1+o];
    }
    while(n1>i && n2>j){
        if (left[i]<=right[j]){
            a[l]=left[i];i++;
        }
        else {
            a[l]=right[j];
            j++;
        }l++;
    }
    while(n1>i){
        a[l]=left[i];i++;l++;
    }
    while(n2>j){
         a[l]=right[j];
            j++;l++;
    }
}
void mergesort(int a[],int si,int ei){
    if (si>=ei)return ;
   int mid=(si+ei)/2;
    mergesort(a,si,mid);
    mergesort(a,mid+1,ei);
    merge(a,si,mid,ei);
}
int main(){
    cout<<"enter the size of array"<<endl;
    int n;cin>>n;int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"array before sorting"<<endl;
    for (auto x:a){
        cout<<x;
    }
    clock_t start=clock();
    mergesort(a,0,n-1);
    clock_t end=clock();
       cout<<"array after sorting"<<endl;
    for (auto x:a){
        cout<<x;
    }
    cout<<endl<<"time take by this algorithm is "<<end-start/CLOCKS_PER_SEC<<"SECONDS"<<endl;
    return 0;
}
