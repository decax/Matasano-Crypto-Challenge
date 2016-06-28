
#include "CryptoUtils.hpp"

#include <iostream>
#include <vector>
#include <iomanip>

void Challenge5()
{
	using namespace std;
	
	// Should produce 0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
	//                a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f
	std::string stanza =
	"Burning 'em, if you ain't quick and nimble\n"
	"I go crazy when I hear a cymbal";
	
	std::string key = "ICE";
	
	vector<uint8_t> a(stanza.begin(), stanza.end());
	vector<uint8_t> b(key.begin(), key.end());
	
	auto c = XOR(a, b);
	
	for (auto by : c) {
		cout << hex << setfill('0') << setw(2) << (int)by;
	}
	cout << std::endl;
}