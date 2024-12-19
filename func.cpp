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
		dec += (ch >= '0' && ch <= '9' ? ch - '0' : ch - 'a' + 10) * (16 << (i * 4));
	}
	
	return dec;
}

uint16_t getHexNum(const char& hexCh)
{
    return hexCh >= '0' && hexCh <= '9' ? hexCh - '0' : hexCh - 'a' + 10;
}

std::string hexToBin(const std::string& hex)
{
    std::string bin(hex.size() * 4, '0');
    
    for (uint64_t i = 0, pos = bin.size(); i < hex.size(); i++)
    {
        int hexNum = getHexNum(hex[hex.size() - 1 - i]);
        bin[--pos] = ((hexNum & 1) != 0) + '0';
        bin[--pos] = ((hexNum & 3) != 0) + '0';
        bin[--pos] = ((hexNum & 7) != 0) + '0';
        bin[--pos] = ((hexNum & 15) != 0) + '0';
    }
    
    return bin;
}

std::string binToHex(const std::string& bin)
{
    std::string hex(bin.size() / 4, '0');
    
    for (uint64_t i = 0; i < hex.size(); i++)
    {
        uint8_t binNum = binToDec<uint64_t>(bin.substr(bin.size() - ((i + 1) * 4), 4));
        hex[hex.size() - 1 - i] = decToHex(binNum)[1];
    }
    
    return hex;
}

int main()
{
    using Int = int8_t;
    
    Int n = -1;
    std::string bin = decToBin(n),
        hex = decToHex(n),
        binToH = binToHex(bin),
        hexToB = hexToBin(hex);
    Int binToN = binToDec<Int>(bin),
        hexToN = hexToDec<Int>(hex);
        
    std::cout << "dec: " << (typeid(Int).name() == typeid(int8_t).name() || typeid(Int).name() == typeid(uint8_t).name() ? (int)n : n)
        << "\nbin: " << bin
        << "\nhex: " << hex
        << "\nbin to hex: " << binToH
        << "\nhex to bin: " << hexToB
        << "\nbin to dec: " << (typeid(Int).name() == typeid(int8_t).name() || typeid(Int).name() == typeid(uint8_t).name() ? (int)binToN : binToN)
        << "\nhex to dec: " << (typeid(Int).name() == typeid(int8_t).name() || typeid(Int).name() == typeid(uint8_t).name() ? (int)hexToN : hexToN);
}
