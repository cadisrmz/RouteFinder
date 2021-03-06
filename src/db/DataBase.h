/*
 * DataBase.h
 *
 *  Created on: 10 lis 2014
 *      Author: Rafa� Prusak
 */

#ifndef DB_DATABASE_H_
#define DB_DATABASE_H_

#include <iostream>
#include <string>
#include <fstream>

#include "lib/RouteData.h"
#include "lib/TripData.h"
#include "lib/StopData.h"
#include "lib/StopTimeData.h"
#include "lib/ServiceData.h"

#include "../jsoncpp/json/json.h"

/**
 * Database class, used to loading from files and then being converted into
 * Network object. Provides input from gtfs or json formats.
 */
class DataBase{
public:

/**
 * Enum defining loading method being used.
 */
	enum LoadMethod {
		JSON = 0,
		GTFS = 1,
		MULTJSON = 2,
		SAVEDDB = 3,
		EMPTY = 4
	};
	DataBase();
	/**
	 * Constructor.
	 * @param method Defines load method being used.
	 * @param path Provides path to files being loaded. If one file is being used
	 * it needs to get path to file, otherwise - to directory containing files.
	 */
	DataBase(DataBase::LoadMethod method, std::string path);

	/**
	 * std::vector object containing loaded RouteData.
	 */
	std::vector<RouteData> routes;

	/**
	 * std::vector object containing loaded TripData.
	 */
	std::vector<TripData> trips;

	/**
	 * std::vector object containing loaded StopData.
	 */
	std::vector<StopData> stops;

	/**
	 * std::vector object containing loaded StopTimeData.
	 */
	std::vector<StopTimeData> stopTimes;

	/**
	 * std::vector object containing loaded ServiceData.
	 */
	std::vector<ServiceData> services;

	std::vector<std::vector<std::vector<Time>>> timeTable;

	/**
	 * Method checking validity of loaded database.
	 * @return true if all vectors got populated with data, false otherwise.
	 */
	bool isValid();

	void saveToFile(const std::string p) const;

private:
	std::string path;
	void loadGTFS();
	void loadJSON();
	void loadOneJSON();
	void loadSavedDB(const std::string p);

	void createTimeTable();

	void validate();

};


#endif /* DB_DATABASE_H_ */
