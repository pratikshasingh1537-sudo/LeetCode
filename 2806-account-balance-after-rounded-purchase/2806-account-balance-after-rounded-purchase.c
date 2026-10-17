int accountBalanceAfterPurchase(int purchaseAmount) {
    
        purchaseAmount= ((purchaseAmount+5)/10)*10;
        int accBalanceAfterPurchase= 100- purchaseAmount;
        return accBalanceAfterPurchase;

}