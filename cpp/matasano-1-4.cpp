#include "CryptoUtils.hpp"

#include <string>
#include <fstream>
#include <algorithm>

void Challenge4()
{
	using namespace std;
	
	vector<string> cypherTexts;
	
	ifstream f("4.txt");
	while (!f.eof()) {
		string line;
		f >> line;
		cypherTexts.push_back(line);
	}
	
	vector<double> scores(cypherTexts.size() * 256);
	
	for (size_t i = 0; i < cypherTexts.size(); i++) {
		auto cypherText = cypherTexts[i];
		auto a = Hex2Bytes(cypherText);
		
		vector<uint8_t> c(a.size());
		for (int b = 0; b < 256; b++) {
			XOR(a, (uint8_t)b, c);
			scores[b + i * 256] = LetterFrequencyScore(c);
		}
	}
	
	auto max = max_element(scores.begin(), scores.end());
	
	auto maxIndex = distance(scores.begin(), max);
	
	auto cypherText = cypherTexts[maxIndex / 256];
	auto a = Hex2Bytes(cypherText);
	
	PrintBytesAsAscii(XOR(a, maxIndex % 256));
}