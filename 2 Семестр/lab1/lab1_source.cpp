#include <iostream>
#include "stdlib.h"
#include <vector> 
#include "math.h"
#include <iomanip>
//#include "Vehicle.h"

using namespace std;

const char DefaultVehicleName[] = "Untyped Vehicle";
const char DefaultCoachName[] = "Default Coach";
const char DefaultAutomobileName[] = "Default Automobile";
const char DefaultAeroplaneName[] = "Default Aeroplane";

const double DefaultVehicleSpeed = -1.;
const double DefaultCoachSpeed = 10.;
const double DefaultAutomobileSpeed = 100.;
const double DefaultAeroplaneSpeed = 500.;

const double DefaultTimeToBoot = 0.01;


class Computer
{
public:
	Computer() : base_time_to_boot(DefaultTimeToBoot) {};
	~Computer() {};
	double GetTimeToBoot() { return base_time_to_boot; }
	void ComputerUpdate(double new__base_time_to_boot) { base_time_to_boot = new__base_time_to_boot; }
protected:
	double base_time_to_boot;
};

class Vehicle
{
public:
	Vehicle() : start_speed(DefaultVehicleSpeed), total_distance(0), total_time(0) { SetName(DefaultVehicleName); };
	Vehicle(string name, double start_speed) : start_speed(start_speed), total_distance(0), total_time(0) { SetName(name); };
	virtual ~Vehicle() { };

	string GetName() { return name; };
	double GetBaseSpeed() { return start_speed; };
	double GetTotalDistance() { return total_distance; };
	double GetTotalTime() { return total_time; };
	virtual bool MakeTrip(double distanceOfTrip)=0;
	virtual double GetSpeed() = 0;

protected:
	double total_distance;
	double total_time;

private:
	string name;
	double start_speed;
	void SetName(string name) { if (name.size() < 50) this->name = name; }
};
class Coach : public Vehicle
{
public:
	Coach(void) : Vehicle(DefaultCoachName, DefaultCoachSpeed) {};
	Coach(string name, double start_speed) : Vehicle (name, start_speed) {};
	~Coach() {};

	virtual bool MakeTrip(double distance_of_trip)
	{
		if (GetSpeed() <= 0) return false;
		if (distance_of_trip <= MAX_DISTANCE)
		{
			double time_of_trip = distance_of_trip / GetSpeed();
			total_time += time_of_trip; total_distance += distance_of_trip;
			return true;
		}
		else return false;
	}
	
	virtual double GetSpeed()
	{
		return GetBaseSpeed() * exp(-total_time / 500.);
	}
private:
	const double MAX_DISTANCE = 1000;

};
class Automobile : public Vehicle
{
public:
	Automobile(void) : Vehicle(DefaultAutomobileName, DefaultAutomobileSpeed) {};
	Automobile(string name, double start_speed) : Vehicle(name, start_speed) {};
	~Automobile() {};

	virtual bool MakeTrip(double distance_of_trip) 
	{
		if (GetSpeed() <= 0) return false;
		double time_of_trip = distance_of_trip / GetSpeed();
		total_distance += distance_of_trip;
		total_time += time_of_trip;
	}
	virtual double GetSpeed() { return GetBaseSpeed() * exp(-total_distance / 500.); }
};
class Aeroplane : public Vehicle, public Computer
{
public:
	const double MaxFlyTime = 20000;
	Aeroplane(void) :Vehicle(DefaultAeroplaneName, DefaultAeroplaneSpeed),Computer(), time_since_last_repair(0) {};
	Aeroplane(string name, double start_speed) : Vehicle(name, start_speed), Computer(), time_since_last_repair(0) {};
	~Aeroplane() {};

	virtual bool MakeTrip(double distance_of_trip) 
	{
		double time_of_trip = distance_of_trip / GetSpeed() + GetTimeToBoot();
		if (time_since_last_repair + time_of_trip > MaxFlyTime)return false;
		time_since_last_repair += time_of_trip;
		total_time += time_of_trip;
		total_distance += distance_of_trip;
		return true;
	}
	virtual double GetSpeed()
	{ return GetBaseSpeed(); }
	void Repair() { time_since_last_repair = 0; }
	double GetTimeSinceLastRepair() { return time_since_last_repair; }
private:
	double time_since_last_repair;
};




template <class MyType> void MySwap(MyType& v1, MyType& v2);
template <class ArrayType, class LessFunctionType> int FindMinimumIndex(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction);
template <class ArrayType, class LessFunctionType> void SelectionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction);
template <class ArrayType, class LessFunctionType> void InsertionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction);
bool CompareNames(Vehicle* lhs, Vehicle* rhs);
bool CompareBaseSpeeds(Vehicle* lhs, Vehicle* rhs);
bool CompareCurrentSpeeds(Vehicle* lhs, Vehicle* rhs);
void DisplayVehicles(const vector<Vehicle*>& vehicles);
void CommitRandomTrips(vector<Vehicle*>& vehicles);

void main() {
	srand(0);
	vector<Coach> coaches;
	vector<Automobile> automobiles;
	vector<Aeroplane> aeroplanes;

	vector<Vehicle*>coach_pointers;
	vector<Vehicle*>automobile_pointers;
	vector<Vehicle*>aeroplane_pointers;

	coaches.push_back(Coach("old coach", 10.));
	coaches.push_back(Coach("common coach", 15.));
	coaches.push_back(Coach("super coach", 20.));
	coaches.push_back(Coach());

	automobiles.push_back(Automobile());
	automobiles.push_back(Automobile("minivan", 110.));
	automobiles.push_back(Automobile("sportscar", 200.));
	automobiles.push_back(Automobile("pickup",140.));

	aeroplanes.push_back(Aeroplane());
	aeroplanes.push_back(Aeroplane("hawk", 700.));
	aeroplanes.push_back(Aeroplane("passenger liner", 600.));
	aeroplanes.push_back(Aeroplane("baggage liner", 550));
	
	vector<Vehicle*>all_vehicle_pointers;
	for (int i = 0; i < coaches.size(); i++) { coach_pointers.push_back(&coaches[i]); all_vehicle_pointers.push_back(&coaches[i]); }
	for (int i = 0; i < automobiles.size(); i++) { automobile_pointers.push_back(&automobiles[i]); all_vehicle_pointers.push_back(&automobiles[i]);}
	for (int i = 0; i < aeroplanes.size(); i++) { aeroplane_pointers.push_back(&aeroplanes[i]); all_vehicle_pointers.push_back(&aeroplanes[i]);}
	
	

	DisplayVehicles(all_vehicle_pointers);
	InsertionSort(all_vehicle_pointers, 0, 11, CompareCurrentSpeeds);
	DisplayVehicles(all_vehicle_pointers);

	CommitRandomTrips(automobile_pointers);
	CommitRandomTrips(coach_pointers);
	CommitRandomTrips(aeroplane_pointers);
	DisplayVehicles(all_vehicle_pointers);
	
}

void DisplayVehicles(const vector<Vehicle*>& vehicles)
{
	cout<<setw(30)<<left<<"NAME"<<setw(16)<<"BASE SPEED"<<setw(16)<<"CURRENT SPEED"<<setw(12)<<"distance"<<setw(12)<<"time"<<endl;
	for (int i = 0; i < vehicles.size(); ++i)
	{
		cout << setw(30) << vehicles[i]->GetName() << setw(16) << vehicles[i]->GetBaseSpeed() <<setw(16)<<vehicles[i]->GetSpeed()<< setw(12) << vehicles[i]->GetTotalDistance() << setw(12) << vehicles[i]->GetTotalTime() << endl;
	}
	cout << "\n\n";
}

void CommitRandomTrips(vector<Vehicle*>& vehicles) 
{
	for (int i = 0; i < vehicles.size(); i++) 
	{
		double rand_distance = double(rand() % 20001) / 10.;
		vehicles[i]->MakeTrip(rand_distance);
	}
}

template <class MyType> void MySwap(MyType& v1, MyType& v2) {
	MyType v3 = v1;
	v1 = v2;
	v2 = v3;
}

template <class ArrayType, class LessFunctionType> 
int FindMinimumIndex(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) 
{ 
	int minimumIndex = beginIndex;
	for (int element_number = beginIndex + 1; element_number <= endIndex; ++element_number) 
	{
		if (LessFunction(data_array[element_number], data_array[minimumIndex])) 
		{ minimumIndex = element_number; } 
	}  return minimumIndex; }

template <class ArrayType, class LessFunctionType> 
void SelectionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) 
{
	for (int element_number = beginIndex; element_number < endIndex; ++element_number) 
	{
		int minimumIndex = FindMinimumIndex(data_array, element_number, endIndex, LessFunction);
		MySwap(data_array[minimumIndex], data_array[element_number]); 
	} 
}

// вариант 1
template<class ArrayType, class LessFunctionType>
void InsertionSort(ArrayType& data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) 
{
	for (int element_number = beginIndex; element_number <= endIndex; element_number++) {
		for (int previous_number = beginIndex; previous_number<element_number; previous_number++) if (LessFunction(data_array[element_number], data_array[previous_number])) {
			MySwap(data_array[previous_number], data_array[element_number]);
			continue;
		}
	}

}

bool CompareNames(Vehicle* lhs, Vehicle* rhs) { return lhs->GetName() < rhs->GetName(); }

bool CompareBaseSpeeds(Vehicle* lhs, Vehicle* rhs) { return lhs->GetBaseSpeed() < rhs->GetBaseSpeed(); }

bool CompareCurrentSpeeds(Vehicle* lhs, Vehicle* rhs) { return lhs->GetSpeed() < rhs->GetSpeed(); }