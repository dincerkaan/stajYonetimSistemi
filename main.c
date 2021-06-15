#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *noPointer,ogrenciSayac=0,i=0,j=0, ogrenciKontrol=0,duzenlemeNumara,duzenlemeKontrol=0,duzenlemeBilgi,silmeBilgi,silmeKontrol=0,geciciNumara,stajEklemeNumara=0,stajEklemeVergi=0,stajSayac=0;
int genelMenuSecim, ogrenciMenuSecim, genelMenuDonme, kontrolNumara[40],yaziKontrol[40],stajNumaraGecici,stajVergiGecici,stajTuru,tarihSayac=0, stajYazdirma=0;
int firmaMenuSecim, *vergiNoPointer, firmaSayac=0, geciciVergi, kontrolVergi[40], yazdirmaKontrol[40],vergiKontrol=0,stajMenuSecim,stajDevam;
char *adPointer[40], *soyadPointer[40], *telefonPointer[40], *firmaAdPointer[40], *faaliyetPointer[40],denemeToplam=0;

typedef struct{
int ogrenciNo;
char ogrenciAd[40];
char ogrenciSoyad[40];
char ogrenciTelefon[40];
}ogrenciStruct;
ogrenciStruct ogrenci[40];

typedef struct{
int vergiNo;
char firmaAd[40];
char faaliyetAlani[40];
}firmaStruct;
firmaStruct firma[40];

typedef struct{
int stajOgrenciNo;
int stajVergiNo;
int yazilimStajBaslangicGun[40];
int yazilimStajBaslangicAy[40];
int yazilimStajBaslangicYil[40];
int yazilimStajBitisGun[40];
int yazilimStajBitisAy[40];
int yazilimStajBitisYil[40];
int donanimStajBaslangicGun[40];
int donanimStajBaslangicAy[40];
int donanimStajBaslangicYil[40];
int donanimStajBitisGun[40];
int donanimStajBitisAy[40];
int donanimStajBitisYil[40];
int yazilimStajHafta[40];
int donanimStajHafta[40];
int gecerliYazdirma;
int yazilimStajToplam;
int donanimStajToplam;
int yazdirma;
}stajStruct;
stajStruct staj[40];

FILE *ogrenciDosya;
FILE *firmaDosya;
FILE *stajDosya;

genelMenu(){
    printf("\n\tGENEL MENU SECIM EKRANI");
    printf("\n_____________________________________");
    printf("\n1- Ogrenci Islemleri");
    printf("\n2- Firma Islemleri");
    printf("\n3- Staj Islemleri");
    printf("\n\nYapmak istediginiz islemi seciniz: ");
    scanf("%d",&genelMenuSecim);

    switch(genelMenuSecim){
        case 1:
            ogrenciMenu();
            break;
        case 2:
            firmaMenu();
            break;
        case 3:
            stajMenu();
            break;
        default:
            printf("\nLutfen gecerli bir deger giriniz!");
    }
}

ogrenciMenu(){
    printf("\n\n\tOGRENCI MENU SECIM EKRANI");
    printf("\n_____________________________________");
    printf("\n1- Ogrenci Ekleme Islemi");
    printf("\n2- Ogrenci Duzenleme Islemi");
    printf("\n3- Ogrenci Silme Islemi");
    printf("\n4- Ogrenci Listeleme Islemi");
    printf("\n5- Genel Menuye Donme Islemi");
    printf("\n\nYapmak istediginiz islemi seciniz: ");
    scanf("%d",&ogrenciMenuSecim);

    switch(ogrenciMenuSecim){
        case 1:
            ogrenciEkleme();
            break;
        case 2:
            ogrenciDuzenleme();
            break;
        case 3:
            ogrenciSilme();
            break;
        case 4:
            ogrenciListeleme();
            break;
        case 5:
            genelMenu();
            break;
        default:
            printf("\nLutfen gecerli bir deger giriniz!");
    }
}

firmaMenu(){
    printf("\n\n\tFIRMA MENU SECIM EKRANI");
    printf("\n_____________________________________");
    printf("\n1- Firma Ekleme Islemi");
    printf("\n2- Firma Duzenleme Islemi");
    printf("\n3- Firma Silme Islemi");
    printf("\n4- Firma Listeleme Islemi");
    printf("\n5- Genel Menuye Donme Islemi");
    printf("\n\nYapmak istediginiz islemi seciniz: ");
    scanf("%d",&firmaMenuSecim);

    switch(firmaMenuSecim){
        case 1:
            firmaEkleme();
            break;
        case 2:
            firmaDuzenleme();
            break;
        case 3:
            firmaSilme();
            break;
        case 4:
            firmaListeleme();
            break;
        case 5:
            genelMenu();
            break;
        default:
            printf("\nLutfen gecerli bir deger giriniz!");
    }
}

stajMenu(){
    printf("\n\nSTAJ MENU SECIM EKRANI");
    printf("\n____________________________");
    printf("\n1- Staj Ekleme Islemleri");
    printf("\n2- Tamamlanmamis Stajlari Listeleme");
    printf("\n3- Tamamlanmis Stajlari Listeleme");
    printf("\n4- Genel Menuye Donme Islemi");
    printf("\n\nYapmak istediginiz islemi seciniz: ");
    scanf("%d",&stajMenuSecim);

    switch(stajMenuSecim){
        case 1:
            stajEkleme();
            break;
        case 2:
            tamamlanmamisStajListeleme();
            break;
        case 3:
            tamamlanmisStajListeleme();
            break;
        case 4:
            genelMenu();
            break;
        default:
            printf("\nLutfen gecerli bir deger giriniz!");
    }
}

ogrenciEkleme(){

noPointer = &ogrenci[ogrenciSayac].ogrenciNo;
adPointer[ogrenciSayac] = &ogrenci[ogrenciSayac].ogrenciAd;
soyadPointer[ogrenciSayac] = &ogrenci[ogrenciSayac].ogrenciSoyad;
telefonPointer[ogrenciSayac]=&ogrenci[ogrenciSayac].ogrenciTelefon;

printf("\nOgrencinin numarasini giriniz: ");
scanf("%d",&geciciNumara);

kontrolNumara[ogrenciSayac]=geciciNumara;

for(i=0;i<=ogrenciSayac;i++){
    if(geciciNumara==kontrolNumara[i-1]){
        yaziKontrol[ogrenciSayac]=0;
        break;
    }
    else{
        ogrenci[ogrenciSayac].ogrenciNo=kontrolNumara[ogrenciSayac];
        yaziKontrol[ogrenciSayac]=1;
    }
}

for(i=0;i<=ogrenciSayac;i++){
    if(geciciNumara == ogrenci[i-1].ogrenciNo)
    {
        printf("GIRILEN NUMARAYA AIT BIR KAYIT BULUNMAKTADIR LUTFEN GECERLI BIR OGRENCI NUMARASI GIRINIZ!\n");
        ogrenciKontrol=1;
        break;
    }
}

if(ogrenciKontrol==0){
    printf("Ogrencinin adini giriniz: ");
    scanf("%s",adPointer[ogrenciSayac]);
    printf("Ogrencinin soyadini giriniz: ");
    scanf("%s",soyadPointer[ogrenciSayac]);
    printf("Ogrencinin telefon numarasini giriniz: ");
    scanf("%s",telefonPointer[ogrenciSayac]);

    ogrenciDosya = fopen("ogrenciler.txt", "a");
    fprintf(ogrenciDosya,"Ogrenci Numarasi: %d\nOgrenci Ad: %s\nOgrenci Soyad: %s\nOgrenci Telefon: %s\n\n",*noPointer,adPointer[ogrenciSayac], soyadPointer[ogrenciSayac], telefonPointer[ogrenciSayac]);
    fclose(ogrenciDosya);
    ogrenciSayac++;
    }

    ogrenciKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

ogrenciDuzenleme(){

printf("\nBilgileri duzenlenecek ogrencinin numarasini giriniz: ");
scanf("%d",&duzenlemeNumara);

for(i=0;i<ogrenciSayac;i++){
    if(duzenlemeNumara==ogrenci[i].ogrenciNo){
        printf("\n\n\tOGRENCI BILGI DUZENLEME MENUSU ");
        printf("\n_____________________________________________________");
        printf("\n1- Ogrencinin adi ");
        printf("\n2- Ogrencinin soyadi ");
        printf("\n3- Ogrencinin telefon numarasi ");
        printf("\n4- Ogrencinin butun bilgileri ");
        printf("\n\nYapmak istediginiz islemi seciniz: ");
        scanf("%d",&duzenlemeBilgi);

        switch(duzenlemeBilgi){
            case 1:
                printf("\nOgrencinin adini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciAd);
                printf("\nBilgilendirme: %d Numarali ogrencinin adi %s olarak duzenlenmistir..", duzenlemeNumara, adPointer[i]);
                break;
            case 2:
                printf("\nOgrencinin soyadini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciSoyad);
                printf("\nBilgilendirme: %d Numarali ogrencinin soyadi %s olarak duzenlenmistir..", duzenlemeNumara, soyadPointer[i]);
                break;
            case 3:
                printf("\nOgrencinin telefon numarasini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciTelefon);
                printf("\nBilgilendirme: %d Numarali ogrencinin telefon numarasi %s olarak duzenlenmistir..", duzenlemeNumara, telefonPointer[i]);
                break;
            case 4:
                printf("\nOgrencinin adini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciAd);
                printf("Ogrencinin soyadini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciSoyad);
                printf("Ogrencinin telefon numarasini giriniz: ");
                scanf("%s",&ogrenci[i].ogrenciTelefon);
                printf("Bilgilendirme: %d Numarali ogrencinin butun bilgileri duzenlenmistir..", duzenlemeNumara);
                ogrenci[i].ogrenciNo = duzenlemeNumara;
                break;
            default:
                printf("Lutfen gecerli bir deger giriniz!\n");
        }
        duzenlemeKontrol=1;
        break;
    }
}
    ogrenciDosya = fopen("ogrenciler.txt", "w");

    for(i=0;i<=ogrenciSayac-1;i++){
        fprintf(ogrenciDosya,"Ogrenci Numarasi: %d\nOgrenci Ad: %s\nOgrenci Soyad: %s\nOgrenci Telefon: %s\n\n",ogrenci[i].ogrenciNo, ogrenci[i].ogrenciAd, ogrenci[i].ogrenciSoyad, ogrenci[i].ogrenciTelefon);
    }
    fclose(ogrenciDosya);

    if(duzenlemeKontrol==0){
        printf("\nGIRILEN OGRENCI NUMARASI SISTEMDE KAYITLI DEGIL GECERLI BIR OGRENCI NUMARASI GIRINIZ!\n");
    }

    duzenlemeKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

ogrenciSilme(){
    printf("\nBilgileri silinecek ogrencinin numarasini giriniz: ");
    scanf("%d",&silmeBilgi);
    for(i=0;i<=ogrenciSayac;i++){
        if(silmeBilgi == ogrenci[i].ogrenciNo){
            ogrenci[i].ogrenciNo=-1;
            kontrolNumara[i] = -1;
            strcpy(ogrenci[i].ogrenciAd, "Silindi");
            strcpy(ogrenci[i].ogrenciSoyad, "Silindi");
            strcpy(ogrenci[i].ogrenciTelefon, "Silindi");
            printf("\n%d Numarali ogrencinin verileri silinmistir.", silmeBilgi);
            silmeKontrol=1;
        }
    }

    ogrenciDosya = fopen("ogrenciler.txt", "w");
    for(i=0;i<=ogrenciSayac-1;i++){
        fprintf(ogrenciDosya,"Ogrenci Numarasi: %d\nOgrenci Ad: %s\nOgrenci Soyad: %s\nOgrenci Telefon: %s\n\n",ogrenci[i].ogrenciNo,adPointer[i], soyadPointer[i], telefonPointer[i]);
    }
    fclose(ogrenciDosya);

    if(silmeKontrol==0){
        printf("\n\nSILMEK ISTEDIGINIZ OGRENCI NUMARASI SISTEMDE KAYITLI DEGIL GECERLI BIR OGRENCI NUMARASI GIRINIZ!");
    }
    silmeKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

ogrenciListeleme(){
    printf("\n\t\t\t\tOGRENCI LISTESI ");
    printf("\n ----------------------------------------------------------------------");
    printf("\nOgrenci No \t       Ogrenci Ad \t    Ogrenci Soyad \t    Ogrenci Telefon");
    printf("\n____________ \t    _________________ \t ____________________ \t ______________________");

    for(i=0;i<=ogrenciSayac;i++){
        if(ogrenci[i].ogrenciNo>0 && yaziKontrol[i]==1){
            printf("\n    %d \t\t\t %s \t\t %s \t\t %s",ogrenci[i].ogrenciNo,adPointer[i],soyadPointer[i],telefonPointer[i]);
        }
    }

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

firmaEkleme(){

vergiNoPointer = &firma[firmaSayac].vergiNo;
firmaAdPointer[firmaSayac] = &firma[firmaSayac].firmaAd;
faaliyetPointer[firmaSayac] = &firma[firmaSayac].faaliyetAlani;

printf("\nFirmanin vergi numarasini giriniz: ");
scanf("%d", &geciciVergi);

kontrolVergi[firmaSayac]=geciciVergi;

for(i=0;i<=firmaSayac;i++){
    if(geciciVergi==kontrolVergi[i-1]){
            yazdirmaKontrol[firmaSayac]=0;
        break;
    }
    else{
        firma[firmaSayac].vergiNo=kontrolVergi[firmaSayac];
        yazdirmaKontrol[firmaSayac]=1;
        }
}

for(i=0;i<=firmaSayac;i++){
    if(geciciVergi==firma[i-1].vergiNo){
        printf("\nGIRILEN VERGI NUMARASINA AIT BIR KAYIT BULUNMAKTADIR LUTFEN GECERLI BIR VERGI NUMARASI GIRINIZ!\n");
        vergiKontrol=1;
        break;
    }
}

if(vergiKontrol==0){
    printf("Firmanin adini giriniz: ");
    scanf("%s",firmaAdPointer[firmaSayac]);
    printf("Firmanin faaliyet alanini giriniz: ");
    scanf("%s",faaliyetPointer[firmaSayac]);

    firmaDosya=fopen("firmalar.txt", "a");
    fprintf(firmaDosya,"Firma Vergi Numarasi: %d\nFirma Ad: %s\nFirma Faaliyet Alani: %s\n\n",*vergiNoPointer,firmaAdPointer[firmaSayac],faaliyetPointer[firmaSayac]);
    fclose(firmaDosya);
    firmaSayac++;
}

vergiKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

firmaDuzenleme(){

printf("\nBilgileri duzenlenecek firmanin vergi numarasini giriniz: ");
scanf("%d",&duzenlemeNumara);

for(i=0;i<firmaSayac;i++){
    if(duzenlemeNumara==firma[i].vergiNo){
        printf("\n\n\tFIRMA BILGI DUZENLEME MENUSU ");
        printf("\n_____________________________________________________");
        printf("\n1- Firmanin adi ");
        printf("\n2- Frimanin faaliyet alani ");
        printf("\n3- Firmanin butun bilgileri ");
        printf("\n\n\tYapmak istediginiz islemi seciniz: ");
        scanf("%d",&duzenlemeBilgi);

        switch(duzenlemeBilgi){
            case 1:
                printf("\nFirmanin adini giriniz: ");
                scanf("%s",&firma[i].firmaAd);
                printf("\n\nBILGILENDIRME: %d Vergi numarali firmanin adi %s olarak duzenlenmistir..", duzenlemeNumara, firmaAdPointer[i]);
                break;
            case 2:
                printf("\nFirmanin faaliyet alanini giriniz: ");
                scanf("%s",&firma[i].faaliyetAlani);
                printf("\nBILGILENDIRME: %d Vergi numarali firmanin faaliyet alani %s olarak duzenlenmistir..", duzenlemeNumara, faaliyetPointer[i]);
                break;
            case 3:
                printf("\nFirmanin adini giriniz: ");
                scanf("%s",&firma[i].firmaAd);
                printf("Firmanin faaliyet alanini giriniz: ");
                scanf("%s",&firma[i].faaliyetAlani);
                printf("Bilgilendirme: %d Vergi numarali fabrikanin butun bilgileri duzenlenmistir..", duzenlemeNumara);
                firma[i].vergiNo = duzenlemeNumara;
                break;
            default:
                printf("Lutfen gecerli bir deger giriniz!\n");
        }
        duzenlemeKontrol=1;
        break;
    }
}
    firmaDosya = fopen("firmalar.txt", "w");

    for(i=0;i<=firmaSayac-1;i++){
        fprintf(firmaDosya,"Firma Vergi Numarasi: %d\nFirma Ad: %s\nFirma Faaliyet Alani: %s\n\n",firma[i].vergiNo, firma[i].firmaAd, firma[i].faaliyetAlani);
    }
    fclose(firmaDosya);

    if(duzenlemeKontrol==0){
        printf("\nGIRILEN FIRMA VERGI NUMARASI SISTEMDE KAYITLI DEGIL GECERLI BIR FIRMA VERGI NUMARASI GIRINIZ!\n");
    }

    duzenlemeKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

firmaSilme(){
    printf("\nBilgileri silinecek firmanin vergi numarasini giriniz: ");
    scanf("%d",&silmeBilgi);
    for(i=0;i<=firmaSayac;i++){
        if(silmeBilgi == firma[i].vergiNo){
            firma[i].vergiNo=-1;
            kontrolVergi[i] = -1;
            strcpy(firma[i].firmaAd, "Silindi");
            strcpy(firma[i].faaliyetAlani, "Silindi");
            printf("\n%d Vergi numarali fabrikanin verileri silinmistir.\n", silmeBilgi);
            silmeKontrol=1;
        }
    }

    firmaDosya = fopen("firmalar.txt", "w");
    for(i=0;i<=firmaSayac-1;i++){
        fprintf(firmaDosya,"Firma Vergi Numarasi: %d\nFirma Ad: %s\nFirma Faaliyet Alani: %s\n\n",firma[i].vergiNo,firmaAdPointer[i], faaliyetPointer[i]);
    }
    fclose(ogrenciDosya);

    if(silmeKontrol==0){
        printf("\n\nSILMEK ISTEDIGINIZ FIRMA VERGI NUMARASI SISTEMDE KAYITLI DEGIL GECERLI BIR FIRMA VERGI NUMARASI GIRINIZ!");
    }
    silmeKontrol=0;

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

firmaListeleme(){
    printf("\n\t\t\t\tFIRMA LISTESI ");
    printf("\n ----------------------------------------------------------------------");
    printf("\nFirma Vergi No \t         Firma Ad \t          Firma Faaliyet Alani ");
    printf("\n________________ \t_________________ \t ______________________");
    for(i=0;i<=firmaSayac;i++){
        if(firma[i].vergiNo>0 && yazdirmaKontrol[i]==1){
            printf("\n    %d \t\t\t %s \t\t   %s ",firma[i].vergiNo,firmaAdPointer[i],faaliyetPointer[i]);
        }
    }

    printf("\nGenel menuye donmek icin 0'i, cikis yapmak icin baska bir sayiya basiniz: ");
    scanf("%d",&genelMenuDonme);

    while(genelMenuDonme==0){
        genelMenu();
    }
}

stajEkleme(){
printf("\nStaj yapacak ogrencinin numarasini giriniz: ");
scanf("%d",&stajNumaraGecici);

for(i=0;i<=ogrenciSayac;i++){
        if(stajNumaraGecici==ogrenci[i].ogrenciNo){
            stajEklemeNumara=1;
            staj[stajSayac].stajOgrenciNo=stajNumaraGecici;
        }
}

if(stajEklemeNumara==1){
    tarihHesaplama();
}

if(stajEklemeNumara==0){
    printf("\nGirilen ogrenci numarasi sistemde kayitli degildir!");
    stajMenu();
}

}

tarihHesaplama(){

if(stajEklemeNumara==1){
    printf("Staj yapilacak firmanin vergi numarasini giriniz: ");
    scanf("%d",&stajVergiGecici);

    for(i=0;i<=firmaSayac;i++){
            if(stajVergiGecici==firma[i].vergiNo){
                staj[stajSayac].stajVergiNo=stajVergiGecici;
                stajEklemeVergi=1;
                break;
            }
    }
}

if(stajEklemeVergi==0){
    printf("\nGirilen firma vergi numarasi sistemde kayitli degildir!");
    stajMenu();
}

if(stajEklemeNumara==1 && stajEklemeVergi==1){
    printf("\n1- Yazilim Staji");
    printf("\n2- Donanim Staji");
    printf("\nStaj Turunu Seciniz: ");
    scanf("%d",&stajTuru);
    if(stajTuru!=1 && stajTuru!=2){
        printf("Girilen deger gecersiz, lutfen gecerli bir deger giriniz!");
        stajMenu();
    }
}

if(stajTuru==1){
    printf("\nStajin basladigi gunu giriniz (Ornek: 1-30): ");
    scanf("%d",&staj[stajSayac].yazilimStajBaslangicGun[tarihSayac]);
    printf("Stajin basladigi ayi giriniz (Ornek: 1-12): ");
    scanf("%d", &staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]);
    printf("Stajin basladigi yili giriniz: ");
    scanf("%d", &staj[stajSayac].yazilimStajBaslangicYil[tarihSayac]);
    printf("Stajin bittigi gunu giriniz (Ornek: 1-30): ");
    scanf("%d",&staj[stajSayac].yazilimStajBitisGun[tarihSayac]);
    printf("Stajin bittigi ayi giriniz (Ornek: 1-12):  ");
    scanf("%d", &staj[stajSayac].yazilimStajBitisAy[tarihSayac]);
    printf("Stajin bittigi yili giriniz: ");
    scanf("%d", &staj[stajSayac].yazilimStajBitisYil[tarihSayac]);

    if(staj[stajSayac].yazilimStajBaslangicYil[tarihSayac]==staj[stajSayac].yazilimStajBitisYil[tarihSayac]){
        if(staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]<staj[stajSayac].yazilimStajBitisAy[tarihSayac]){
            staj[stajSayac].yazilimStajHafta[tarihSayac]=((staj[stajSayac].yazilimStajBitisAy[tarihSayac]-staj[stajSayac].yazilimStajBaslangicAy[tarihSayac])*30+
                         (staj[stajSayac].yazilimStajBitisGun[tarihSayac]-staj[stajSayac].yazilimStajBaslangicGun[tarihSayac]+1))/7;
            stajYazdirma=1;
        }
        if(staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]>staj[stajSayac].yazilimStajBitisAy[tarihSayac]){
            printf("\nStaj baslangic tarihi, bitis tarihinden daha gec olamaz!");
            stajMenu();
        }
        if(staj[stajSayac].yazilimStajHafta[tarihSayac]>8){
            printf("\nBir yil icinde en fazla 8 hafta staj yapilabilir!");
            stajMenu();
        }
        if(staj[stajSayac].yazilimStajHafta[tarihSayac]<4){
            printf("\nBir yil icinde en az 4 hafta staj yapilabilir!");
            stajMenu();
        }
    }

    if(staj[stajSayac].yazilimStajBitisYil[tarihSayac]>staj[stajSayac].yazilimStajBaslangicYil[tarihSayac]){
        if(staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]>staj[stajSayac].yazilimStajBitisAy[tarihSayac]){
            staj[stajSayac].yazilimStajHafta[tarihSayac]=((staj[stajSayac].yazilimStajBitisYil[tarihSayac]-staj[stajSayac].yazilimStajBaslangicYil[tarihSayac])*360-
                         (staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]-staj[stajSayac].yazilimStajBitisAy[tarihSayac])*30-
                         (staj[stajSayac].yazilimStajBaslangicGun[tarihSayac]-staj[stajSayac].yazilimStajBitisGun[tarihSayac]-1))/7;
        }
        if(staj[stajSayac].yazilimStajBitisAy[tarihSayac]>=staj[stajSayac].yazilimStajBaslangicAy[tarihSayac]){
            staj[stajSayac].yazilimStajHafta[tarihSayac]=((staj[stajSayac].yazilimStajBitisYil[tarihSayac]-staj[stajSayac].yazilimStajBaslangicYil[tarihSayac])*360+
                         (staj[stajSayac].yazilimStajBitisAy[tarihSayac]-staj[stajSayac].yazilimStajBaslangicAy[tarihSayac])*30+
                         (staj[stajSayac].yazilimStajBitisGun[tarihSayac]-staj[stajSayac].yazilimStajBaslangicGun[tarihSayac]+1))/7;
        }
        if( staj[stajSayac].yazilimStajHafta[tarihSayac]>10){
            printf("\nYapilabilecek maksimum yazilim staj haftasi 10'dur. Gecerli bir deger giriniz!");
            stajMenu();
        }
        if(staj[stajSayac].yazilimStajHafta[tarihSayac]<=10){
             stajYazdirma=1;
        }
    }

    if(stajYazdirma==1){
        stajDosya=fopen("stajlar.txt", "a");
    fprintf(firmaDosya,"Ogrenci Numarasi: %d\nFirma Vergi Numarasi: %d\nStaj Baslangic Tarihi: %d.%d.%d\nStaj Bitis Tarihi: %d.%d.%d\n Staj Suresi: %d Hafta\n Staj Turu: Yazilim\n\n",staj[stajSayac].stajOgrenciNo,staj[stajSayac].stajVergiNo,
          staj[stajSayac].yazilimStajBaslangicGun[tarihSayac], staj[stajSayac].yazilimStajBaslangicAy[tarihSayac], staj[stajSayac].yazilimStajBaslangicYil[tarihSayac],
          staj[stajSayac].yazilimStajBitisGun[tarihSayac], staj[stajSayac].yazilimStajBitisAy[tarihSayac], staj[stajSayac].yazilimStajBitisYil[tarihSayac], staj[stajSayac].yazilimStajHafta[tarihSayac]);
    fclose(firmaDosya);

    for(i=0;i<=tarihSayac;i++){
        denemeToplam=denemeToplam+staj[stajSayac].yazilimStajHafta[i];
    }
    staj[stajSayac].yazilimStajToplam=denemeToplam;
    }

    denemeToplam=0;
    stajYazdirma=0;
}

if(stajTuru==2){
    printf("\nStajin basladigi gunu giriniz (Ornek: 1-30): ");
    scanf("%d",&staj[stajSayac].donanimStajBaslangicGun[tarihSayac]);
    printf("Stajin basladigi ayi giriniz(Ornek: 1-12): ");
    scanf("%d", &staj[stajSayac].donanimStajBaslangicAy[tarihSayac]);
    printf("Stajin basladigi yili giriniz: ");
    scanf("%d", &staj[stajSayac].donanimStajBaslangicYil[tarihSayac]);
    printf("Stajin bittigi gunu giriniz (Ornek: 1-30):");
    scanf("%d",&staj[stajSayac].donanimStajBitisGun[tarihSayac]);
    printf("Stajin bittigi ayi giriniz (Ornek: 1-12): ");
    scanf("%d", &staj[stajSayac].donanimStajBitisAy[tarihSayac]);
    printf("Stajin bittigi yili giriniz: ");
    scanf("%d", &staj[stajSayac].donanimStajBitisYil[tarihSayac]);

    if(staj[stajSayac].donanimStajBaslangicYil[tarihSayac]==staj[stajSayac].donanimStajBitisYil[tarihSayac]){
        if(staj[stajSayac].donanimStajBaslangicAy[tarihSayac]<staj[stajSayac].donanimStajBitisAy[tarihSayac]){
            staj[stajSayac].donanimStajHafta[tarihSayac]=((staj[stajSayac].donanimStajBitisAy[tarihSayac]-staj[stajSayac].donanimStajBaslangicAy[tarihSayac])*30+
                         (staj[stajSayac].donanimStajBitisGun[tarihSayac]-staj[stajSayac].donanimStajBaslangicGun[tarihSayac]+1))/7;
            stajYazdirma=1;
        }
        if(staj[stajSayac].donanimStajBaslangicAy[tarihSayac]>staj[stajSayac].donanimStajBitisAy[tarihSayac]){
            printf("\nStaj baslangic tarihi, bitis tarihinden daha gec olamaz!");
            stajYazdirma=0;
            stajMenu();
        }
        if(staj[stajSayac].donanimStajHafta[tarihSayac]>8){
            printf("\nBir yil icinde en fazla 8 hafta staj yapilabilir!");
            stajYazdirma=0;
            stajMenu();
        }
        if(staj[stajSayac].donanimStajHafta[tarihSayac]<4){
            printf("\nBir yil icinde en az 4 hafta staj yapilabilir!");
            stajYazdirma=0;
            stajMenu();
        }
    }

    if(staj[stajSayac].donanimStajBitisYil[tarihSayac]>staj[stajSayac].donanimStajBaslangicYil[tarihSayac]){
        if(staj[stajSayac].donanimStajBaslangicAy[tarihSayac]>staj[stajSayac].donanimStajBitisAy[tarihSayac]){
            staj[stajSayac].donanimStajHafta[tarihSayac]=((staj[stajSayac].donanimStajBitisYil[tarihSayac]-staj[stajSayac].donanimStajBaslangicYil[tarihSayac])*360-
                         (staj[stajSayac].donanimStajBaslangicAy[tarihSayac]-staj[stajSayac].donanimStajBitisAy[tarihSayac])*30-
                         (staj[stajSayac].donanimStajBaslangicGun[tarihSayac]-staj[stajSayac].donanimStajBitisGun[tarihSayac]-1))/7;
        }
        if(staj[stajSayac].donanimStajBitisAy[tarihSayac]>staj[stajSayac].donanimStajBaslangicAy[tarihSayac]){
            staj[stajSayac].donanimStajHafta[tarihSayac]=((staj[stajSayac].donanimStajBitisYil[tarihSayac]-staj[stajSayac].donanimStajBaslangicYil[tarihSayac])*360+
                         (staj[stajSayac].donanimStajBitisAy[tarihSayac]-staj[stajSayac].donanimStajBaslangicAy[tarihSayac])*30+
                         (staj[stajSayac].donanimStajBitisGun[tarihSayac]-staj[stajSayac].donanimStajBaslangicGun[tarihSayac]+1))/7;
        }

         if( staj[stajSayac].donanimStajHafta[tarihSayac]>8){
            printf("\nYapilabilecek maksimum donanim staj haftasi 8'dir. Gecerli bir deger giriniz!");
            stajYazdirma=0;
            stajMenu();
        }
        if(staj[stajSayac].donanimStajHafta[tarihSayac]<=8){
             stajYazdirma=1;
        }
    }

    if(stajYazdirma==1){
         stajDosya=fopen("stajlar.txt", "a");
    fprintf(firmaDosya,"Ogrenci Numarasi: %d\nFirma Vergi Numarasi: %d\nStaj Baslangic Tarihi: %d.%d.%d\nStaj Bitis Tarihi: %d.%d.%d\n Staj Suresi: %d Hafta\n Staj Turu: Donanim\n\n",staj[stajSayac].stajOgrenciNo,staj[stajSayac].stajVergiNo,
          staj[stajSayac].donanimStajBaslangicGun[tarihSayac], staj[stajSayac].donanimStajBaslangicAy[tarihSayac], staj[stajSayac].donanimStajBaslangicYil[tarihSayac],
          staj[stajSayac].donanimStajBitisGun[tarihSayac], staj[stajSayac].donanimStajBitisAy[tarihSayac], staj[stajSayac].donanimStajBitisYil[tarihSayac], staj[stajSayac].donanimStajHafta[tarihSayac]);
    fclose(firmaDosya);

    for(i=0;i<=tarihSayac;i++){
        denemeToplam=denemeToplam+staj[stajSayac].donanimStajHafta[i];
    }
    staj[stajSayac].donanimStajToplam=denemeToplam;
    }

    denemeToplam=0;
    stajYazdirma=0;
    }

    printf("\nOgrenciye ait baska staj bilgisi girilecekse 1'e, girilmeyecekse 2'ye basiniz: ");
    scanf("%d",&stajDevam);

if(stajDevam==1){
    tarihSayac++;
    tarihHesaplama();
}

if(stajDevam==2){
    if(staj[stajSayac].yazilimStajToplam>=4 && staj[stajSayac].donanimStajToplam>=2 && staj[stajSayac].yazilimStajToplam+staj[stajSayac].donanimStajToplam==12){
    staj[stajSayac].yazdirma=1;
    staj[stajSayac].gecerliYazdirma=1;
    }
    else{
    staj[stajSayac].yazdirma=2;
    staj[stajSayac].gecerliYazdirma=2;
    }
    stajSayac++;
    stajEklemeNumara=0;
    tarihSayac=0;
    stajMenu();
}

}

tamamlanmamisStajListeleme(){

printf("\n\n\t\t\t  ZORUNLU STAJ SURESINI TAMAMLAMAMIS OGRENCILER");
printf("\n\t\t\t____________________________________________________");
printf("\n\nOgrenci Numarasi\t Yazilim Staj Suresi\t   Donanim Staj Suresi\t        Toplam Staj Suresi");
printf("\n________________\t _____________________\t  _____________________\t       ________________________");

stajDosya = fopen("tamamlanmamisStajlar.txt", "w");
for(i=0;i<=stajSayac-1;i++){
    if(staj[i].yazdirma==2 && staj[i].gecerliYazdirma==2){
        printf("\n%d\t\t\t\t%d Hafta\t\t\t%d Hafta\t\t\t    %d Hafta",staj[i].stajOgrenciNo,staj[i].yazilimStajToplam,staj[i].donanimStajToplam,staj[i].yazilimStajToplam+staj[i].donanimStajToplam);

        fprintf(stajDosya,"Ogrenci Numarasi: %d\nYazilim Staj Suresi: %d\nDonanim Staj Suresi: %d\nToplam Staj Suresi: %d\n\n",staj[i].stajOgrenciNo,staj[i].yazilimStajToplam,
               staj[i].donanimStajToplam,staj[i].yazilimStajToplam+staj[i].donanimStajToplam);
    }
}

fclose(stajDosya);
stajMenu();
}

tamamlanmisStajListeleme(){

printf("\n\n\t\t\t  ZORUNLU STAJ SURESINI TAMAMLAMIS OGRENCILER");
printf("\n\t\t\t____________________________________________________");
printf("\n\nOgrenci Numarasi\t Yazilim Staj Suresi\t   Donanim Staj Suresi\t        Toplam Staj Suresi");
printf("\n________________\t _____________________\t  _____________________\t       ________________________");

stajDosya = fopen("tamamlanmisStajlar.txt", "w");
for(i=0;i<=stajSayac-1;i++){
    if(staj[i].yazdirma==1 && staj[i].gecerliYazdirma==1){
        printf("\n%d\t\t\t\t%d Hafta\t\t\t%d Hafta\t\t\t    %d Hafta",staj[i].stajOgrenciNo,staj[i].yazilimStajToplam,staj[i].donanimStajToplam,staj[i].yazilimStajToplam+staj[i].donanimStajToplam);

        fprintf(stajDosya,"\nOgrenci Numarasi: %d\nYazilim Staj Suresi: %d\nDonanim Staj Suresi: %d\nToplam Staj Suresi: %d\n\n",staj[i].stajOgrenciNo,staj[i].yazilimStajToplam,
               staj[i].donanimStajToplam,staj[i].yazilimStajToplam+staj[i].donanimStajToplam);
    }
}

fclose(stajDosya);
stajMenu();
}

int main()
{
    genelMenu();
    return 0;
}
