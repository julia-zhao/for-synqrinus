# for-synqrinus
Read me for the reasoning behind the solutions!

EXERCISE #1:
For the coin system listed in the system (where each coin's value is at least twice the value of the smallest coin closest in value to it), a "greedy" algorithm that selects the largest possible coin within the bounds of the amount left will always provide the optimal solution. 

653 - 8 coins used. 3x200 cents, 2x25 cents, 3x1 cent.
63 - 6 coins used. 2x25 cents, 1x10 cents, 3x1 cent.
132 - 5 coins used. 1x100 cents, 1x25 cents, 1x5 cents, 2x1 cent.

EXERCISE #1, BONUS:
With the addition of the 53 cent coin, the greedy algorithm from above no longer guarantees the optimal solution. For example, the greedy algorithm will take three coins for 106 cents (1 dollar, 5 cents, 1 cent) while the optimal solution is two coins (2x53 cents).
Thus, we now have to check every possible solution to determine the minimum number of coins. 

653 - 4 coins used. 3x200 cents, 1x53 cents.
63 - 2 coins used. 1x53 cents, 1x10 cents.
132 - 4 coins used. 2x53 cents, 1x25 cents, 1x1 cent.

EXERCISE #2:
I have decided to implement a DFS tree with more than 2 possible children per node. 

----------------------
brainstorm for algorithm (?), refactoring later maybe. didn't work the first time around because there's too many conditions to consider.

   if (COIN_SET[j] == 1){
                        coins_used[0]++;
                    }
                    else if (COIN_SET[j] == 5){ // 5 cents = 5x1 cent
                        if (i%5==0){
                            coins_used[0]-=5;
                            coins_used[1]++;
                        }
                    }
                    else if (COIN_SET[j] == 10){ // 10 cents = 2x5 cents
                        if (i%5==0 || i%10==0){
                            if (coins_used[1] >= 2 ){
                                coins_used[1] -=2;
                                coins_used[2]++;
                            }
                        }
                    }
                    else if (COIN_SET[j] == 25){ // 25 cents = 2x10 cents + 1x5 cents
                        if (i%25==0){
                            coins_used[1]--;
                            coins_used[2]-=2;
                            coins_used[3]++;
                        }
                    }
                    else if (COIN_SET[j] == 53){ // 53 cents = 2x25 cents + 3x1 cents
                        if (i%53==0){
                            coins_used[0]-=3;
                            coins_used[3]-=2;
                            coins_used[4]++;
                        }
                    }
                    else if (COIN_SET[j] == 100){ // 100 cents = 1x53 cents + 1x25 cents + 2x10 cents + 1x1 cent
                            coins_used[0]--;
                            coins_used[2]-=2;
                            coins_used[3]--;
                            coins_used[4]--;
                            coins_used[5]++;
                        }
                    }
                    else{ // 200 cents = 2x100 cents
                        if (i%200==0){
                            coins_used[5]-=2;
                            coins_used[6]++;
                        }
                    }