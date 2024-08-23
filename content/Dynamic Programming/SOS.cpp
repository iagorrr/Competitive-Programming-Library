const int LOG = 17;
int dp[(1<< LOG)];
for(int b = 0; b < LOG; b++){
    for(int mask = 0; mask < (1<< LOG); mask++){
        if(mask & (1<< b)){
            dp[mask] |= dp[mask ^ (1LL << b)];
        }
    }
}
