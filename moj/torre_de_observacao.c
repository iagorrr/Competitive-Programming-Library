// iagorrr & caua
#include <stdio.h>
#include <stdlib.h>
#define min(a,b) {a < b ? a : b}
#define max(a, b) {a > b ? a : b}
int ans;
char matrix[(int)1e2+1][(int)1e2+1];
int n, m;


typedef struct pair
{
    int first, second;
} pair;

/*
    for(x1 -- > x2)
        for(y1 --> y2)
*/
void spread(pair cord, int h)
{
    int x1 = max(0, cord.first-h);
    int x2 = min(n-1, cord.first+h);
    int y1 = max(0, cord.second-h);
    int y2 = min(m-1, cord.second+h);
    
    for(int i = x1; i <= x2; ++i)
    {
        for(int j = y1; j <= y2; ++j)
        {
            ans += matrix[i][j] == '#' ? 1 : 0;
            matrix[i][j] = (matrix[i][j] == 't' ? 't' : '.');
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    pair torre[(int)1e4]; int total_torres=0;

    for(int i = 0; i < n; ++i)
    {
        scanf("%s", matrix[i]);

        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 't')
            {
                pair temp; temp.first = i; temp.second = j;
                torre[total_torres++] = temp;
            }
        }
    }


    for(int i = 0; i < total_torres; ++i)
    {
        int h; scanf("%d", &h);
        spread(torre[i], h);
    }
    
    printf("%d\n", ans);
    for(int i = 0;  i < n; ++i) printf("%s\n", matrix[i]);

    return 0;
}
