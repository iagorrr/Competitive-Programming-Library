/*
  iagorrr ;)
    - 'trie' implementation that asign a value to a string, as example product name and price.
    - not so interesting if strings size are longer than 100.

    * let |s| be the size of the string.
    - methods: 
      insert O(|s|):
        - receives a string and asing a value to it, if that string already have a value,
        the previous value will be subscripted.
      get O(|s|):
        - get the value of a given string, if there is no string returns -1.
      delete O(|s|):
        - the given string will not be considered in the set anymore. 

      

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int N = 100;    // tamanho alfabeto
int M = 10;     // tamanho max str

typedef struct trie_node {
  int value;                // value asigned to the string.
  bool final;               // if is the end of some word
  struct trie_node **links; // the chars it can be linked.
} tn_st;

tn_st *trie_init() {
  tn_st *trie = (tn_st *)malloc(sizeof(tn_st));
  trie->value = -1;
  trie->final = false;
  trie->links = (tn_st**) calloc(sizeof(tn_st**), N);
  // trie->links = (tn_st **) malloc(sizeof(tn_st **) * N);
  return trie;
}

void trie_insert(tn_st *trie, char *str, int value) {
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL){
      cur->links[(int)str[i]] = trie_init();
      fprintf(stderr, "needed to alocate a new position for %c\n", str[i]);
    }
    cur = cur->links[(int)str[i]];

    fprintf(stderr, "trie at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      cur->final = true;
      cur->value = value;
      break;
    }

  }while (cur && str[i]);
}

int trie_get(tn_st *trie, char *str) {
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL)
      return -1;
    cur = cur->links[(int)str[i]];

    fprintf(stderr, "trie at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      if(cur->final) return cur->value;
      else return -1;
    }

  }while (cur && str[i]);
  return -1;
}

void trie_delete(tn_st *trie, char *str) {
  int i = 0;
  tn_st *cur = trie; 
  do {
    if (cur->links[(int)str[i]] == NULL)
      return;
    cur = cur->links[(int)str[i]];

    fprintf(stderr, "trie at char : %c, cur adress: %p\n", str[i], (void*)cur);
    i++;

    if (str[i] == '\0') {
      cur->final = false;
      cur->value = -1;
      return;
    }

  }while (cur && str[i]);
}
int main(void) {
  tn_st *trie = trie_init();
  char names[6][10] = {"iago", "iagoo", "iaga", "iagorrr", "bruno", "bcr"};
  int values[6] = {1, 2 ,3 , 4, 5 , 6};
  for(int i = 0; i < 6; ++i) {
    trie_insert(trie, names[i],  values[i]);
  }
  
  for(int i = 0; i < 6; ++i) {
    int value = trie_get(trie, names[i]);
    printf("value of %s is : %d\n", names[i], value); 
  }

  char invalidnames[6][10] = {"iag", "iagor", "bc", "iagorr", "bruna", "iagu"};
  for(int i = 0; i < 6; ++i) {
    int value = trie_get(trie, invalidnames[i]);
    printf("value of %s is : %d\n", invalidnames[i], value); 
  }

  
  trie_delete(trie, names[0]);
  for(int i = 0; i < 6; ++i) {
    int value = trie_get(trie, names[i]);
    printf("value of %s is : %d\n", names[i], value); 
  }
}
