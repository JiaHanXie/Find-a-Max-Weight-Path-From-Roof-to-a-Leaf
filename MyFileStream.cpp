#include "MainHeader.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define BUFFERSIZE 512

MyFileStream::MyFileStream(std::string filename,int R_W){
	this->filename=filename;
	this->R_W=R_W;
}

bool MyFileStream::Open(){
	file.open(filename.c_str(),(R_W==1)?(std::ios::out|std::ios::trunc):(std::ios::in));
	if(!file.good()){
		std::cout << "Can't open file " << filename << std::endl;
		return false;
	}
	return true;
}

std::vector<std::string> MyFileStream::Read(){
	char line[BUFFERSIZE];
	std::vector<std::string> Input_Line;
	Input_Line.clear();
	if (file.good()){
		while (!file.eof()){
			file.getline(line, BUFFERSIZE);
			Input_Line.push_back(line);
		}
	}else{
		std::cout << "File Error!" << std::endl;
	}
	return Input_Line;
}

void MyFileStream::Write(std::vector<std::string> Output_Line){
	std::string outString="";
	for(size_t i=0;i<Output_Line.size();i++)
		outString=outString+Output_Line[i]+"\n";
	file << outString;
}

void MyFileStream::Close(){
	file.close();
}