#include "Base64.hpp"
#include "CryptoUtils.hpp"

#include <fstream>
#include <string>
#include <iostream>

void Challenge6()
{
	using namespace std;
	
	auto x = HammingDistance("this is a test", "wokka wokka!!!"); // should return 37
	if (x != 37) {
		return;
	}
	
	ifstream f("6.txt");
	string str((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
	auto cypherText = base64_decode(str);
	
	vector<double> hammingDistances(40 - 1);
	
	for (int keySize = 2; keySize <= 40; keySize++) {
		string a(cypherText.begin(), cypherText.begin() + keySize);
		string b(cypherText.begin() + keySize, cypherText.begin() + keySize * 2);
		
		hammingDistances[keySize - 2] = (double)HammingDistance(a, b) / keySize;
	}
	
	auto it = min_element(hammingDistances.begin(), hammingDistances.end());
	cout << "KeySize = " << it - hammingDistances.begin() + 2 << endl;
}