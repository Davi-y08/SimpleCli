#include "Ethernet.hpp";
using namespace std;

#ifdef _WIN32
#define PING "ping -n 4 "
#define CURL "curl -s ifconfig.me"
#else
#define PING "ping -c 4 "
#define CURL "curl -s ifconfig.me"
#endif

void pingSite(const string& site) {
	string command = PING + site;
	std::system(command.c_str());
	cout << "a";
}