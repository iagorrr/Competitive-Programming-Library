/*
  https://www.youtube.com/watch?v=7e-7WYsd_tM
*/
#include <stdbool.h>
#include <stdio.h>
void solve(int n, int k, int *v) {

  pq_st *pq = pq_init(k+1);
  for(int i = 0 ; i < k; ++i) {
    pq_insert(pq, v[i]);
    pq->data[i] = v[i];
  }


  printf("%d", pq_top(pq));
  pq_change(pq, 0, 0);
  pq_pop(pq);
  



  int antiga = 1;
  int nova = k;
 
  while(true){

  }
}
