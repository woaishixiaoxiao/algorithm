#include<iostream>
using namespace std;
#include<string.h>
void replaceSpace(char *str,int length) {
    if(!str||(length==0)){
        return;
    }
    int cnt=0;
    for(int i=0;i<length;i++){
        if(str[i]==' '){
            cnt++;
        }
    }
    cnt*=2;;
    int curr_length=length+cnt+1;
    int j=curr_length;
    for(int i=length;i>=0;i--){
        if(str[i]==' '){
            str[--j]='0';
            str[--j]='2';
            str[--j]='%';
        }else{
            str[--j]=str[i];
        }
    }
}
main(){
	char *s=new char[100];
	strcpy(s,"hello word");
	cout<<s<<endl;
	replaceSpace(s,strlen("hello world"));
	cout<<s;
}
