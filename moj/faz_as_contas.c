int faz_conta_direito(int parcelas, char op){
    int ans = 0;
    int p;
    scanf("%d", &p);
    ans = p;
    for(int i = 1; i < parcelas; ++i){
        scanf("%d", &p);
        ans += op == '+' ? p : -p;
    }
    return ans;
}

// AC.