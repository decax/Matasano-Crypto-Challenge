#include "CryptoUtils.hpp"

#include <iostream>

void Challenge2()
{
	using namespace std;
	
	// should produce 746865206b696420646f6e277420706c6179
	
	auto a = "1c0111001f010100061a024b53535009181c";
	auto b = "686974207468652062756c6c277320657965";
	auto c = XOR(Hex2Bytes(a), Hex2Bytes(b));
	
	for (auto b : c) {
		cout << hex << (int)b;
	}
	
	cout << endl;
}
