#include <iostream>
#include <cstdint>


template<class T>
std::string decToBin(const T& n)
{
	const uint64_t typeSize = sizeof(T) * 8;
	
	std::string bin(typeSize, '0');
	
	for (T i = 0; i < typeSize; i++)
	{
		bin[typeSize - 1 - i] = (bool)(n & ((uint64_t)1 << i)) + '0';
	}
	
	return bin;
}

template<class T>
T binToDec(const std::string& bin)
{
	T dec = 0;
	
	for (T i = 0; i < bin.size(); i++)
	{
		dec += (uint64_t)(bin[bin.size() - 1 - i] - '0') << i;
	}
	
	return dec;
}

template<class T>
std::string decToHex(T n)
{
	const uint64_t typeSize = sizeof(T) * 2;
	const char* HEX_VALS = "0123456789abcdef";
	
	std::string hex(typeSize, '0');
	
	for (T i = 0; i < typeSize; i++, n >>= 4)
	{
		hex[typeSize - 1 - i] = HEX_VALS[n & 15];
	}
	
	return hex;
}

template<class T>
T hexToDec(const std::string& hex)
{
	T dec = 0;
	
	for (T i = 0; i < hex.size(); i++)
	{
		char ch = hex[hex.size() - 1 - i];
		std::cout << (ch >= '0' && ch <= '9' ? ch - '0' : ch - 'a' + 10) << '\n';
		dec += (ch >= '0' && ch <= '9' ? ch - '0' : ch - 'a' + 10) * (i + 1);
	}
	
	return dec;
}