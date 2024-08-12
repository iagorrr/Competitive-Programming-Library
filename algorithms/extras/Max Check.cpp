/*{=========================~ BEGIN MAX CHECK ~==========================*/

/*
	Returns the maximum value in range [l, r] that satisfies the
	lambda function check, if there is no such value the minimal 
	possible value for that type will be returned.
 */

template<typename T>
T maxCheck(T l, T r, function<bool(T)> check) {
        T best = numeric_limits<T>::min();
        while(l<=r){
                T m=midpoint(l,r);
                if(check(m))chmax(best,m),l=m+1;
                else r=m-1;
        }
        return best;
}

/*===========================~ END MAX CHECK ~==========================}*/
