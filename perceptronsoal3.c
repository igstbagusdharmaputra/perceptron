#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int aktifasi (float net)
{
	if(net>0.2){
		return 1;
	}else if (net < -0.2 ){
		return -1;
	}
	else if (net >=-0.2 && net <= 0.2){
		return 0;
	}
}
int main()
{
	int data[4][2],i,j,Ya[4],Yd[4],error,epoch;
	float net,lr,w[4][2],wb[4][2],b,db,th;
	float biaslama,biaslamadb;
	int baris = 0;
	printf  ("Data Training Pada Perceptron\n");
	
	printf ("masukan input - \n");
	for (i = 0 ; i<4 ;i++){
		for (j = 0; j< 2 ;j++)
		{
			scanf ("%d",&data[i][j]);
		}
	}
	printf ("Masukan bobot masing-masing input - \n");
	for (i = 0; i < 2; i++){
		scanf ("%f",&w[baris][i]);
	}
	printf ("Masukan desired output - \n");
	for (i = 0; i < 4; i++){
		scanf ("%d",&Yd[i]);	
	}
	//0<lr<1
	printf ("Masukan Learning Rate - \n");fflush(stdin);
	scanf ("%f",&lr);
	printf ("Masukan Threshold - \n");fflush(stdin);
	scanf ("%f",&th);
	printf ("Masukan bias : ");
	scanf ("%d",&b);
	printf ("\n\n");
	float x,y,tempbias;
	error = 0; 
	epoch = 0; 
	net = 0; 
	int k =0;
	int actual;
	do{
		printf ("Epoch ke-%d\n",epoch+1);
	
		for (k = 0 ; k < 4 ; k++){
			biaslama = b;
			for (i = 0 ; i < 2 ; i ++ )
			{
				net = net + (w[baris][i] * data[baris][i]);
			}	
			net =  net - biaslama;
			actual = aktifasi(net);
			Ya[baris] = actual;
			error = Yd[baris] - actual;
			b = lr * error;
			for ( i = 0 ; i < 2 ; i++){
				wb[baris][i] = w[baris][i] + (data[baris][i] * b);
			}
			printf ("W1 = %.2f\n",w[baris][0]);
			printf ("W2 = %.2f\n",w[baris][1]);
			printf ("Bias = %.2f\n",biaslama);
			printf ("Net = %.2f\n",net);
			printf ("Aktual Output = %d\n",Ya[baris]);
			printf ("Error = %d\n",error);
			printf ("W1Baru = %.2f\n",wb[baris][0]);
			printf ("W2Baru = %.2f\n",wb[baris][1]);
			printf ("\n");
			baris++;
			w[baris][0] = wb[baris-1][0];
			w[baris][1] = wb[baris-1][1];
			b = b + biaslama;
			net = 0;
		}
		x = wb[3][0];
		y = wb[3][1];
		baris=0;
		w[baris][0] = x;
		w[baris][1] = y;
		
		epoch++;
	}while(Ya[0]!=Yd[0] || Ya[1]!=Yd[1] || Ya[2]!=Yd[2] || Ya[3]!=Yd[3] );
	
	return 0;
}
