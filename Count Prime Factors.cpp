/*
    Time Complexity = O(sqrt(N))
    Space Complexity = O(1)
*/ 

// function to calculate count of prime factors
int countPrimeFactors(int num) {

    int totalCnt = 0;
    while(num % 2 == 0) {
        totalCnt++;
        num >>= 1LL;
    }

    for(int i = 3 ; i*i <= num ; i += 2) {
        while(num % i == 0) {
            totalCnt++;
            num /= i;
        }
    }

    if(num>2) totalCnt++;
    return totalCnt;
}
