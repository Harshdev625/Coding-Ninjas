void removeConsecutiveDuplicates(char input[]){
    char a=input[0];
    for(int i=1;i<strlen(input);i++){
        if(input[i]==a){
            int j;
            for(j=i-1;j<strlen(input)-1;j++){
                input[j]=input[j+1];
            }
            input[j]='\0';
        }
        else{
            a=input[i];
        }
    }
}