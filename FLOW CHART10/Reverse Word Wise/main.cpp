#include <iostream>
#include <cstring>
using namespace std;

void reversewordwise(char a[]){
    int b=0;
    for(int i=0;a[i]!='\0';i++){
        b++;
    }
    int d=b-1;
    for(int i=0;d>=i;i++,d--){
        char e=a[i];
        a[i]=a[d];
        a[d]=e;
    }
    int f=0;
    int h;
    for(int i=0;i<=d;i++){
        if(a[i]==' '){
            int g=i-1;
            while(g>=f){
                char h=a[f];
                a[f]=a[g];
                a[g]=h;
                f=i;
                f++;
                g--;
            }
          h=f+g+2;
        }
       f=h;
    }
}


int main()
{
   char a[1000];
   cin.getline(a,1000);
   reversewordwise(a);
   cout<<a;
}








//i will try to make other smile like if she is a girl i will say her "teri aakho ki yeh adaye ,teri  baato me woh jalak mil jaye ,ki tujhe dekhe bina ye din na beet paaye".or if he is a boy i will say "bhai tere me haar cheez hai khass par phir bhi tuhje khate sab bakwas unhe kya pata ki tu hira hai jo milta nhi kisi ke pass.
