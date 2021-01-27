#include<iostream>
using namespace std;
void swap(int *a,int *b){
  int t;
  t=*a;*a=*b;*b=t;
}

void print(int arr[],int n){
  for(int i=0;i<n;i+=1)
    cout<<arr[i]<<" ";
  cout<<endl;
}

//time n2(avg,worst) n in best
//space 1
void bubbleSort(int arr[],int n){
  int i,j,flag;
  for(i=0;i<n-1;i+=1){
    flag=0;
    for(j=0;j<n-i-1;j+=1){
      if(arr[j+1]<arr[j]) swap(&arr[j+1],&arr[j]),flag=1;
    }
    if(!flag) break;
  }
  print(arr,n);
}

//time n2 (all cases)
//space 1
void selectionSort(int arr[],int n){
  int min_index,i,j;
  for(i=0;i<n-1;i+=1){
    min_index=i;
    for(j=i+1;j<n;j+=1){
      if(arr[min_index]>arr[j]) min_index=j;
    }
    swap(&arr[i],&arr[min_index]);
  }
  print(arr,n);
}

//time n2(avg,worst) n in best
//space 1
void insertionSort(int arr[],int n){
  int i,j,key;
  for(i=1;i<n;i+=1){
    key=arr[i];
    for(j=i-1;j>=0 && key<arr[j];j-=1){
      arr[j+1]=arr[j];
    }
    arr[j+1]=key;
  }
  print(arr,n);
}

// nlogn space in this implementation but can be made n if we clear both the arrays
// nlogn time (all cases)
void merge(int left[],int l, int right[], int r, int arr[]){
    int i=0,j=0,k=0;
    while(i<l && j<r){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i+=1;
        }else{
            arr[k]=right[j];
            j+=1;
        }
        k+=1;
    }
    while(i<l){
        arr[k]=left[i];
        i+=1;k+=1;
    }
    while(j<r){
        arr[k]=right[j];
        j+=1;k+=1;
    }
}
void mergeSort(int arr[],int n){
    if(n==1) return;
    int i,mid=n/2;
    int left[mid],right[n-mid];
    for(i=0;i<mid;i+=1) left[i]=arr[i];
    for(i=mid;i<n;i+=1) right[i-mid]=arr[i];
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(left,mid,right,n-mid,arr);
}

// logn space in randomized and n in non-randomized partitioning
// nlogn time (all cases)
int partitioning(int arr[],int s,int e){
  int pIndex=s+rand()%(e-s+1);
  swap(&arr[pIndex],&arr[e]);
  int pivot=arr[e],i,pos=s;
  for(i=s;i<e;i+=1){
    if(arr[i]<=pivot){
      swap(&arr[pos],&arr[i]);
      pos+=1;
    }
  }
  swap(&arr[e],&arr[pos]);
  return pos;
}
void quickSort(int arr[],int s,int e){
  if(s>=e) return;
  int pos=partitioning(arr,s,e);
  quickSort(arr,s,pos-1);
  quickSort(arr,pos+1,e);
}

// space 1
// time nlogn (all cases)
void heapify(int arr[],int n,int i){
  int left,right,max=i;
  left=2*i+1;
  right=2*i+2;
  if(n>left && arr[left]>arr[max]){
    max=left;
  }
  if(n>right && arr[right]>arr[max]){
    max=right;
  }
  if(max!=i){
    swap(&arr[max],&arr[i]);
    heapify(arr,n,max);
  }
}
void heapSort(int arr[],int n){
  int i;
  for(i=n/2-1;i>=0;i-=1){
    heapify(arr,n,i);
  }
  for(i=n-1;i>0;i-=1){
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
  }
  print(arr,n);
}

// Elements entered by user should in some range
// in this case the range is 0-9
// space o(n+k) k:range
// time: o(n+k) k:range
void countSort(int arr[],int n){
  int count[10]={0},i,sum=0,output[n];
  for(i=0;i<n;i+=1){
    count[arr[i]]+=1;
  }
  for(i=1;i<10;i+=1){
    count[i]+=count[i-1];
  }
  // for stable sorting start the loop from the end
  for(i=0;i<n;i+=1){
    output[count[arr[i]]-1]=arr[i];
    count[arr[i]]-=1;
  }
  print(output,n);
}

int main(){
  int arr[]={3,4,3,6,5,8,3,4,6,4,3,7,2,8,4,8,6,9,5,7,3};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"Original array: ";
  for(int i=0;i<n;i+=1)
    cout<<arr[i]<<" ";
  cout<<endl<<"Sorted array:   ";
  //bubbleSort(arr,n);
  //selectionSort(arr,n);
  //insertionSort(arr,n);
  //mergeSort(arr,n);print(arr,n);
  quickSort(arr,0,n-1);print(arr,n);
  //heapSort(arr,n);
  //countSort(arr,n);
}
