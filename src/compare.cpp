/*
*   COMPARE
*	A basic utility to compare two files.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define DEBUG 0
int main(int argc, char *argv[]){
	if(DEBUG == 1){
		std::cout << "Debug Info" << std::endl;
		std::cout<< "==============================" << std::endl;
		if(argv[0]){std::cout<< "ARGV 0: " << argv[0] << std::endl;}
		if(argv[1]){std::cout<< "ARGV 1: " << argv[1] << std::endl;}
		if(argv[2]){std::cout<< "ARGV 2: " << argv[2] << std::endl;}
		if(argv[3]){std::cout<< "ARGV 3: " << argv[3] << std::endl;}
		std::cout<< "==============================" << std::endl;
	}
	int show, nomatch, match;
	std::string fileOneName,fileTwoName;
	if(argv[1]){
	fileOneName = argv[1];
	}else{
		std::cout<< "USAGE: " << std::endl;
		std::cout<< "./compare [filename1] [filename2] (optional) {--show-output}" << std::endl;
		return 1;
	}
	if(argv[2]){
	fileTwoName = argv[2];
	}else{
		if(fileOneName != "--help"){
			std::cout<< "USAGE: " << std::endl;
			std::cout<< "./compare [filename1] [filename2] (optional) {--show-output}" << std::endl;
			return 1;
		}
	}
	if(fileOneName == "--help"){
		std::cout<< "Compare Utils 1.0" << std::endl;
		std::cout<< "==============================" << std::endl;
		std::cout<< "USAGE: " << std::endl;
		std::cout<< "./compare [filename1] [filename2] (optional) {--show-output}" << std::endl;
		std::cout<< "'--show-output' shows exactly what is diffrent." << std::endl;
		std::cout<< "Commands:" << std::endl;
		std::cout<< "* --help = shows this page and exits" << std::endl;
		std::cout<< "==============================" << std::endl;
		return 0;
	}
	if(argv[3]){
		std::string isshow = argv[3];
		if(isshow == "--show"){
			show = 1;
		}
	}
	std::ifstream fileOne;
	std::ifstream fileTwo;
	fileOne.open(fileOneName, std::ios::binary | std::ios::in);
	fileTwo.open(fileTwoName, std::ios::binary | std::ios::in);
	char current;
	char currentt;
	std::cout<< "==============================" << std::endl;
	while(fileOne.get(current) && fileTwo.get(currentt)){
		if(current == currentt){
			match++;
		}else{
			if(show == 1){
				std::cout<< "CONFICT: " << current<< " VS: "<<currentt<< std::endl;
			}
			nomatch++;
		}
	}
	std::cout<< "============FINAL=============" << std::endl;
	std::cout<< "==============================" << std::endl;
	std::cout<< "MATCHES: " << match << std::endl;
	std::cout<< "NO MATCHES: " << nomatch << std::endl;
	std::cout<< "==============================" << std::endl;
	return 0;
}