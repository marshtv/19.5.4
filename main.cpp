#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string file_path;
	std::cout << "Input path to file for PNG-check:" << std::endl;
	std::cin >> file_path;

	//std::cout << file_path.substr((file_path.size() - 3));
	std::string file_ext = file_path.substr((file_path.size() - 3));

	if (file_ext != "png") {
		std::cout << "File's extension is not a *.png" << std::endl;
		std::cout << "Check Failed." << std::endl;
		return 0;
	}

	std::ifstream check_file;
	check_file.open(file_path);
	if (!check_file.is_open()) {
		std::cout << "File's path ERROR. File didn't opened" << std::endl;
		return 0;
	}

	int8_t check_num;
	char buffer[3];
	std::string check_ext_str;

	check_file.read((char*)buffer, 0);
	check_file >> check_num;
	//std::cout << (int)check_num << std::endl;

	check_file.read((char*)buffer, 2);
	check_file >> buffer;
	//std::cout << buffer << std::endl;

	if ((int)check_num != -119 && buffer[0] != 'P' && buffer[1] != 'N' && buffer[2] != 'G') {
		std::cout << "Content's identification ERROR!!!" << std::endl;
		std::cout << "Check Failed." << std::endl;
		return 0;
	} else {
		std::cout << "Check OK." << std::endl;
		std::cout << "File is PNG." << std::endl;
		return 0;
	}
}
