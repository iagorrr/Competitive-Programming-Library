struct Mex {
	int mx_sz; vector<int> hs; set<int> st;

	// _mx_sz is the maximum total of elements our structure may have ~ O(mx_sz)
	Mex(int _mx_sz) :
		mx_sz(_mx_sz),
	       	hs(mx_sz+1)
	{

		auto it = st.begin();
		for (int i = 0; i <= mx_sz; i++)
			it = st.insert(
				it, i
			);
	}

	// adds one copy of x from our structure O(log N)
	void add(int x) {
		if (x > mx_sz)
			return;
		if (hs[x] == 0) {
			st.erase(x);
		}
		hs[x]++;
	}

	// removes one copy of x from our structure O(log N);
	void remove(int x) {
		if (x > mx_sz)
			return;

		hs[x]--;
		if (!hs[x])
			st.emplace(x);

	}

	// returns the mex of our structure O(1)
	int operator () () const {
		return *st.begin();
	}


	/*
		Optional, you can just create with size N
		and add N elements :D
	 */
	Mex(const vector<int> &xs, int _mx_sz=-1) :
		Mex(_mx_sz == -1 ? xs.size() : _mx_sz)
       	{
		for (auto xi : xs)
			add(xi);
	}
};

