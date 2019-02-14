#include<stdio.h>
int maxProfit(int price[], int n, int k){
	int i,j,m;

    int profit[k + 1][n + 1];

    for (i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    for (j = 0; j <= n; j++)
        profit[0][j] = 0;
 	
	int init_min;
		
    for (i = 1; i <= k; i++){
        for (j = 1; j < n; j++){
            int max_so_far = init_min;
            
            for (m = 0; m < j; m++){
				max_so_far = max(max_so_far, price[j] - price[m] + profit[i - 1][m]);
			}
 
            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }
 
    return profit[k][n - 1];
}
int main(){
	
    int k=3;
    int price[] = {12,14,17,10,14,12,15};
    int n = sizeof(price) / sizeof(price[0]);
 
    printf("Maximum profit is:");
    maxProfit(price, n, k);
 
    return 0;
}
