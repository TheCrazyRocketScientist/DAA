#include <stdio.h>
#include<stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))


int main(){
  int m,n,t,r;
  printf("Enter m : \n");
  scanf("%d",&m);
  printf("Enter n: \n");
  scanf("%d",&n);
  t = min(m,n);
  while(t>0){
    if(m%t == 0 && n%t == 0){
        printf("GCD of %d and %d is %d",m,n,t);
        break;
      }
      t--;
  }
  
  return 0;
}