#include <bits/stdc++.h>
using namespace std;
#define dodo ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ll long long
void selectionSort(int arr[],int n){
    int i,j,minIdx;
    for (i = 0; i < n-1; ++i) {
        minIdx=arr[i];
        for (j = i+1; j < n; ++j) {
            if (arr[j]<arr[minIdx])
                minIdx=j;
        }
        if (minIdx!=i)
            swap(arr[minIdx],arr[i]);
    }
}
void insertionSort(int arr[], int n){
    int tmp,i,j;
    for (i = 1; i < n; ++i) {
        tmp=arr[i];
        for ( j = i-1; j >=0 ; --j) {
            if (arr[j]>tmp){
                arr[j+1]=arr[j]; //shift right
            }else
                break;
        }
        arr[j+1]=tmp;
    }
}
template <class T>
void BubbleSort(T data[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = n - 1; j > i; --j){
            if (data[j] < data[j - 1])
                swap(data[j], data[j - 1]);
        }
    }
}
template <class T>
void shellSort(T arr[], int n)
{
    // Start with a big gap, halve it every iteration
    for (int gap = n / 2; gap > 0; gap /= 2){
    // Do a gaped insertion sort for this gap size.
        for (int i = gap; i < n; i += 1){
    // Save a[i] in temp and make a hole at position i
            T temp = arr[i];
    // Shift earlier gap-sorted elements up until the correct
    // location for a[i] is found (Insertion sort)
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            // Put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

template<class T>
void myShellSort(T a[], int n){
    for (int gap = n/2; gap > 0; gap/=2) {

        for (int i = gap; i < n; ++i) {
            T tmp= a[i];
            int j;
            for (j = i; j>=gap && a[j-gap]>tmp ; j-=gap) {
                a[j]=a[j-gap];
            }
            a[j]=tmp;
        }
    }
}




template <class  T>
void merge(T a[], T l, T mid, T r){
    vector<T>L,R;
    for (int i = l; i <= mid; ++i) {
        L.push_back(a[i]);
    }
    for (int i = mid+1; i <= r; ++i) {
        R.push_back(a[i]);
    }
    int li=0,ri=0,i=l;
    while (li<L.size()&&ri<R.size()) {
        if (L[li]<=R[ri]){
            a[i++]=L[li++];
        }else{
            a[i++]=R[ri++];
        }
    }
    while (li < L.size()) {
        a[i++] = L[li++];
    }
    while (ri < R.size()) {
        a[i++] = R[ri++];
    }
}
template <class T>
void mergeSort(T a[],int l, int r){
    if (l>=r) //base case
        return;
    int mid=(l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}

template <class T>
void QuickSort(T data[], int left, int right){
    int i=left,j=right;
    int pivot= data[(left+right)/2]; //taking the pivot as the middle
    while (i<=j){
        while (data[i]<pivot){
            ++i;
        }
        while (data[j]>pivot){
            --j;
        }
        if (i<=j){
            swap(data[i],data[j]);
            ++i;
            --j;
        }
    }
    if (left<j){ //when they are equal this will be the base case(only one element)
        QuickSort(data, left, j);
    }
    if (right>i){
        QuickSort(data,i,right);
    }
}
template<class T>
int partition(T a[],int left, int right){
    int i=left;
    for (int j = left+1; j <= right; ++j) {
        if (a[j]<a[left]){
            swap(a[++i],a[j]);
        }
    }
    swap(a[i],a[left]);
    return i;
}

template<class T>
void firstPivotQuickSort(T a[],int left, int right){
    if (left>=right)return;
    int pivot= partition(a,left,right);
    firstPivotQuickSort(a,left,pivot-1);
    firstPivotQuickSort(a,pivot+1,right);
}
int main() {
    int arr[]={2,8,5,9,4,3,1};
//    int a[]={1,12,5,26,7,14,3,7,2};
    int a[]={5,3,0,10,2};
//    BubbleSort(arr,7);
//    for (auto i:arr) {
//        cout<<i<<' ';
//    }
//    QuickSort(a,0,8);
//    mergeSort(a,0,8);
    firstPivotQuickSort(a,0,4);
    for (auto i:a) {
        cout<<i<<' ';
    }
}
