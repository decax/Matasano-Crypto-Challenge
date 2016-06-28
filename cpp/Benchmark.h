#pragma once

#include <string>
#include <map>
#include <chrono>
#include <iostream>

class Benchmark
{
public:
	static void Begin(const std::string &title)
	{
		beginTimePoint[title] = std::chrono::high_resolution_clock::now();
	}
	
	static void End(const std::string &title)
	{
		auto begin = beginTimePoint[title];
		auto end = std::chrono::high_resolution_clock::now();
		
		std::cout << title << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
	}
	
private:
	static std::map<std::string, std::chrono::high_resolution_clock::time_point> beginTimePoint;
};