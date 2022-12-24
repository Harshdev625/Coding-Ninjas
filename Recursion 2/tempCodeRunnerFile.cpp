int binarySearch(int input[], int length,int  element){
    if(*input==element ){
        return 0;
    }
    return 1 + binarySearch( input+1,  length-1,  element);
}