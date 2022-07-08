#include <iostream>

using namespace std;

int main(void){
	int total;
	cin >> total;
	
	int i;
	for (i = 0; i < total; i++){
		std::cout <<"Ho";
		
		if (i + 1 < total){
			std::cout <<" ";
		}
		else {
			std::cout <<"!" << std::endl;
		}

	}
}

// Accepted
