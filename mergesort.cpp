void merge(vector<int>&a,int si,int mid,int ei){
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
void mergesort(vector<int>&a,int si,int ei){
    if (si>=ei)return ;
   int mid=(si+ei)/2;
    mergesort(a,si,mid);
    mergesort(a,mid+1,ei);
    merge(a,si,mid,ei);
}
int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
     vector<int>arr(n);
    for(int i=0;i<n;i++){
        int a=rand()%(INT_MAX);
        arr[i]=a;
    }
    double s1=clock();
    mergesort(arr,0,n-1);
    double s2=clock();
    cout<<"time taken by the mergesort algorithm is "<<((s2-s1)/CLOCKS_PER_SEC)<<endl;
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}
