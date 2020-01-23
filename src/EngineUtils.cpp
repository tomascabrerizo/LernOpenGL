#include "EngineUtils.h"

namespace GameEngine {

	//Function to reaad text files	
	std::string Read_File(const char* filepath)
	{
		std::fstream file;
		file.open(filepath, std::ios::in);
		file.seekg(0, file.end);
		int lenght = file.tellg();
		file.seekg(0, file.beg);
		char* buffer = new char[lenght];
		memset(buffer, 0, lenght);
		file.read(buffer, lenght);
		file.close();
		
		std::string result(buffer);
		delete buffer;
		return result;
	}


}
