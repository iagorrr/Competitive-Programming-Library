// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

int main(){
	int t, n;
	while(scanf("%d %d", &t, &n)){
		if(t == 0) break;

		char* time =  malloc(sizeof(char)*20);
		int p;
		int ans = 0;
		scanf("%d", &p);
		while(t--){
			scanf("%s %d", time, &p);
			ans += p;
		}
		printf("%d\n", 3*n - ans);
	}

	return 0;
}


