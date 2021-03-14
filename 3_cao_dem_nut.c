#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
}

int randoms()
{
	int max = 52, min = 1;
	int r = (rand()%(max - min)) + min;
	return r;
}

int tenbai(int i, int j){
	switch (i){
		case 0:{
			printf("At ");
			break;
		}
		case 1:{
			printf("2 ");
			break;
		}
		case 2:{
			printf("3 ");
			break;
		}
		case 3:{
			printf("4 ");
			break;
		}
		case 4:{
			printf("5 ");
			break;
		}
		case 5:{
			printf("6 ");
			break;
		}
		case 6:{
			printf("7 ");
			break;
		}
		case 7:{
			printf("8 ");
			break;
		}
		case 8:{
			printf("9 ");
			break;
		}
		case 9:{
			printf("10 ");
			break;
		}
		case 10:{
			printf("J ");
			break;
		}
		case 11:{
			printf("Q ");
			break;
		}
		case 12:{
			printf("K ");
			break;
		}
	}
	switch (j){
		case 0:{
			printf("Bich");
			break;
		}
		case 1:{
			printf("Chuon");
			break;
		}
		case 2:{
			printf("Ro");
			break;
		}
		case 3:{
			printf("Co");
			break;
		}
	}
	return 0;
}

int laybai(int inp, int bobai_c[13][4]){
	int t, u, o, so_nut = 0, check_tay = 0;
	for (o = 3*inp - 3; o <= 3*inp - 1; o++){
		for(t = 0; t < 13; t++){
			for(u = 0; u < 4; u++){
				if(bobai_c[t][u] == o){
					check_tay += t;
					if ((t > 0) && (t < 9)){
						so_nut += t;
					} else so_nut += 10;
					tenbai(t, u);
					break;
				}
			}
		}
	printf("\n");
	if (check_tay >=  30) so_nut = 99; 
	else 
	so_nut = so_nut % 10;
	}
	return so_nut;
}

int main()
{
	int bobai[13][4], check[52];
	int i, j, a, r_key;
	int so_nguoi_choi = 1, so_lan_xaobai;
	printf("Chao mung den voi game 3CAO\n");
	printf("made by LemmyC va Tun~ xDDDDD\n");
	printf("=============================\n");
	delay(2);
	system("cls");
	printf("Nhap so nguoi choi (2 - 17 nguoi): ");
	while (so_nguoi_choi > 17 || so_nguoi_choi < 2){
		scanf("%d",&so_nguoi_choi);
		if (so_nguoi_choi > 17 || so_nguoi_choi < 2) {
			printf("So nguoi choi khong chinh xac. Vui long nhap lai !!!\n");
			delay(1);
			system("cls");
			printf("Nhap so nguoi choi (2 - 17 nguoi): ");
		} else break;
	}
	system("cls");
	printf("Ban muon xao bai bao nhieu lan (toi da 10 lan, khong xao bai nhap 0): ");
	while (so_lan_xaobai < -1 || so_lan_xaobai > 10){
		scanf("%d",&so_lan_xaobai);
		if (so_lan_xaobai < -1 ||so_lan_xaobai > 10) {
			printf("So lan xao bai khong chinh xac. Vui long nhap lai\n");
			delay(1);
			system("cls");
			printf("Ban muon xao bai bao nhieu lan (toi da 10 lan, khong xao bai nhap 0): ");
		} else break;
	}
	system("cls");
	while (r_key != 0){
		printf("BAT DAU (CHOI LAI) (1 = YES; 0 = NO): ");
		while (r_key <0 || r_key > 1){
					scanf("%d",&r_key);
					if (r_key <0 || r_key > 1) {
						printf("Vui long nhap chinh xac 1 hoac 0\n");
						delay(1);
						system("cls");
						printf("BAT DAU (CHOI LAI) (1 = YES; 0 = NO): ");
					} else break;
		}
		system("cls");
		if (r_key == 0) break;
		srand((unsigned)time(NULL));
		for (i = 0; i < 52; i++)
			check[i] = i;
		for (a = 0; a <= so_lan_xaobai; a++){
			for (i = 0; i < 52; i++){
				j = randoms();
				int temp = check[i]; 
    			check[i] = check[j]; 
    			check[j] = temp; 
			}
		}
		a = 0;
		for (i = 0; i < 13; i++)
			for (j = 0; j < 4; j++)
			{
				bobai[i][j] = check[a];
				a++;
			}
		for (a = 1; a <= so_nguoi_choi; a++){
			int nut;
			printf("Nguoi choi %d\n", a);
			printf("==============\n");
			nut = laybai(a, bobai);
			if (nut == 99) printf("Ban duoc Ba Cao\n");
				else if (nut == 0) printf("CHO TUN OC CAC\n");
				else printf("Ban duoc %d Nut\n", nut);
			printf("\n");
			printf("\n");
			
		}
		r_key = -1;
	}
	system("cls");
	printf("CAM ON VI DA TRAI NGHIEM, TUN IU PAN <3 <3 <3");
	delay(3);
	return 0;
}
