void sort012(int *arr,int size){
    int i=0;
    int j=size-1;
    int b=0,c=0;
    for(int a=0;a<size;a++){
        if(arr[a]==0){
            b++;
        }
        else if(arr[a]==2){
            c++;
        }
    }
    for(int k=0;b || c;k++){
        if(arr[k]==0){
            int t=arr[i];
            arr[i]=arr[k];
            arr[k]=t;
            i++;
            b--;
        }
        else if(arr[k]==2){
            int t=arr[j];
            arr[j]=arr[k];
            arr[k]=t;
            j--;
            c--;
        }
    }
}