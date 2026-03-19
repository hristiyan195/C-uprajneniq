#include <stdio.h>
#include <limits.h>
#include <math.h>

short po_golqmo_chislo(short a,short b){
   short result,maximum;
   maximum=a;
   if(b>a){
      maximum=b;
   }
   result=maximum;
   return result;
}
short po_malko_chislo(short a, short b){
   short result,minimum;
   minimum=a;
   if(b<a){
      minimum=b;
   }
   result=minimum;
   return result;
}
void task1(){
   short num,num1,maximum,minimum;
   maximum=-SHRT_MAX;
   minimum=SHRT_MAX;
   do
   {
      for (;;)
      {
        printf("Vuvedete dve chisla");
         scanf("%hd %hd",&num,&num1);
         if (num==0||num1==0){
            break;
         }
         if(po_golqmo_chislo(num,num1)>maximum){
            maximum=po_golqmo_chislo(num,num1);
         }
         if(po_golqmo_chislo(num,num1)<minimum){
            minimum=po_malko_chislo(num,num1);
         }
   }
   printf("Maximum: %hd Minimum:%hd",maximum,minimum);
      }
   
    while (num!=0 && num1!=0);
   
}
void task2(){
   printf("Vuvedete chasove i minuti");
   short hours,minutes;
   scanf("%hd %hd",&hours,&minutes);
   minutes+=15;
   if (minutes>60){
      hours+=1;
      minutes-=60;
   }
   if (hours>23){
    hours-=24;
   }
   if (minutes<10){
      printf("%hd:0%hd",hours,minutes);
   }
   else{printf("%hd:%hd",hours,minutes);}
}
void task3(){
   printf("Vuvedete dve chisla");
   short num1,num2,num3;
   scanf("%hd %hd %hd",&num1,&num2,&num3);
   if (num1==num2 &&num1==num3){
      printf("Yes");
   }
   else{printf("NO");}
}
void task4(){
   printf("vuvedete broi tochki");
   short number;
   float points=0.0,total_points=0.0;
   scanf("%hd",&number);
   if (number<=100){
      points+=5;
   }
   else if(number>1000){
      points+=0.1*number;
   }
   else {
      points+=0.2*number;
   }
   if (number%2==0)
   {
      points+=1;
   }
   else if(number%10==5){
      points+=2;
   }
   total_points=number+points;
   printf("%f\n",points);
   printf("%f\n",total_points); 
}
void task5(){
   printf("Vuvedete sekundi");
   short seconds1,seconds2,seconds3,total_seconds=0,minutes=0,leftover;
   scanf("%hd %hd %hd",&seconds1,&seconds2,&seconds3);
   total_seconds+=seconds1+seconds2+seconds3;
   minutes=total_seconds/60;
   leftover=total_seconds%60;
   printf("%hd:%02hd",minutes,leftover);
}
void task6(){
   printf("Vuvedete 6 koordinati");
   float x1, y1, x2, y2, x, y;
    scanf("%f", &x1);
    scanf("%f", &y1);
    scanf("%f", &x2);
    scanf("%f", &y2);
    scanf("%f", &x);
    scanf("%f", &y);
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Inside\n");
    } else {
        printf("Outside\n");
    }
}
void task7(){
   printf("Vuvedete razstoqnie v km i period ot denq-D(za den) ili N(za nosht)");
   short km,price=0;
   char timeofday;
   scanf("%hd",&km);
   scanf(" %c",&timeofday);
   if (km>=20&&km<100){
      price=0.09*km;
      printf("Best transport is Bus\n");
   }
   else if(km>=100){
      price=0.06*km;
      printf("Best transport is Train\n");
   }
   else
   {
      if (timeofday=='N')
      {
         price=0.7+(0.9*km);
      }
      else{
         price=0.7+(0.79*km);
      }
      printf("Best transport is taxi\n");
   }
   printf("%hd\n",price);

}
void task8(){
int v,p1,p2;double h;
scanf("%d%d%d%lf",&v,&p1,&p2,&h);
double w1=p1*h,w2=p2*h,w=w1+w2;
if(w<=v)printf("The pool is %d%% full. Pipe 1: %d%%. Pipe 2: %d%%.\n",(int)(w/v*100),(int)(w1/w*100),(int)(w2/w*100));
else printf("For %.2f hours the pool overflows with %.2f liters.\n",h,w-v);
}

void task9(){
int x,z,w;double y;
scanf("%d%lf%d%d",&x,&y,&z,&w);
double wine=(x*y*0.4)/2.5;
if(wine>=z)printf("Good harvest this year! Total wine: %.0f liters.\n%.0f liters left -> %.0f liters per person.\n",floor(wine),ceil(wine-z),ceil((wine-z)/w));
else printf("It will be a tough winter! More %.0f liters wine needed.\n",floor(z-wine));
}

void task10(){
int n,m;
double c1=0,c2=0,c3=0,c4=0,c5=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&m);
if(m<200)c1++;else if(m<400)c2++;else if(m<600)c3++;else if(m<800)c4++;else c5++;}
printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n",c1/n*100,c2/n*100,c3/n*100,c4/n*100,c5/n*100);
}

void task11(){
printf("Vuvedete duljina");
int n;scanf("%d",&n);
int mid=2*n-2*(n/2)-4;
printf("/");for(int i=0;i<n/2;i++)printf("^");printf("\\");
for(int i=0;i<mid;i++)printf("_");
printf("/");for(int i=0;i<n/2;i++)printf("^");printf("\\\n");
for(int i=1;i<n-2;i++){
printf("|");for(int j=0;j<2*n-2;j++)printf(" ");printf("|\n");}
printf("|");for(int i=0;i<n/2+1;i++)printf(" ");
for(int i=0;i<mid;i++)printf("_");
for(int i=0;i<n/2+1;i++)printf(" ");printf("|\n");
printf("\\");for(int i=0;i<n/2;i++)printf("_");printf("/");
for(int i=0;i<mid;i++)printf(" ");
printf("\\");for(int i=0;i<n/2;i++)printf("_");printf("/\n");
}

void task12(){
printf("Vuvedete duljina");
int n;scanf("%d",&n);
for(int i=0;i<n-2;i++){
for(int j=0;j<n-1;j++)printf(i%2==0?"*":"-");printf("\\ /");
for(int j=0;j<n-1;j++)printf(i%2==0?"*":"-");printf("\n");}
for(int i=0;i<n-1;i++)printf(" ");printf("@\n");
for(int i=0;i<n-2;i++){
for(int j=0;j<n-1;j++)printf(i%2==0?"*":"-");printf("/ \\");
for(int j=0;j<n-1;j++)printf(i%2==0?"*":"-");printf("\n");}
}
int main(){
   int choice;
   do{
      printf("izberete zadacha ot 1-12");
      scanf("%d", &choice); 
      switch(choice){       
      case 1:task1();break;
      case 2:task2();break;
      case 3:task3();break; 
      case 4:task4();break;
      case 5:task5();break;
      case 6:task6();break;
      case 7:task7();break;
      case 8:task8();break; 
      case 9:task9();break;
      case 10:task10();break;
      case 11:task11();break;
      case 12:task12();break;
      }
   }
   while(choice!=0);
   
   return 0;
}