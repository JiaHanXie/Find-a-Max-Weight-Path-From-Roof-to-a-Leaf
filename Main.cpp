#include "MainHeader.hpp"
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define	INPUTFILE	"input"
#define	OUTPUTFILE	"output"

int							Main::stage=0;
int							Main::Sum=0;
std::vector<int>			Main::WeightList;
std::vector<std::string>	Main::CommandList;
std::string					Main::ResultList="";
int							Main::NumLine4Arrange=0;

void Main::Init(){
	NumLine4Arrange=0;
	MyFileStream READ(INPUTFILE,0);
	READ.Open();
	CommandList=READ.Read();
	WeightList.clear();
	while(CommandList[NumLine4Arrange]!="exit"){
		Main::Arrangement();
	}
	std::cout << "Number of nodes=" << WeightList.size() << std::endl;
	if(WeightList.size()!=((1-pow(2,stage))/-1)){
		std::cout << "error: format of input file is wrong!" << std::endl;
	}
	READ.Close();
}

void Main::Computing(){
	std::vector<int> SumList_Temp0(pow(2,stage),0);
	std::vector<int> SumList_Temp1;
	std::vector<std::string> ResultList0(pow(2,stage),"");
	std::vector<std::string> ResultList1;
	while(stage>1){
		SumList_Temp1.clear();
		ResultList1.clear();
		for(int i=0;i<pow(2,stage-1);i=i+2){
			if(WeightList[pow(2,stage-1)-1+i]+SumList_Temp0[i]>=WeightList[pow(2,stage-1)+i]+SumList_Temp0[i+1]){
				ResultList1.push_back(" Left "+ResultList0[i]);
				SumList_Temp1.push_back(WeightList[pow(2,stage-1)-1+i]+SumList_Temp0[i]);
			}else{
				ResultList1.push_back(" Right "+ResultList0[i+1]);
				SumList_Temp1.push_back(WeightList[pow(2,stage-1)+i]+SumList_Temp0[i+1]);
			}
			SumList_Temp0.clear();
			ResultList0.clear();
			SumList_Temp0.assign(SumList_Temp1.begin(),SumList_Temp1.end());
			ResultList0.assign(ResultList1.begin(),ResultList1.end());
		}
		stage=stage-1;
	}
	ResultList=ResultList1[0];
	Sum=SumList_Temp1[0]+WeightList[0];
}

void Main::Exit(){
	ResultList=ResultList+" "+(std::to_string(Sum));
	std::vector<std::string> Result=split(" ",ResultList);
	MyFileStream WRITE(OUTPUTFILE,1);
	WRITE.Open();
	WRITE.Write(Result);
	WRITE.Close();
	for(int i=0;i<Result.size();i++){
		std::cout << Result[i] << std::endl;
	}
}

void Main::Arrangement(){
	std::vector<std::string> argv=split(" ",CommandList[NumLine4Arrange]);
	if(argv[0]=="Stage"){
		stage=std::stoi(argv[1]);
	}else if(argv[0]=="Weight"){
		WeightList.push_back(std::stoi(argv[1]));
	}else{
		std::cout << "error: format of input file is wrong!" << std::endl;
	}
	NumLine4Arrange=NumLine4Arrange+1;
}

std::vector<std::string> split(std::string delim, std::string tgt){
	std::vector<std::string> result;
	char* word=NULL;
	word=strtok(const_cast<char*>(tgt.c_str()), delim.c_str());
	while (word!=NULL){
		result.push_back(word);
		word=strtok(NULL, delim.c_str());
	}
	return result;
}