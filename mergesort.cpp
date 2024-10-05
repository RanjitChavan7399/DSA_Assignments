#include<iostream>
#include<cmath>

using namespace std;
void merge(int a[], int start, int mid, int end);

void mergesort(int a[], int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2; 
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);

        merge(a, start, mid, end);
    }
}

void merge(int a[], int start, int mid, int end){
    int b[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while( i <= mid && j <= end){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }
        while(j <= end){
            b[k] = a[j];
            j++;
            k++;
    }
    for(int k = 0; k < (end - start + 1); k++){
        a[k] = b[k];
    }
 
}

int main(){

    int n;
    cout<<"Enter size of array :";
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter the "<<i+1<<" element of array :";
        cin>>a[i];
    }

    mergesort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}