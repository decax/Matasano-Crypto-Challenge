#include "CryptoUtils.hpp"

#include <map>

void Challenge3()
{
	using namespace std;
	
	auto cypherText = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	
	auto a = Hex2Bytes(cypherText);
	
	map<int, double> scores;
	
	for (int b = 0; b < 256; b++) {
		auto plainText = XOR(a, (uint8_t)b);
		scores[b] = LetterFrequencyScore(plainText);
	}
	
	auto max = max_element(scores.begin(), scores.end(), [](pair<int, double> lhs, pair<int, double> rhs) { return lhs.second < rhs.second; });
	PrintBytesAsAscii(XOR(a, (*max).first));
}