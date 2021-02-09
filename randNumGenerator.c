#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fillArrayWithRandoms(int array[], int, int, int);
void printerr(int array[], int);
int main()
{
  srand(time(NULL)); //randomize the number generator

  int size, min, max, islem = 0, i, flag = 1;
  printf("Lutfen integer dizinizin kapasitesini giriniz: ");
  scanf("%d", &size);
  printf("Lutfen rastgele sayi araligini giriniz [a-b formatinda]: ");
  scanf("%d-%d", &min, &max);
  printf("Diziniz olusturulmustur.");
  int array[size];
  fillArrayWithRandoms(array, size, min, max);
 // printerr(int array[], int);
while(i<size)
{printf(" dizi:[%d]: %d",i, array[i]);
i++;
}
return 0;
}

//void printerr (int array[], int )

void fillArrayWithRandoms (int array[], int size, int min, int max)
{
	int i=0;
while(i<size)
{array[i]=((rand()%(max-min))+min);
i++;
}
	}
