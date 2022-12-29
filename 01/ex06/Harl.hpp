#include <iostream>

class Harl{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void so_what(void);
public:
	void complain(std::string level);
};