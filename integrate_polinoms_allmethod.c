//Entegrate function program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define func(x) (x*x+5)//we can change function here
#define n 2//division part number higher number will be closer main answer

double rectangle(double from, double to)
{
   double h,i;
   double sum=0.0;
   h=(to-from)/n;
   
   for(i=from;i<to;i+=h){
   	    sum+=func(i)*((i+h)-i);
   }
   
   return sum;
}
 
double midpoint(double from, double to)
{
   double h,i;
   double sum=0.0;
   h=(to-from)/n;
   for(i=from;i<to;i+=h){
   	    sum+=func(((i+h)+i)/2)*((i+h)-i);
   }
   
   return sum;
}
 
double trapezoid(double from, double to)
{
   double h,i;
   double sum=0.0;
   h=(to-from)/n;
   for(i=from;i<to;i+=h){
   	    sum+=((func(i)*((i+h)-i))/2)+((func(i+h)*((i+h)-i))/2);

   }
   return sum;
}
 
double simpson(double from, double to)
{
   double h,i;
   double sum=0.0;
   h=(to-from)/n;
   for(i=from;i<to;i+=h){
   	    sum+=(((i+h)-i)/6)*(func(i)+4*(func(((i+h)+i)/2))+func(i+h));
   }
   
   return sum;
}


int main(int argc, char *argv[]) {
	int from,to,islemparam,i;
	int islemci[10];
	if(argc==1)
	return 0;
	
	for(i=1;i<3;i++){
		islemci[i]=atoi(argv[i]);
	}
	from=islemci[1];
	to=islemci[2];
	
	
	if(strcmp(argv[3], "rectangle") == 0)
	{
		islemparam = 0;
	}
	
	else if (strcmp(argv[3], "midpoint") == 0)
	{
		islemparam = 1;
	}
	
	else if (strcmp(argv[3], "trapezoid") == 0)
	{
		islemparam = 2;
	}
	
	else if (strcmp(argv[3], "simpson") == 0)
	{
		islemparam = 3;
	}
	
	else {
		printf("Girdiginiz isimde bir fonksiyon yoktur.\n");
	return 0;
	}
	


	switch(islemparam){
		case 0:
			printf("Entegrate=%.3f",rectangle(from,to));
		break;
		
		case 1:
			printf("Entegrate=%.3f",midpoint(from,to));
		break;	
		
		case 2:
			printf("Entegrate=%.3f",trapezoid(from,to));
		break;
		
		case 3:
			printf("Entegrate=%.3f",simpson(from,to));
		break;
	}
	
	return 0;
}
/*double func(int polinom){
	int kat[10];
	int us[10];
	for(i=0;i<'/0';i++){
		if(strcmp((polinom+i),"x")){
			kat[i]=(polinom+(i-1));
		}
		if(strcmp((polinom+i),"^")){
			us[i]=(polinom+(i+1));
		}
		
	}
	return func(x);
}*/
