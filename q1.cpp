// QUESTION 1

#include "q1.h"

#include <iostream>
#include <map>

/** 
    Calculates the amount of change & which coins to use
    @param amount: the amount of money to make change for
    @param num_coins: the number of coins that is required 
    @param coins_used: stores the amount of every coin that is used
    @return void as all values are passed by reference
*/
void make_change(unsigned int &amount, unsigned int &num_coins, std::map <unsigned int, unsigned int> &coins_used){
    while (amount > 0){
        if (amount >= 200){
            amount -= 200;
            coins_used[200]+=1;
        }
        else if (amount >= 100){
            amount -= 100;
            coins_used[100]+=1;
        }
        else if (amount >= 25){
            amount -= 25;
            coins_used[25]+=1;
        }
        else if (amount >= 10){
            amount -= 10;
            coins_used[10]+=1;
        }
        else if (amount >= 5){
            amount -= 5;
            coins_used[5]+=1;
        }
        else{
            amount -= 1;
            coins_used[1]+=1;
        }
        num_coins++;
    }
}

// Assuming valid input only
int main(){
    unsigned int amount = 0;
    unsigned int num_coins = 0;

    std::map <unsigned int, unsigned int> coins_used = {
        { 1, 0 },
        { 5, 0 },
        { 10, 0 },
        { 25, 0 },
        { 100, 0 },
        { 200, 0}
    };
    
    std::cin >> amount;
    make_change(amount, num_coins, coins_used);

    std::cout << "Total number of coins used: " << num_coins << std::endl;

    std::map<unsigned int, unsigned int>::iterator i = coins_used.begin();

    // Iterate through map for output
    while(i != coins_used.end()){
        std::cout << i->first << " cent value coins used: " << i->second << std::endl;
        i++;
    }

    return 0;
}