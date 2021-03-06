#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct komponen{
	char jenis;
	float value;
	char kiri[2];
	char kanan[2];
	} komponen;

int main()
{	//DEKLARASI VARIABEL
	FILE *fptr;
	char* fname = (char*)malloc(sizeof(char));
	char data[50];
	komponen resistor[6] = (komponen*)malloc(sizeof(komponen));
	komponen kapasitor[6] = (komponen*)malloc(sizeof(komponen));
	komponen temp = (komponen*)malloc(sizeof(komponen));
	int inc_r = 0;
	int inc_c = 0;
	int inc1 = 0;
	int inc2 = 0;
	
	//INPUT FILE
	printf("Masukkan nama file external : ");
	gets(fname);
	fptr = fopen(fname, "r");
	if (fptr == NULL)
		printf("Belum ada rangkaian yang diinput");
	else
	{	//BACA FILE
		while(!feof(fptr))
		{	fgets(data, sizeof(data), fptr);
			//DIBAWAH INI AKAN DIIMPLEMETASIKAN FUNGSI UNTUK MEMECAH "data" menjadi perbagian
		 	temp = pecah(data);
		 	if(temp.jenis == 'R')
			{
				resistor[inc_r] = temp;
				++inc_r;
			}
		 	else
			{
				kapasitor[inc_k] = temp;
				++inc_k;
			}
		}
		//SAMPAI DISINI SEMUA RESISTOR DAN KAPASITOR SUDAH MASUK ARRAY
		resistor[5].char = 'R';
		resistor[5].value = 0;
		strcpy(resistor[5].kiri, "xx");
		strcpy(resistor[5].kanan, "xx");
		
		kapasitor[5].char = 'C';
		kapasitor[5].value = 0;
		strcpy(kapasitor[5].kiri, "xx");
		strcpy(kapasitor[5].kanan, "xx");
		
		//mencari R ekivalen
		for (inc1 = 0; inc1<6; ++inc1)
		{
			for(inc2 = 6; inc2>6-inc1; --inc2)
			{
				if (strcmp(resistor[inc1].kiri, resistor[inc2].kiri) == 0 && strcmp(resistor[inc1].kanan, resistor[inc2].kanan)==0) //paralel
				{
					
					}
			}
		}
	}
  return 0;
}

komponen pecah(char* data)
{	char delimiter = ' ';
	int i = 0;
 	int j = 0;
 	char* temp = (char*)malloc(sizeof(char));
 	struct komponen *out;
 	
 	while(data[i]!=NULL)
	{	while(data[i] != delimiter)
		{	temp[i] = data[i];
			++i; }\
		temp[i+1] = '\0';
	 	i = 0;
	 	if (j == 0)	out->jenis = temp[0];
	 	else if (j == 1)	out->value = atoi(temp);
	 	else if (j == 2)	out->kiri = temp;
	 	else	out->kanan = data;
		++j;
	}
}
