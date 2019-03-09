# include<stdio.h>
 void knapsack(int n, float weight[], float profit[],float capacity) {
   float x[10], sum=0.0;
   int i,j,M;
   M=capacity;
   for (i=0; i<n; i++)
      x[i]=0.0;
   for (i=0; i<n; i++) {
      if (weight[i]>M)
         break;
      else
	  {
         x[i]=1.0;
         sum=sum+profit[i];
         M=M-weight[i];
      }
   }
   if(i<n)
   x[i]=M/weight[i];
   sum+=(x[i]*profit[i]);
   printf("\nThe result is:- ");
   for (i=0;i<n;i++)
   printf("%f\t",x[i]);
   printf("\nMaximum profit is:- %f",sum);
}
int main() {
   float weight[10], profit[10], capacity;
   int num, i, j;
   float ratio[10], temp;
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
    printf("\nEnter the wts");
   for (i=0; i<num; i++) {
      scanf("%f",&weight[i]);
   }
    printf("\nEnter the profit");
   for (i = 0; i < num; i++) {
      scanf("%f",&profit[i]);
   }
   printf("Enter the capacity of knapsack");
   scanf("%f",&capacity);
   for (i=0; i<num; i++) 
   {
      ratio[i] = profit[i] / weight[i];
   }
    for (i=0;i<num;i++)
	 {
      for (j=i+1;j<num;j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num, weight, profit, capacity);
}
