#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//Интерфейс
class Medication
{
public:
	virtual string GetName() = 0;
	virtual string GetDuration() = 0;
};

//Конкретный объект Медикаментозное лечение
class DrugTreatment : public Medication
{
public:
	virtual string GetName()
	{
		return string("Drug Treatment");
	}

	virtual string GetDuration()
	{
		return string("48 hours");
	}
};

//Конкретный объект Профилактика
class Prophylaxis : public Medication
{
public:
	virtual string GetName()
	{
		return string("Prophylaxis");
	}

	virtual string GetDuration()
	{
		return string("14 days");
	}
};

//Декоратор
class GoToHospital : public Medication
{
public:
	virtual string GetName()
	{
		return string("GoToHospital");
	}
	virtual string GetDuration()
	{
		return string("1 week");
	}
};

class Facade
{
private:
	unique_ptr<GoToHospital> gotohospital;
	unique_ptr<DrugTreatment> drugtreatment;
	unique_ptr<Prophylaxis> prophylaxis;
public:
	Facade() {
		gotohospital = std::make_unique<GoToHospital>();
		drugtreatment = std::make_unique<DrugTreatment>();
		prophylaxis = std::make_unique<Prophylaxis>();
	}

	void Duration()
	{
		cout << "Name: " << prophylaxis->GetName() << "\nDuration: " << prophylaxis->GetDuration() << endl;

		cout << "\n";

		cout << "Name: " << drugtreatment->GetName() << "\nDuration: " << drugtreatment->GetDuration() << endl;

		cout << "\n";

		cout << "Name: " << gotohospital->GetName() << "\nDuration: " << gotohospital->GetDuration() << endl;
	}
};