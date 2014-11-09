/*
 * DataReader.cpp
 *
 *  Created on: 9 lis 2014
 *      Author: Rafa� Prusak
 */

#include "DataReader.h"

#include "../jsoncpp/json/json.h"

#include <fstream>
#include <iostream>

std::vector<RouteData> DataReader::readRoutes(std::string filename){
	std::ifstream file(filename.c_str(),std::ios::in);
	std::vector<RouteData> result;
	result.clear();
	if(!file.is_open()){
		std::cout<<"Otwarcie pliku "<<filename<<" nie powiod�o sie!"<<std::endl;
		return result;
	}else{
		//std::cout<<"Otwarto poprawnie plik "<<filename<<std::endl;

		Json::Reader parser;
		Json::Value root;

		if( !parser.parse(file,root) ){
			std::cout<<parser.getFormatedErrorMessages()<<std::endl;
			return result;
		}else{
			Json::Value routes = root["routes"];
			for(unsigned int i=0; i<routes.size();i++){
				RouteData temp(routes[i]["name"].asString(),routes[i]["id"].asInt());
				result.push_back(temp);
			}
		}
		return result;
	}
}