#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=0,j=0,charnum=0,indtobinary=0;
    char input[4];
    char in,pre;
    char base64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    while(scanf("%c",&in)==1){
        for(j=0;in!=base64[j]&&j<66;j++);
        if(j<65){
            input[charnum]=in;
            pre = in;
            charnum++;
        }
        else if(in=='#'){
            if(pre!='#'){
                printf("#");
                pre='#';
            }
        }
        if(charnum==4){
            for(i=0;i<4;i++){
                if(input[i]=='='){
                    indtobinary <<=6;
                }else{
                    for(j=0;input[i]!=base64[j]&&j<66;j++);
                    indtobinary = ((indtobinary<<6)+j);
                }
            }
            printf("%c",indtobinary >> 16);
            if(input[2]!='=')
                printf("%c",indtobinary >> 8);
            if(input[3]!='=')
                printf("%c",indtobinary);
            charnum=0;
            indtobinary=0;
        }

    }
}