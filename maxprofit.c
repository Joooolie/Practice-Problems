

int maxProfit(int* prices, int pricesSize){
    int i = 0, prev = 0, curr = 0;
    //1 = buy, 0 = sell
    int buy = 1, last_bought = 0, profit = 0;
    for (i=1; i<pricesSize;i++){
        prev = prices[i-1];
        curr = prices[i];
        printf("prev = %d, curr = %d\n", prev, curr);
        
        if (prev < curr) {
            if (buy) {
                printf("We're buying\n");
                last_bought = prev;
                buy = 0;
            }
            
        } if (prev > curr) {
            if (!buy) {
                printf("We're selling\n");
                profit += (prev - last_bought);
                buy = 1;
            }
        }
    }
    
    if (!buy) {
        printf("We need to sell! \n");
        //last_bought = prices[pricesSize-1];
        profit += (prices[pricesSize-1] - last_bought);
    }
    return profit;
}