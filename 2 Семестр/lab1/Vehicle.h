#pragma once
class Vehicle
{
private:
	char* name;
	int start_speed;
	virtual bool MakeTrip(double distanceOfTrip);
public:
	Vehicle(void);
	Vehicle(char*);
	Vehicle(double);
	Vehicle(char*, double);
	~Vehicle();
};
class Coach :Vehicle
{
	bool MakeTrip(double distanceOfTrip);
public:
	Coach(void);
	Coach(char*) ;
	Coach(char*, double);
	~Coach();
};
class Automobile :Vehicle
{
	bool MakeTrip(double distanceOfTrip);
public:
	Automobile(void);
	Automobile(char*);
	Automobile(char*, double);
	~Automobile();
};
class Aeroplane :Vehicle
{
	bool MakeTrip(double distanceOfTrip);
public:
	Aeroplane(void);
	Aeroplane(char*);
	Aeroplane(char*, double);
	~Aeroplane();

};