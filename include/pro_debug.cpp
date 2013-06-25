#include "pro_debug.hpp"

using namespace pro;

debug* debug::m_Instance = NULL;

debug* debug::getInstance() {
	if(!m_Instance)
		m_Instance = new debug;
	return m_Instance;
}

bool debug::open(const char* fn) {
	bool success;
	dbgFile.open(fn);
	if(!dbgFile.is_open()) {
		printf("[ERROR]: Debug file %s could not be created!\n", fn);
		success = false;
	} 
	else
		success = true;
	return success;
}

void debug::log(std::string info, DBG_TYPE type) {
	if(dbgFile.is_open()) {
		if(type == NORMAL) {
			std::cout << "[DEBUG]: " << info << std::endl;
			dbgFile << "[DEBUG]: " << info << std::endl;
		}
		if(type == ERR) {
			std::cout << "[ERROR]: " << info << std::endl;
			dbgFile << "[ERROR]: " << info << std::endl;
		}
		if(type == FATAL) {
			std::cout << "[FATAL]: " << info << std::endl;
			dbgFile << "[FATAL]: " << info << std::endl;
		}
	}
	else
		std::cerr << "[ERROR]: Could not write to file(the debug file is not open)!";
}

bool debug::close() {
	bool success;
	if(dbgFile.is_open()) {
		dbgFile.close();
		success = true;
	}
	else {
		std::cerr << "[ERROR]: The debug file has already been closed or wasn't created properly!\n";
		success = false;
	}
	return success;
}