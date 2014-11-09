/*
 * StopData.h
 *
 *  Created on: 9 lis 2014
 *      Author: Rafa� Prusak
 */

#ifndef DB_STOPDATA_H_
#define DB_STOPDATA_H_

class StopData{
	public:
		StopData();
		StopData(const StopData& src);
		StopData(std::string name,unsigned int id,double lat,double lng);
		~StopData();
		StopData operator=(const StopData src);
		friend std::ostream& operator<<(std::ostream& output, const StopData& src);
		std::string getName() const;
		unsigned int getId() const;
		double getLat() const;
		double getLng() const;
	private:
		std::string name;
		unsigned int id;
		double lat;
		double lng;
};



#endif /* DB_STOPDATA_H_ */