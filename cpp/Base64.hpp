#pragma once

#include <string>
#include <vector>

std::string base64_encode(const std::vector<uint8_t> &bytes);
std::vector<uint8_t> base64_decode(std::string const& encoded_string);
