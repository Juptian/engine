
#pragma once
#include <string>
#include <iostream>

namespace Sparky
{
	class FileUtils
	{
	public:
		//This works lets not touch it now thank you

		/*
		* Read_File(const char* filePath)
		* @param filePath Path to the file of which to read
		* @return Returns file contents
		*/
		static std::string Read_File(const char* filePath)
		{
			FILE* file = fopen(filePath, "rt"); //RT means read text
			fseek(file, 0, SEEK_END); //Getting the length of the file
			unsigned long length = ftell(file); //Putting it into a long
			char* data = new char[length + 1]; //Making a char* for it
			memset(data, 0, length + 1); //Setting everything to 0

			fseek(file, 0, SEEK_SET); //Going back to the beginning
			fread(data, 1, length, file); //Reading the file
			fclose(file); //Closing the file

			std::string result(data);
			delete[] data;
			return result;
		}

	};
}