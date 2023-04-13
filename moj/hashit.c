// iagorrr ;)

/*
  Pra esse exercício ele checa a primeira posição e o hash
  para resolver colisão só começa a incrementar o J depois
  da verificação do primeiro.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int k = 19;
const int mod =101;
const int strmax = 30;
typedef char* Item;
typedef struct ht {
  Item *ht;
} ht;

typedef struct pair{
  int fst;
  Item s;
} pair;


int hash_str(Item s) {
  int i = 0;
  int h = 0;
  while(s[i] != '\0'){
    h = (h + s[i]*(i+1));
    ++i;
  }
  h = (h*k)%mod;
  return h;
}
void ht_init(ht *ht, int n){
  ht->ht = (Item*) calloc(n, sizeof(Item));
  for(int i = 0; i < n; ++i) {
    ht->ht[i] = (char*) calloc(strmax, sizeof(char));
    ht->ht[i][0] = '\0';
  }
}

int hash_open(int key_hash, int j) {
  int ans = ((key_hash + j*j + (23*j))%mod);
  return ans; 
}

void ht_insert(ht *ht, Item x) {
  /*
    prove that isn't in the list,
    and find the first valid posi
    tion to inset.
  */
  int h = hash_str(x);
  if(ht->ht[h][0] == '\0'){
  // insert.
    int i = 0;
    while(x[i] != '\0') {
      
      ht->ht[h][i] = x[i]; 
      i++;
    }
    ht->ht[h][i] = '\0';
    return;
  }


  if(strcmp(x, ht->ht[h]) == 0) return;

  int first_free = -1;
  int  curpos = h;
  int j = 1;
  while(j < 20) {
    curpos = hash_open(h, j);
    if(first_free < 0 && ht->ht[curpos][0] == '\0') {
      first_free = curpos;
    }
    if(strcmp(x, ht->ht[curpos]) == 0)  {
      return;
    }
    j++;
  }

  if(first_free == -1) return;

  // insert.
  int i = 0;
  while(x[i] != '\0') {
    
    ht->ht[first_free][i] = x[i]; 
    i++;
  }
  ht->ht[first_free][i] = '\0';
}

void ht_delete(ht *ht, Item x) {
  /*
    remove a given key from the ht,
    in the context of strings mark
    the first as NULL.
  */
  int j = 1;
  int h = hash_str(x);
  if(strcmp(x, ht->ht[h]) == 0) {
    ht->ht[h][0] = '\0';
    return;
  }

  int  curpos = h;
  while(j < 20) {
    curpos = hash_open(h, j);
    if(strcmp(x, ht->ht[curpos]) == 0)  {
      ht->ht[curpos][0] = '\0';
      return;
    }
    j++;
  }
}


void run() {
  int n; scanf("%d", &n); 

  ht ht; ht_init(&ht, mod);
  while(n--) {
    char *s = (char*) malloc(sizeof(char)*30);
    scanf("%s", s);

    if(s[0] == 'A')
      ht_insert(&ht, s+4);
    else 
      ht_delete(&ht, s+4) ;
  }
  
  int cnt = 0;
  for(int i = 0; i < mod; ++i) {
    if(ht.ht[i][0] != '\0') {
      ++cnt;
    }
  }

  printf("%d\n", cnt);
  for(int i = 0; i < mod; ++i) {
    if(ht.ht[i][0] != '\0') {
      printf("%d:%s\n", i, ht.ht[i]);
    }
  }
}
int main(void) {
  int t; scanf("%d", &t);

  while(t--) {
    run();
  }
}

// AC, hash open adress
