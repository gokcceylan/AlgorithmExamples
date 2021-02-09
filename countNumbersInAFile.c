#include <stdio.h>
void kabarcik(int array[], int n);

int main(){
	FILE*dosya=fopen("sayi.txt", "r");
	if(dosya==NULL) return 1;
	
	int n=0;
	while(1){
		int t;
		if(fscanf(dosya, "%d", &t)!=1)
		break;
		n++;
	}
	printf("Dosyada %d sayi tespit edildi", n);
	return 0;
}
