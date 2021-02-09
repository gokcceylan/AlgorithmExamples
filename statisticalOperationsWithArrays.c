#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double ortalama(int a[], int);
void yazdir(int a[], int);
void sifirla(int a[], int);
int mod(int a[], int);
double medyan(int a[], int);
double varyans(int a[], int);
double standart_sapma(int a[], int);
void terscevir(int a[], int);
void degistir(int a[], int n, int i, int yeniSayi);
void fillArrayWithRandoms(int array[], int size, int min, int max);

int main( void ) {
	srand(time(NULL));

	int size, min, max, mode, islem = 0, i, bayrak = 1, n, yeniSayi, oops=1;
	double aver, median, variance, stan;
	printf("Lutfen integer dizinizin kapasitesini giriniz: ");
	scanf("%d", &size);
	printf("Lutfen rastgele sayi araligini giriniz [a-b formatinda]: ");
	scanf("%d-%d", &min, &max);
	printf("Diziniz olusturulmustur.");
	int array[size];
	fillArrayWithRandoms(array, size, min, max);

	while (bayrak) {
		printf("***** Ne yapmak istersiniz? *****\n");
		printf("0. Cikis\n1. Elemanlari yazdir\n2. Ortalama al\n3. Modu bul\n4. Medyani bul\n5. Varyansi bul\n6. Standart sapmayi bul\n7. Diziyi ters cevir\n8. Eleman degistir\n9. Diziyi sifirla\n\n");
		scanf("%d", &islem);
oops=1;
		switch (islem) {
			case 0:
				bayrak = 0;
				printf("Cikisiniz yapiliyor...");
				sleep (5);
				return 0;
				break;
			case 1:
				printf("Dizideki elemanlar: ");
				yazdir(array, size);
				printf("\n");
				break;
			case 2:
				printf("Dizideki sayilarin ortalamasi: ");
				aver = ortalama(array, size);
				printf("%f\n", aver);
				break;
			case 3:
				mode=mod(array, size);
				if(mode < 1)
				printf("Mod yok.\n");
				else
				printf("Mod: %d\n", mode);
				break;
			case 4:
				median=medyan(array, size);
				printf("Medyan: %lf\n", median);
				break;
			case 5:
				printf("Varyans: ");
				variance=varyans(array, size);
				printf("%f\n", variance);
				break;
			case 6:
				printf("Standart sapma: ");
				stan=standart_sapma(array, size);
				printf("%f\n", stan);
				break;
			case 7:
				terscevir(array, size);
				printf("Dizi ters cevrildi.\n");
				break;
			case 8:
				printf("Hangi indis'teki elemani degistirmek istiyorsunuz?");				
				while(oops)
				{
				scanf("%d", &i);
				printf("\nLutfen yeni sayiyi giriniz: ");
				scanf("%d", &yeniSayi);
					if(i>=size) {
						printf("\nBelirtilen indiste eleman bulunmamaktadýr. Yeni bir indis giriniz: ");
						oops=1;
					}
					else
					{
					oops=0;
					}
					
				}

				degistir(array, size, i, yeniSayi);
				printf("Eleman degistirildi.\n");
				break;
			case 9:
				sifirla(array, size);
				printf("Dizi sifirlandi.\n");
				break;
			default:
				printf("Gecersiz istek\n");
				break;
		}
	}
}

double standart_sapma(int array[], int size) {
	double q, ss;
	q=varyans(array, size);
	ss=sqrt(q);
	return ss;
}

double varyans(int array[], int size) {
	int i, x;
	double vs=0.0, avera=ortalama(array, size);
	for(i=0; i<size; i++) {
		x=array[i];
		vs=vs+((avera-x)*(avera-x)/(size-1));
	}

	return vs;
}

double medyan(int array[], int size) {
	int i=0 , j=0 , temp=0;
	int barray[size];

		for(j=0 ; j<size ; j++) {
			barray[j] = array[j];
			}

	for(i=0 ; i<size ; i++) {
		for(j=0 ; j<size-1 ; j++) {
			if(barray[j]>barray[j+1]) {
				temp = barray[j];
				barray[j]=barray[j+1];
				barray[j+1]=temp;
			}
		}
	}

	double median=0;

	if(size%2 == 0)/*eleman sayýsý çift sayý iken*/
		median = (barray[size/2 - 1] + barray[size/2])/2.0;
	else/*eleman sayýsý tekken*/
		median = barray[(size-1)/2];

	return median;
}

void degistir (int array[], int size, int i, int yeniSayi)
{
	
	array[i]=yeniSayi;
}

int mod (int array[], int size) {
//dizinin her elemaný için sayaç olsun. bu deðerleri dizide tutalým.
//sayaç dizisi olsun ve büyüklüðü dizinin büyülüðüyle ayný olsun
//size kez diziyi inceleyelim ve sayaç artsýn þayet sayacýn temsi ettiði sayýnýn aynýsý dizide varsa
//en yüksek deðerli sayaç hangi deðere denk geliyorsa o deðer ekrana yazdýrýlsýn
int i, j, location;
int sayac[size];

for(i=0; i<size; i++){
	sayac[i]=-1;
	for(j=0; j<size-1 ; j++){
		if(array[i]==array[j])
		sayac[i]++;
	}
}
for(i=1;i<size;i++){
if(sayac[i]>sayac[location])
	location=i;
}
if(sayac[location] < 1)
	return -1;
else
	return array[location];

}

double ortalama(int array[], int size) {
	int b;
	double sum=0, average;
	for(b = 0; b < size; b++) {
		sum = sum + array[b];
	}
	average = sum / size;
	return average;
}

void fillArrayWithRandoms(int array[], int size, int min, int max) {
	int i;
	for (i = 0; i < size; i++) {
		array[i] = (rand() % (max - min)) + min;
	}
}

void sifirla(int array[], int size) {
	int a;
	for(a = 0; a < size; a++) {
		array[a]= 0;
	}
}

void yazdir(int array[], int size) {
	int i=0;
	while(i<size) {
		printf(" %d", array[i]);
		i++;
	}
	return;
}

void terscevir(int array[], int size) {
	int barray[size], g, f;
	for(g=size-1, f=0; g>=0; g--, f++)
		barray[f]=array[g]; /*we wanted to copy elements into barray starting from the end of array because we don't wanna get confused*/
	for(g=0; g<size; g++)
		array[g]=barray[g]; /*we want to update our original array otherwise coding or program will get really challenging*/
	return;
}
