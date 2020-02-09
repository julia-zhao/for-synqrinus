#include "q1_bonus.h"

#include <iostream>
#include <map>
#include <algorithm>

/** 
    Calculates the amount of change & which coins to use
    @param amount: the amount of money to make change for
    @param coins_used: stores the optimal combination of coins for every sum from 0 up to amount
    @param COIN_SET: stores the values of the coins in the set
    @return int for the number of coins it takes to create change
*/
unsigned int make_change(unsigned int &amount, unsigned int **coins_used, const std::array<unsigned int, 7> &COIN_SET, const unsigned int &COINS_LENGTH){
    /*  
        Initialize an array of size (amount+1}) - because it is indexed starting at at 0
        with impossible values - the maximum amount of coins you can use to make up (amount) value is (amount)*1 cent coins
    */
    unsigned int *num_coins = new unsigned int [amount+1];

    num_coins[0] = 0; // It takes 0 coins to create a sum of 0 cents
    for (unsigned int i=1; i<amount+1; i++){
        num_coins[i] = amount+1;
    }

    for (unsigned int i=1; i <= amount; i++){ // Loop through from 1 cents to (amount) cents
        for (unsigned int j=0; j < COINS_LENGTH; j++){ // Loop through all coins in the set
            if (COIN_SET[j] <= i){
                unsigned int min = std::min(num_coins[i], num_coins[i-COIN_SET[j]] + 1);
                // "Take" the coin
                num_coins[i] = min; // num_coins[i-j] is the min amount of coins used to create the sum (i-j)
                if (min == (num_coins[i-COIN_SET[j]] + 1)){ 
                    // Subtract the minimum amount of coins to replace COIN_SET[j]:
                    for (int k=0; k<COINS_LENGTH; k++){
                        coins_used[i][k] = coins_used[i-COIN_SET[j]][k];
                    }
                    coins_used[i][j]++;
                } //end of if
            }
        } //end of for loop through coins in set (j)
    } //end of for loop from a sum of 0 to a sum of amount (i)
    return num_coins[amount];
} //end of function

int main(){
    unsigned int amount = 0;
    unsigned int num_coins = amount+1;
    const unsigned int SET_SIZE = 7; //number of coins in set 
    const std::array<unsigned int, SET_SIZE> COIN_SET = {1, 5, 10, 25, 53, 100, 200};

    std::cin >> amount;

    // Array of size (amount+1) * SET_SIZE to hold the optimal combinmation of coins
    unsigned int **coins_used = new unsigned int *[amount+1];
    for (int i=0; i<amount+1; i++){
        coins_used[i] = new unsigned int[SET_SIZE];
    }

    for (int i=0; i<SET_SIZE; i++){
            coins_used[0][i] = 0;
    }

    num_coins = make_change(amount, coins_used, COIN_SET, SET_SIZE);

    std::cout << "Total number of coins used: " << num_coins << std::endl;  
    // Iterate through array
    for (unsigned int i=0; i<SET_SIZE; i++){
        std::cout << COIN_SET[i] << " cent value coins used: " << coins_used[amount][i] << std::endl;
    }

    return 0;
}