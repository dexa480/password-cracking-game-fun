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
    int pass_used[4] = {0,0,0,0}; // Hangi şifre basamaklarının eşleştiğini tutar
    int guess_used[4] = {0,0,0,0}; // Hangi tahmin basamaklarının kullanıldığını tutar

    for(i=3;i>=0;i--){
        pass[i]=password %10;
        password=password/10;
    }
    for(i=3;i>=0;i--){
        number[i]=x%10;
        x=x/10;
    }

    // 1. Adım: Tam eşleşmeleri (Yeşil / Correct Place) bul
    for(i=0;i<4;i++){
        if(number[i]==pass[i]){
            printf("%d bu sayı doğru yerde\n", number[i], i+1);
            pass_used[i] = 1;  // Bu şifre basamağı eşleşti, kapat.
            guess_used[i] = 1; // Bu tahmin basamağı kullanıldı, kapat.
        }
    }

    // 2. Adım: Yanlış yerdeki eşleşmeleri (Sarı / Wrong Place) bul
    for(i=0;i<4;i++){
        if(guess_used[i] == 1) continue; // Bu tahmin zaten tam eşleştiyse atla

        for(j=0;j<4;j++){
            // Eğer şifre basamağı henüz kullanılmadıysa VE sayılar eşleşiyorsa
            if(pass_used[j] == 0 && number[i] == pass[j]){
                printf("%d bu sayı var ama yeri yanlış\n", number[i], i+1);
                pass_used[j] = 1; // Bu şifre basamağını kullandık, başkası eşleşemesin
                break; // Bu tahmin rakamı için bir eşleşme bulduk, döngüden çık
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int password,a,guess=9;
    password =randomNumber();
    while(guess>=0){
        printf("lutfen 4 basamakli bir sayi girin\n");
        scanf("%d",&a);
        if(a>=1000 && a<=9999){ // Düzeltme: =< yerine <= olmalı

            if(password==a){
                printf("tebrikler bildiniz!\n");
                break;
            }
            control(password,a);
            printf("%d hakkiniz kaldi\n",guess);
            guess--;
        }
        else{
            printf("hata !! lutfen 4 basamakli sayi girin\n");
        }
    }
    if(guess==-1){
        printf("kaybettiniz, sayi =%d\n",password);
    }

  return 0;
}

