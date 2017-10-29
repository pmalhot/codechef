//
//  main.cpp
//  MARBLES
//
//  Created by Prakhar Malhotra on 10/27/17.
//  Copyright © 2017 Prakhar Malhotra. All rights reserved.
//

#include <iostream>
#include <stdint.h>

//the product of any k consecutive integers is divisible by k!
//Can also use Pascal's triangle.
//https://stackoverflow.com/questions/11809502/which-is-better-way-to-calculate-ncr
uint64_t combination(int n,int r){
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;
    
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int test_cases;
    std::cin >> test_cases;
    int n,k;
    for(int i = 0; i<test_cases; i++){
        std::cin >> n >> k;
        if(n < k){
            std::cout << 0;
        }
        else if(n == k){
            std::cout << 1;
        }
        else{
            //Since we want 1 of each at least.
            n = n - k;
            
            //Now the problem becomes how many ways to count to n-k using k variables.
            //https://math.stackexchange.com/questions/47345/number-of-ways-of-distributing-n-identical-objects-among-r-groups
            //Not quite clear on this. Anyways ...
            std::cout << combination(n+k-1, k-1);
        }
        
        std::cout << std::endl;
    }
    return 0;
}
