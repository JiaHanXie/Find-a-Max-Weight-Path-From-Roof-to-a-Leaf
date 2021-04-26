#if !defined(MainHeaderHpp_Included)
#define MainHeaderHpp_Included

#include <vector>
#include <string>
#include <fstream>

class MyFileStream;
class Main;

class Main{
public:
	static	void						Init();
	static	void						Computing();
	static	void						Exit();
	static	void						Arrangement();
	static	int							stage;
	static	int							Sum;
	static	std::vector<int>			WeightList;
	static	std::vector<std::string>	CommandList;
	static	std::string					ResultList;
	static	int							NumLine4Arrange;
};

class MyFileStream{
public:
	MyFileStream(std::string filename,int R_W);
	bool								Open();
	std::vector<std::string>			Read();
	void								Write(std::vector<std::string> Output_Line);
	void								Close();
private:
	std::fstream						file;
	std::string							filename;
	int									R_W;//0: read; 1: write
};

std::vector<std::string> split(std::string delim, std::string tgt);

#endif