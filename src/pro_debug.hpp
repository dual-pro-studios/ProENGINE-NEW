#ifndef PRO_DEBUG_HPP
#define PRO_DEBUG_HPP

#include <string>
#include <iostream>
#include <fstream>

namespace pro {

class debug
{
public:
	enum DBG_TYPE {NORMAL, ERR, FATAL};
	static debug* getInstance();
	bool open(const char* fn);
	void log(const char* info, DBG_TYPE type = NORMAL);
	bool close();
private:
	debug() {}
	debug(debug const&);
	debug& operator=(debug const&);
	static debug* m_Instance;
	std::ofstream dbgFile;
};

}

#endif