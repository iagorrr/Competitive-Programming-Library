// iagorrr ;)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// macros.
#define maxword 80 + (int)6.66
struct translate{
    char jp[maxword];
    char pt[maxword];
};
// Compara duas strings pra saber qual é a maior.
int lesseq_str(char *a, char *b){
    int p = 0;

    while(a[p] != '\0' && b[p] != '\0'){
        if(b[p] - a[p] < 0) return 0; // a maior que b.
        else if(b[p]-a[p] > 0) return 1; // b maior que a.
        ++p;
    }

    // se ambas não diferem até aqui é porque são iguais.
    if(a[p] == '\0' && b[p] == '\0') return 2;

    // iguais até certo ponto porém b é maior.
    if(a[p] == '\0' && b[p] != '\0') return 1;
    else return 0;
}
typedef struct translate Item;
#define less(A, B) (lesseq_str(A.jp, B.jp) == 1 ? 1 : 0)
#define lesseq(A, B) (lesseq_str(A.jp, B.jp) != 0 ? 1 : 0)
#define exch(A, B) \
    {              \
        Item t;    \
        t = A;     \
        A = B;     \
        B = t;     \
    }
#define cmpexch(A, B)   \
    {                   \
        if (lesseq(B, A)) \
            exch(A, B); \
    }

// insertion sort.
void insertionsort(Item *v, int l, int r)
{
    for (int i = r-1; i > l; i--)
        cmpexch(v[i - 1], v[i]);

    for (int i = l + 1; i < r; i++)
    {
        int j = i;
        Item tmp = v[j];
        while (lesseq(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

void merge(Item *V, int l, int m, int r)
{
    Item *R = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (lesseq(V[i], V[j]))
            R[k++] = V[i++];
        else
            R[k++] = V[j++];
    }

    while (i <= m)
        R[k++] = V[i++];
    while (j <= r)
        R[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = R[k++];
    free(R);
}

void mergesort(Item *V, int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergesort(V, l, meio);
    mergesort(V, meio + 1, r);
    merge(V, l, meio, r);
}

int separa(Item *V, int l, int r)
{
    int i = l - 1, j = r;
    Item v = V[r];
    for (;;)
    {
        while (less(V[++i], v))
            ;
        while (less(v, V[--j]))
            if (j == l)
                break;
        if (i >= j)
            break;
        exch(V[i], V[j]);
    }
    exch(V[i], V[r]) return i;
}

int trapstop = 0;
int trapsize = 0;
static void quicksort(Item *V, int l, int r, int rec)
{
    if (r - l <= 32 || trapstop == 1)
        return;

    if (rec == 0)
    {
        trapstop = 1;
        return;
    }

    exch(V[(l + r) / 2], V[r - 1]);
    cmpexch(V[l], V[r - 1]);
    cmpexch(V[l], V[r]);
    cmpexch(V[r - 1], V[r]);

    int j = separa(V, l + 1, r - 1);
    quicksort(V, l, j - 1, rec - 1);
    quicksort(V, j + 1, r, rec - 1);
}

void sort_w(Item *V, int l, int r)
{
    // --r;
    // trapsize = 2 * ((int)log2((double)(r - l + 1)));
    // quicksort(V, l, r, trapsize);

    // if (trapstop == 1)
        mergesort(V, l, r);
    // else
        // insertionsort(V, l, r);
}
// busca binária pra verificar a existencia de um elemento.
int binary_search(Item *v, int l, int r, Item x){
    while(l + 1 < r){
        int mid = l + (r-l)/2;
        if(lesseq_str(v[mid].jp, x.jp)) l = mid;
        else r = mid-1;
    }

	if(lesseq_str(v[r].jp, x.jp) == 2) return r;
	return lesseq_str(v[l].jp, x.jp) == 2 ? l : -1;
}                                                                                                                                   

void translate_w(Item word, Item *v, int l , int r){
	int p = binary_search(v, l, r, word);	
	if(p == -1)
		printf("%s", word.jp);
	else
		printf("%s", v[p].pt);
}

int main()
{
    int t;
    char buff;
    scanf("%d", &t);
    scanf("%c", &buff);
    while (t--)
    {
        int n, m;
        scanf("%d", &n); 
        scanf("%c", &buff);
        scanf("%d", &m);
        scanf("%c", &buff);

		// fprintf(stderr, "n: %d m: %d\n", n , m);
        Item v[n];
        for(int i = 0; i < n; ++i){
            fgets(v[i].jp, maxword, stdin);
            v[i].jp[strlen(v[i].jp)-1] = '\0';
            fgets(v[i].pt, maxword, stdin);
            v[i].pt[strlen(v[i].pt)-1] = '\0';

            // printf("[%s,%s]\n", v[i].jp, v[i].pt);
        }

        sort_w(&v[0], 0, n-1);
		// printf("sorted\n");
        for(int i = 0; i < n; ++i){
            // printf("[%s,%s]\n", v[i].jp, v[i].pt);
        }

        for(int i = 0; i < m; ++i){
            char current_line[maxword];
            fgets(current_line, maxword, stdin);
			//printf("i: %d cline: [%s]\n", i, current_line);
			int j = -1;
			Item current_word;
			int cpos = 0;
			while(current_line[++j] != '\0'){
				if(current_line[j] == ' ' || current_line[j] == '\n'){
					current_word.jp[cpos] = '\0';

					// traduzir essa palavra e já exibir.
					translate_w(current_word, v, 0, n-1);
					
					printf("%c", current_line[j]);
					cpos = 0;
				}
				else current_word.jp[cpos++] = current_line[j];
			}

        }

        printf("\n");   

        
    }
    return 0;
}

// AC.