#include "CryptoUtils.hpp"

#include "Base64.hpp"

#include <cstdlib>

double LetterFrequencyScore(const std::vector<uint8_t> &s)
{
	//static std::map<char, double> letterScore = {
	//	{ 'a', 0.0651738 },
	//	{ 'b', 0.0124248 },
	//	{ 'c', 0.0217339 },
	//	{ 'd', 0.0349835 },
	//	{ 'e', 0.1041442 },
	//	{ 'f', 0.0197881 },
	//	{ 'g', 0.0158610 },
	//	{ 'h', 0.0492888 },
	//	{ 'i', 0.0558094 },
	//	{ 'j', 0.0009033 },
	//	{ 'k', 0.0050529 },
	//	{ 'l', 0.0331490 },
	//	{ 'm', 0.0202124 },
	//	{ 'n', 0.0564513 },
	//	{ 'o', 0.0596302 },
	//	{ 'p', 0.0137645 },
	//	{ 'q', 0.0008606 },
	//	{ 'r', 0.0497563 },
	//	{ 's', 0.0515760 },
	//	{ 't', 0.0729357 },
	//	{ 'u', 0.0225134 },
	//	{ 'v', 0.0082903 },
	//	{ 'w', 0.0171272 },
	//	{ 'x', 0.0013692 },
	//	{ 'y', 0.0145984 },
	//	{ 'z', 0.0007836 },
	//	{ ' ', 0.1918182 }
	//};
	static std::vector<double> letterScore = {
		0.0651738, // a
		0.0124248, // b
		0.0217339, // c
		0.0349835, // d
		0.1041442, // e
		0.0197881, // f
		0.0158610, // g
		0.0492888, // h
		0.0558094, // i
		0.0009033, // j
		0.0050529, // k
		0.0331490, // l
		0.0202124, // m
		0.0564513, // n
		0.0596302, // o
		0.0137645, // p
		0.0008606, // q
		0.0497563, // r
		0.0515760, // s
		0.0729357, // t
		0.0225134, // u
		0.0082903, // v
		0.0171272, // w
		0.0013692, // x
		0.0145984, // y
		0.0007836, // z
		0.1918182  // (space)
	};
	
	double total = 0.0;
	for (auto c : s) {
		auto ch = c & 0xdf;
		if (ch >= 'A' && ch <= 'Z') {
			total += letterScore[ch - 'A'];
		}
		else if (c == ' ')
		{
			total += 0.1918182;
		}
		//auto it = letterScore.find(tolower(c));
		//if (it != letterScore.end()) {
		//	total += it->second;
		//}
	}
	
	return total / s.size();
}

double LetterFrequencyScore2(const std::vector<uint8_t> &s)
{
	//static std::map<char, double> letterScore = {
	//	{ 'a', 0.0651738 },
	//	{ 'b', 0.0124248 },
	//	{ 'c', 0.0217339 },
	//	{ 'd', 0.0349835 },
	//	{ 'e', 0.1041442 },
	//	{ 'f', 0.0197881 },
	//	{ 'g', 0.0158610 },
	//	{ 'h', 0.0492888 },
	//	{ 'i', 0.0558094 },
	//	{ 'j', 0.0009033 },
	//	{ 'k', 0.0050529 },
	//	{ 'l', 0.0331490 },
	//	{ 'm', 0.0202124 },
	//	{ 'n', 0.0564513 },
	//	{ 'o', 0.0596302 },
	//	{ 'p', 0.0137645 },
	//	{ 'q', 0.0008606 },
	//	{ 'r', 0.0497563 },
	//	{ 's', 0.0515760 },
	//	{ 't', 0.0729357 },
	//	{ 'u', 0.0225134 },
	//	{ 'v', 0.0082903 },
	//	{ 'w', 0.0171272 },
	//	{ 'x', 0.0013692 },
	//	{ 'y', 0.0145984 },
	//	{ 'z', 0.0007836 },
	//	{ ' ', 0.1918182 }
	//};
	static std::vector<double> letterScore = {
		0.0651738, // a
		0.0124248, // b
		0.0217339, // c
		0.0349835, // d
		0.1041442, // e
		0.0197881, // f
		0.0158610, // g
		0.0492888, // h
		0.0558094, // i
		0.0009033, // j
		0.0050529, // k
		0.0331490, // l
		0.0202124, // m
		0.0564513, // n
		0.0596302, // o
		0.0137645, // p
		0.0008606, // q
		0.0497563, // r
		0.0515760, // s
		0.0729357, // t
		0.0225134, // u
		0.0082903, // v
		0.0171272, // w
		0.0013692, // x
		0.0145984, // y
		0.0007836, // z
		0.1918182  // (space)
	};
	
	double total = 0.0;
	for (auto c : s) {
		auto ch = c & 0xdf;
		if (ch >= 'A' && ch <= 'Z') {
			total += letterScore[ch - 'A'];
		}
		else if (c == ' ')
		{
			total += 0.1918182;
		}
		//auto it = letterScore.find(tolower(c));
		//if (it != letterScore.end()) {
		//	total += it->second;
		//}
	}
	
	return total / s.size();
}

std::vector<uint8_t> Hex2Bytes(const std::string &hex)
{
	std::vector<uint8_t> bytes(hex.size() / 2);
	
	char h[3] = { 0 };
	
	for (size_t i = 0, j = 0; i < hex.size(); i += 2, j++) {
		h[0] = hex[i];
		h[1] = hex[i + 1];
		
		bytes[j] = (uint8_t)strtol(h, nullptr, 16);
	}
	
	return bytes;
}

std::string Hex2Base64(const std::string &hex)
{
	return base64_encode(Hex2Bytes(hex));
}

std::vector<uint8_t> XOR(const std::vector<uint8_t> &a, uint8_t b)
{
	std::vector<uint8_t> c(a);
	for (size_t i = 0; i < a.size(); i++) {
		c[i] ^= b;
	}
	
	return c;
}

void XOR(const std::vector<uint8_t> &a, uint8_t b, std::vector<uint8_t> &c)
{
	for (size_t i = 0; i < a.size(); i++) {
		c[i] = a[i] ^ b;
	}
}

std::vector<uint8_t> XOR(const std::vector<uint8_t> &a, const std::vector<uint8_t> &b)
{
	std::vector<uint8_t> c(a);
	for (size_t i = 0, j = 0; i < a.size(); i++) {
		c[i] ^= b[j];
		
		if (++j >= b.size())
			j %= b.size();
	}
	
	return c;
}

#include <iostream>

void PrintBytesAsAscii(const std::vector<uint8_t> &bytes)
{
	for (auto b : bytes) {
		std::cout << b;
	}
	std::cout << std::endl;
}

int NbBits(uint8_t x)
{
	int nbBits = 0;
	for (int i = 0; i < sizeof(uint8_t) * 8; i++) {
		nbBits += (x & (1 << i)) >> i;
	}
	
	return nbBits;
}

int HammingDistance(std::string a, std::string b)
{
	int diff = 0;
	for (size_t i = 0; i < a.size(); i++) {
		diff += NbBits(a[i] ^ b[i]);
	}
	
	return diff;
}