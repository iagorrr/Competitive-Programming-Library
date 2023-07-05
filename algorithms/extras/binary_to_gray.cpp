string binToGray(string bin){
	string gray(bin.size(), '0');
	int n =  bin.size()-1;
	gray[0] = bin[0];
	for(int i = 1; i <= n; i++){
		gray[i] = '0'+(bin[i-1]=='1')^(bin[i]=='1');
	}
	return gray;
}