/*
 * DataBase.cpp
 *
 *  Created on: 10 lis 2014
 *      Author: Rafa� Prusak
 */


#include "DataBase.h"
#include "lib/DataReader.h"
#include "lib/GTFSReader.h"


DataBase::DataBase(DataBase::LoadMethod method, std::string path)
	:
	path(path)
{
	if(method == DataBase::LoadMethod::JSON) this->loadJSON();
	else if(method == DataBase::LoadMethod::GTFS) this->loadGTFS();
	else return;

	this->validate();
}

void DataBase::loadGTFS() {

	GTFSReader reader;
	reader.readGTFS(this->path);

	this->routes = reader.getRoutes();
	this->stops = reader.getStops();
	this->trips = reader.getTrips();
	this->stopTimes = reader.getStopTimes();
	this->services = reader.getServices();

}

void DataBase::loadJSON() {

	const std::string routesFile = this->path + "/" + "routes.json";
	const std::string tripsFile = this->path + "/" + "trips.json";
	const std::string stopsFile = this->path + "/" + "stops.json";
	const std::string stopTimesFile = this->path + "/" + "stop_times.json";
	const std::string servicesFile = this->path + "/" + "services.json";

	this->routes = DataReader::readRoutes(routesFile);
	this->trips = DataReader::readTrips(tripsFile);
	this->stops = DataReader::readStops(stopsFile);
	this->stopTimes = DataReader::readStopTimes(stopTimesFile);
	this->services = DataReader::readServices(servicesFile);
}

void DataBase::validate() {

	if(routes.empty()){
		std::cerr<<"routes vector is empty!"<<std::endl;
	}else{
		std::cerr<<"routes vector is ready"<<std::endl;
	}

	if(trips.empty()){
		std::cerr<<"trips vector is empty!"<<std::endl;
	}else{
		std::cerr<<"trips vector is ready"<<std::endl;
	}

	if(stops.empty()){
		std::cerr<<"stops vector is empty!"<<std::endl;
	}else{
		std::cerr<<"stops vector is ready"<<std::endl;
	}

	if(stopTimes.empty()){
		std::cerr<<"stop times vector is empty!"<<std::endl;
	}else{
		std::cerr<<"stop times vector is ready"<<std::endl;
	}

	if(services.empty()){
		std::cerr<<"services vector is empty!"<<std::endl;
	}else{
		std::cerr<<"services vector is ready"<<std::endl;
	}

}
