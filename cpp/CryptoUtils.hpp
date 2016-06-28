#pragma once

#include <vector>
#include <string>

double LetterFrequencyScore(const std::vector<uint8_t> &s);
double LetterFrequencyScore2(const std::vector<uint8_t> &s);

std::vector<uint8_t> Hex2Bytes(const std::string &hex);
std::string Hex2Base64(const std::string &hex);

std::vector<uint8_t> XOR(const std::vector<uint8_t> &a, uint8_t b);
void XOR(const std::vector<uint8_t> &a, uint8_t b, std::vector<uint8_t> &c);
std::vector<uint8_t> XOR(const std::vector<uint8_t> &a, const std::vector<uint8_t> &b);

void PrintBytesAsAscii(const std::vector<uint8_t> &bytes);

int HammingDistance(std::string a, std::string b);