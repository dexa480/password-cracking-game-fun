#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int randomNumber(){
    int i,a,password[4];
    for(i=0;i<4;i++){
        password[i]=rand()%9 + 1;
    }
    a=password[0]*1000+password[1]*100+password[2]*10+password[3];
    return a;
}
void control(int password,int x){
    int number[4],pass[4],i,j;
    for(i=3;i>=0;i--){
        pass[i]=password %10;
        password=password/10;
    }
    for(i=3;i>=0;i--){
        number[i]=x%10;
        x=x/10;
    }
    for(i=0;i<4;i++){
        if(number[i]==pass[i]){
            printf("%d this is in the correct place\n",number[i]);
        }
    }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(pass[i]==number[j]&&i!=j){
                    printf("%d this number is available but not there\n",number[j]);
                }
            }
        }
}

int main(){
    srand(time(NULL));
    int password,a,guess=9;
    password =randomNumber();
    while(guess>=0){
        printf("pls write a 4-digit number\n");
        scanf("%d",&a);
        if(a>=1000&&a<=9999){

            if(password==a){
                printf("congrtulations this number is true\n");
                break;
            }
            control(password,a);
            printf("%d guess left\n",guess);
            guess--;
        }
        else{
            printf("error !!pls enter 4-digit number\n");
        }
    }
    if(guess==-1){
        printf("you lost the number is =%d\n",password);
    }

  return 0;
}

