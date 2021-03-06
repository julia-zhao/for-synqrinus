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
I have decided to implement a tree with more than 2 possible children per node. Since the question assumes that all inputs are given in order, I can simply insert the children into a  list and not worry about sorting when inserting nodes. When outputting, I added one │ (U+2502) for every child node in the list (if there were more than one). Otherwise, I added a space. Finally, I added one └ (U+2514) if the node was a child of another node. 

EXERCISE #2, BONUS:
This was done in the same method as question 2, but I checked to see if the node was the rightmost node as well. If it was not, I outputted a ├ (U+251C) in place of the └ (U+2514).
