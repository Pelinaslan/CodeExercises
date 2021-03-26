//
//  main.c
//  yapisal_final
//
//  Created by Pelin ASLAN on 2.06.2020.
//  Copyright © 2020 Pelin Aslan. All rights reserved.
//


//ilk kesim aşamasindan sonraki kartlari yazdirmiyor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct KART{
    char *cins;
    char *no;
};


//deste karistir
void karistir(struct KART *Deste){
    int i,j;
    struct KART temp;
    for(i=0; i<52; ++i){
        j = rand() %52;
        temp =Deste[i];
        Deste[i] = Deste[j];
        Deste[j] = temp;
    }
}


void desteyap(struct KART *Deste, char *cins[], char *no[]){
    int i;
    
    for (i=0; i<52; ++i){
        Deste[i].no= no[i % 13];
        Deste[i].cins=cins[i/13];
    }
}


void dagit(struct KART *Deste,struct KART *Oyuncu1,struct KART *Oyuncu2,struct KART *Oyuncu3,struct KART *yer,struct KART *O1,struct KART *O2){
    int i,y=0;
    
    
    for(i=0; i<4; i++){
        
        Oyuncu3[i]=Deste[i];
        yer[y] = Oyuncu3[i];//ilk dört karti diziye attik
        y=y+1;
        
    }  //ik 4 kart ortaya
    //y=4
    
    y=y-1;//y son kartin numarasini tutar
    printf("yere acilan ilk kart= %5s - %-8s\n ",Oyuncu3[3].cins,Oyuncu3[3].no); //sadece sonuncu acik karti yazar
    printf("\n");
    
    int a=0,ab=0; //oyuncu ve bilgisayarin topladigi kartlarin sayisini tutar
    for(i=4; i<52;  ){
        
        for(int j=0; j<4; j++){
            Oyuncu1[j]=Deste[i];
            
            printf("%d) oyuncu = %5s - %-8s\n ",j+1,Oyuncu1[j].cins,Oyuncu1[j].no);
            i++;
            
        }
        printf("\n");
        
        for(int p=0; p<4; p++){
            Oyuncu2[p]=Deste[i];
            //printf("oyuncu 2= %5s - %-8s\n ",Oyuncu2[p].cins,Oyuncu2[p].no);
            i++;
            
        }
        printf("\n");
        
        
        //4 kere donguyu tekrarlayarak tek elde cekilen 4 kartin ortaya atilmasini saglar
        for(int s=0; s<4; s++){
            int secim;
            printf("atmak istediginiz kartin numarasini giriniz:");
            scanf("%d",&secim);
            
            
            if(Oyuncu1[secim-1].no == yer[y].no && yer[1].no != NULL ) {
                
                printf("kartları %5s - %-s kullanarak kestiniz yerde %5s - %-s vardi \n ",Oyuncu1[secim-1].cins,Oyuncu1[secim-1].no,yer[y].cins,yer[y].no );
                
                y=y+1;
                yer[y] = Oyuncu1[secim-1];  //yere atilan karti diziye attik
                
                int boyut=0;
                while(yer[boyut].no != NULL){
                    boyut++;
                }
                
                for(int i=0 ;i<boyut;i++){
                    
                    O1[a]=yer[i];    //yerdeki tüm kartlari o1 dizisine attik
                    
                    yer[i].no = NULL;
                    yer[i].cins = NULL;
                    
                    a=a+1;
                    
                    y=0; //yerdeki kartlari temizledik
                    
                    
                }
                
                
            }
            
            
            else if(Oyuncu1[secim-1].no == yer[0].no && yer[1].no == NULL  ){     //pisti yaparsak
                
                printf("%5s - %-s ile pişti yaptiniz yerde %5s - %-s vardı \n",Oyuncu1[secim-1].cins,Oyuncu1[secim-1].no,yer[0].cins,yer[0].no);
                
                
                //pisti yapildiysa topladigi kart bilgisi olarak (pisti - pisti yaptigi kart numarasi) yazilir
                //daha sonra puan fonk. pisti sayisina göre toplam kart sayisi artiyor..!
                O1[a].cins="pisti";
                O1[a].no = Oyuncu1[secim-1].no;
                a=a+1;
                
                
                yer[0].no = NULL;
                yer[0].cins = NULL;
                
                yer[1].no = NULL;
                yer[1].cins = NULL;
                y=0;
                //yerdeki kartlari temizledik
                
                
            }
            
            
            //seçtigim kart vale ise
            else if(Oyuncu1[secim-1].no == "vale" && yer[0].no != NULL){
                
                printf("kartlari %5s - %-s (vale) ile kestiniz yerdeki son kart %5s - %-s 'di \n",Oyuncu1[secim-1].cins,Oyuncu1[secim-1].no,yer[y].cins,yer[y].no);
                y=y+1;
                yer[y] = Oyuncu1[secim-1];  //yere atilan karti diziye attik
                
                int boyut=0;
                while(yer[boyut].no != NULL){
                    boyut++;
                }
                
                
                for(int i=0 ;i<boyut;i++){
                    
                    O1[a]=yer[i];
                    
                    yer[i].no = NULL;
                    yer[i].cins = NULL;
                    a=a+1;
                    
                    y=0;
                    
                    //yerdeki kartlari temizledik
                    
                }
                
            }
            
            else{
                
                if(yer[0].no ==NULL){      //yerde hiç kart yoksa
                    yer[0] = Oyuncu1[secim-1];
                }
                
                else{
                    y=y+1;
                    yer[y] = Oyuncu1[secim-1];  //yere atilan karti diziye attik
                }
                printf("attiginiz kart= %5s - %-8s \n ",Oyuncu1[secim-1].cins,Oyuncu1[secim-1].no);
                
            }
            
            
            
            
            
            //bilgisayar kart atacak
            //tüm kartlara bakar uygun olani atar..!
            int sonuc =0;
            for(int b=0; b<4; b++){
                
                //kartim yerdeki son kartla ayni,keser!
                if(yer[y].no == Oyuncu2[b].no && yer[1].no != NULL){
                    
                    printf("bilgisayar %5s - %-s ile kartlari kesti yerde %5s - %-s vardi \n",Oyuncu2[b].cins,Oyuncu2[b].no,yer[y].cins,yer[y].no);
                    
                    y=y+1;
                    yer[y] = Oyuncu2[b]; //yere atilan karti diziye attik
                    
                    int boyutt=0;
                    while(yer[boyutt].no != NULL){
                        boyutt++;
                    }
                    
                    for(int i=0;i<boyutt ;i++){
                        
                        O2[ab]=yer[i];       //kestigi kartlari o2 dizisine atadik
                        yer[i].no = NULL;
                        yer[i].cins = NULL;
                        
                        ab=ab+1;
                        
                        y=0;    //yerdeki kartlari temizledik
                        
                        
                    }
                    
                    
                    Oyuncu2[b].no = "bos";
                    Oyuncu2[b].cins = "bos";
                    sonuc=1;
                    //bilgisayarin attigi karti sildik
                    break;
                    
                }
                
            }
            
            if(sonuc != 1){
                for(int b=0; b<4; b++){
                    
                    //pisti yaparsak
                    if(Oyuncu2[b].no == yer[0].no && yer[1].no == NULL){
                        
                        printf("bilgisayar %5s - %-s ile pişti yapti yerde %5s - %-s vardi \n",Oyuncu2[b].cins,Oyuncu2[b].no,yer[0].cins,yer[0].no);
                        
                        //pisti yapildiysa topladigi kart bilgisi olarak (pisti - pisti yaptigi kart numarasi) yazilir
                        //daha sonra puan fonk. pisti sayisina göre toplam kart sayisi artiyor..!
                        O2[ab].cins = "pisti";
                        O2[ab].no=Oyuncu2[b].no;
                        ab=ab+1;
                        
                        
                        yer[0].no = NULL;
                        yer[0].cins = NULL;
                        
                        yer[1].no = NULL;
                        yer[1].cins = NULL;
                        y=0;
                        //yerdeki kartlari temizledik
                        
                        
                        
                        
                        
                        printf("\n");
                        Oyuncu2[b].no = "bos";
                        Oyuncu2[b].cins = "bos";
                        sonuc=1;
                        break;
                    }
                }
            }
            
            
            
            if(sonuc != 1){
                for(int b=0; b<4; b++){
                    //ayni kart yoksa ve pişti yapamiyorsa vale var mi kontrolu yerde hiç kart yoksa vale atmaz, 1 tane varsa atar pişti yapma ihtimali için!!!
                    if(Oyuncu2[b].no == "vale" && yer[0].no != NULL ){
                        
                        
                        printf("bilgisayar %5s - %-s (vale) ile kartlari kesti yerdeki son kart %5s - %-s 'di \n",Oyuncu2[b].cins,Oyuncu2[b].no,yer[y].cins,yer[y].no);
                        
                        y=y+1;
                        yer[y] = Oyuncu2[b];    //yere atilan karti diziye attik
                        
                        int boyutt=0;
                        while(yer[boyutt].no != NULL){
                            boyutt++;
                        }
                        
                        for(int i=0 ;i<boyutt ;i++){
                            
                            O2[ab]=yer[i];
                            
                            yer[i].no = NULL;
                            yer[i].cins = NULL;
                            ab=ab+1;
                            
                            y=0;
                            //yerdeki kartlari temizledik
                        }
                        
                        //attigi kartin indisini sildik
                        Oyuncu2[b].no = "bos";
                        Oyuncu2[b].cins = "bos";
                        sonuc=1;
                        break;
                    }
                }
            }
            
            
            
            
            
            if(sonuc != 1){
                
                for(int b=0; b<3; b++){
                    
                    //hicbir kosula uymuyorsa bos olmayan ve aynisindan 2 tane olan ilk karti atar..!
                    if(Oyuncu2[b].no != "bos" && Oyuncu2[b].no != "vale"){
                        
                        int c=b+1;
                        
                        for( ;c<4;c++){
                            
                            if(Oyuncu2[b].no == Oyuncu2[c].no){
                                if(yer[0].no == NULL){
                                    
                                    yer[0] = Oyuncu2[b];//yere atilan karti diziye attik
                                }
                                else{
                                    
                                    y=y+1;
                                    yer[y] = Oyuncu2[b];//yere atilan karti diziye attik
                                    
                                }
                                printf("bilgisayarın attigi kart= %5s - %-8s \n ",Oyuncu2[b].cins,Oyuncu2[b].no);
                                Oyuncu2[b].no = "bos";
                                Oyuncu2[b].cins = "bos"; //attigi kartin indisini sildik
                                sonuc=1;
                                break;
                            }
                            
                        }// for c sonu
                        
                    }
                }
            }
            
            
            
            
            if(sonuc != 1){
                
                for(int b=0; b<4; b++){
                    
                    //hicbir kosula uymuyorsa ayni karttan 2 tane de yoksa bos olmayan ilk karti atar
                    if(Oyuncu2[b].no != "bos" && Oyuncu2[b].no != "vale"){
                        if(yer[0].no == NULL){
                            
                            yer[0] = Oyuncu2[b];//yere atilan karti diziye attik
                        }
                        else{
                            
                            y=y+1;
                            yer[y] = Oyuncu2[b];//yere atilan karti diziye attik
                            
                        }
                        printf("bilgisayarın attigi kart= %5s - %-8s \n ",Oyuncu2[b].cins,Oyuncu2[b].no);
                        Oyuncu2[b].no = "bos";
                        Oyuncu2[b].cins = "bos"; //attigi kartin indisini sildik
                        sonuc=1;
                        break;
                    }
                    
                }
                
            }
            
            
            //4 karta da bakti ve yerde kart yokken bilgisayarin elinde sadece vale kaldiysa bu döngüye girer
            if(sonuc != 1){
                
                for(int b=0; b<4; b++){
                    
                    // bos olmayan tek kart vale ise..
                    if(Oyuncu2[b].no != "bos"){
                        if(yer[0].no == NULL){
                            
                            yer[0] = Oyuncu2[b];//yere atilan karti diziye attik
                        }
                        else{
                            
                            y=y+1;
                            yer[y] = Oyuncu2[b];//yere atilan karti diziye attik
                            
                        }
                        printf("bilgisayarın attigi kart= %5s - %-8s \n ",Oyuncu2[b].cins,Oyuncu2[b].no);
                        Oyuncu2[b].no = "bos";
                        Oyuncu2[b].cins = "bos"; //attigi kartin indisini sildik
                        
                        break;
                    }
                    
                }
                
                
            }
            
            
            
            
        }//4 lük for sonu
        
        
    }//52 lik for sonu
    
    
    
    printf("---oyuncunun elindeki kartlar--- \n");
    for(int i=0;i<a;i++){
        
        
        printf(" %5s - %-s\n",O1[i].cins,O1[i].no);
        
    }
    
    
    
    
    printf("\n");
    
    
    
    printf("---bilgisayarin elindeki kartlar---\n");
    for(int i=0;i<ab;i++){
        
        printf(" %5s - %-s\n",O2[i].cins,O2[i].no);
        
    }
    
    
    
    puan(Deste,O1,O2,a,ab);
    
}//dagit sonu

//oyuncu ve bilgisayarin topladigi kartlarin listelerini parametre olarak alip puanlarini hesaplar..
int puan(struct KART *Deste,struct KART *O1,struct KART *O2,int o1_sayisi,int o2_sayisi){
    
    int o1=0,o2=0;      //puani tutar
    
    
    
    for(int i=0; i<o1_sayisi; i++){
        if(O1[i].cins == "pisti"){
            
            if(O1[i].no=="vale"){
                o1=o1+20;
            }
            else{
                o1=o1+10;
            }
            
            o1_sayisi=o1_sayisi+1;//pisti yaptigimiz diger karti toplam karta ekledik
        }
        
        if(O1[i].cins == "maca" && O1[i].no == "iki"){
            o1=o1+2;
        }
        
        if(O1[i].cins == "karo" && O1[i].no == "on"){
            o1=o1+3;
        }
        
        if(O1[i].no == "as" || O1[i].no == "vale" ){
            o1=o1+1;
        }
        
        
    }
    
    
    
    for(int i=0; i<o2_sayisi; i++){
        if(O2[i].cins == "pisti"){
            
            if(O2[i].no=="vale"){
                o2=o2+20;
            }
            else{
                o2=o2+10;
            }
            
            o2_sayisi=o2_sayisi+1;//pisti yaptigimiz diger karti toplam karta ekledik
        }
        
        if(O2[i].cins == "maca" && O2[i].no == "iki"){
            o2=o2+2;
        }
        
        if(O2[i].cins == "karo" && O2[i].no == "on"){
            o2=o2+3;
        }
        
        if(O2[i].no == "as" || O2[i].no == "vale" ){
            o2=o2+1;
        }
        
    }
    
    
    
    //toplam kart miktari fazla olan +3 puan alir esitse kimse almaz
    if(o1_sayisi>o2_sayisi){
        o1=o1+3;
        
    }
    
    if(o1_sayisi<o2_sayisi){
        o2=o2+3;
        
    }
    
    printf("kart sayisi(oyuncu/bilgisayar)= %d/%d \n",o1_sayisi,o2_sayisi);
    
    if(o1>o2){
        printf("oyunu kazandiniz...\n");
        printf("puaniniz =%d\n",o1);
        printf("bilgisayarin puani =%d\n",o2);
    }
    else if(o1<o2){
        printf("bilgisayar kazandi...\n");
        printf("puanınız =%d\n",o1);
        printf("bilgisayarin puanı =%d\n",o2);
    }
    
    else{
        printf("berabere kaldiniz...!\n");
        printf("puanınız =%d\n",o1);
        printf("bilgisayarin puanı =%d\n",o2);
    }
    
    return o1,o2;
}








int main(int argc, const char * argv[]) {
    
    struct KART Deste[52];
    
    struct KART Oyuncu1[4];
    struct KART Oyuncu2[4]; //bilgisayar
    struct KART Oyuncu3[4]; //ilk el ortaya kart acmak icin
    struct KART yer[52];
    struct KART O1[52];
    struct KART O2[52];
    srand( time( 0 ) );
    
    
    char *no[] ={ "iki","uc","dort","bes","alti","yedi","sekiz","dokuz","on", "vale", "kiz", "papaz", "as"};
    char *cins[] ={"sinek","maca","karo","kupa"};
    
    desteyap(Deste,cins,no);
    karistir(Deste);
    dagit(Deste,Oyuncu1,Oyuncu2,Oyuncu3,yer,O1,O2);
    
    
    return 0;
                                            }


