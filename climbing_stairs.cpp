#include <iostream>
#include <vector>
#include <string>

int diff_ways(int n, std::vector<int>& ways);
int climbingStairs(int n);

int diff_ways(int n, std::vector<int>& ways) {
    if(n == 0) {
        return 1;           //return 1 if reached exactly number of steps
    } else if(n < 0) {
        return 0;           //returns 0 if exceeds number of steps
    } else {
        if(ways[n] == -1) {
            //stores number of diff ways to reach step if not already calculated
            ways[n] = diff_ways(n - 1, ways) + diff_ways(n - 2, ways);
            return ways[n];
        } else {
            //returns number of ways to reach step if already calculated
            return ways[n];
        }
    }
}

int climbingStairs(int n) {
    
    //initializing vector to store already calculated number of ways
    std::vector<int> ways(n + 1);
    for(int i = 0; i < n + 1; i++) {
        ways[i] = -1;
    }

    return diff_ways(n, ways); 
}

int main() {
    std::cout << climbingStairs(47) << std::endl;
}