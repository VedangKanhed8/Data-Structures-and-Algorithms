/*
  Time Complexity :
    PreComputation = O(N * log(logN))
    Query = O(logN)
   Space Complexity = O(N)
*/

const int maxN = 5e5 + 7; 
vector<int> SPF(maxN);

// PreComputation
// SPF(i) stores lowest prime factor of i
void seive() {
    
    for(int i=1;i<maxN;i++) { 
        SPF[i] = i;
    }

    for(int i=2;i*i<=maxN;i++) {
        if(SPF[i] == i) {
            for(int j=i*i;j<maxN;j+=i) {
                if(SPF[j] == j) SPF[j]=i;
            }
        }
    }
}

// function to calculate prime factors
int countPrimeFactors(int num) {
    
    int total = 0;
    while(num != 1) {
        total++;
        num = num/SPF[num];
    }
    return total;
}
