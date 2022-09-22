#include <stdio.h>

void main() {
   int prime[MAX], i, j, num, divideornot, idx;

   scanf_s("%d", &num); //N까지의 범위에 있는 소수에서 N 입력

   prime[0] = 2; idx = 1; //prime? idx?

   for (i = 3; i <= num; i += 2) { // 
      divideornot = 1; j = 1;
      while ((j < idx) && (prime[j] <= sqrt(i)) && (divideornot == 1)) {
         if (i % prime[j] == 0) { divideornot = 0; break; }
         j++;
      }
      if (divideornot == 1) { prime[idx] = i; idx++; }
   }
   for (i = 0; i < idx; i++) printf("%d\n", prime[i]);
}

void main() {
    //  2부터 i-1까지의 모든 수 한 번이라도 나눠지면 반복 중단
    int i, j, n;
    scanf_s("%d", &n);
    for (i = 3; i <= n; i += 2) {
        j = 1
        while (())
    }

}

void main() {
   int prime[MAX], i, j, num, divideornot, idx;

   scanf_s("%d", &num); //N까지의 범위에 있는 소수에서 N 입력

   prime[0] = 3; idx = 1; //prime? idx?

   for (i = 3; i <= num; i += 2) { //
      divideornot = 1; j = 1;
      while (&& (divideornot == 1)) {
         if (i % prime[j] == 0) { divideornot = 0; break; }
         j++;
      }
      if (divideornot == 1) { prime[idx] = i; idx++; }
   }
   for (i = 0; i < idx; i++) printf("%d\n", prime[i]);
}