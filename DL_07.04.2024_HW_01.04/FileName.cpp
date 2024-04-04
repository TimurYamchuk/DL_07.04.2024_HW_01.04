#include <iostream>
#include <string>

using namespace std;

class Car
{
	string body;
	string propeller;
	string wheels;
	string gearbox;
public:
	void SetBody(string body)
	{
		this->body = body;
	}
	string GetBody()
	{
		return this->body;
	}
	void SetPropeller(string propeller)
	{
		this->propeller = propeller;
	}
	string GetPropeller()
	{
		return this->propeller;
	}
	void SetWheels(string wheels)
	{
		this->wheels = wheels;
	}
	string GetWheels()
	{
		return this->wheels;
	}
	void SetGearbox(string gearbox)
	{
		this->gearbox = gearbox;
	}
	string GetGearbox()
	{
		return this->gearbox;
	}
	void ShowCar()
	{
		cout << "Car with Body: " + body + ", Propeller: " + propeller + ", Wheels: " + wheels + +", Gearbox: " + gearbox + "\n";
	}
};

// Abstract Builder задает абстрактный интерфейс (класс) дл€ создани€ частей объекта Product (в нашем случае, Pizza);
/** "Abstract Builder" */
class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildBody() abstract;
	virtual void BuildPropeller() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildGearbox() abstract;
};

// ConcreteBuilder выполн€ет следующие действи€:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определ€ет создаваемое представление и следит за ним;
// - предоставл€ет интерфейс дл€ доступа к продукту

class DaewooLanosBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Sedan");
	}
	void BuildPropeller() override
	{
		car.SetPropeller("98");
	}
	void BuildWheels() override
	{
		car.SetWheels("13");
	}
	void BuildGearbox() override
	{
		car.SetGearbox("5 Manual");
	}
};

class FordProbeBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Cupe");
	}
	void BuildPropeller() override
	{
		car.SetPropeller("160");
	}
	void BuildWheels() override
	{
		car.SetWheels("14");
	}
	void BuildGearbox() override
	{
		car.SetGearbox("4 Auto");
	}
};

class UAZPatriotBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Universul");
	}
	void BuildPropeller() override
	{
		car.SetPropeller("120");
	}
	void BuildWheels() override
	{
		car.SetWheels("16");
	}
	void BuildGearbox() override
	{
		car.SetGearbox("4 Manual");
	}
};

class HyndaiGetzBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Hetsh");
	}
	void BuildPropeller() override
	{
		car.SetPropeller("66");
	}
	void BuildWheels() override
	{
		car.SetWheels("13");
	}
	void BuildGearbox() override
	{
		car.SetGearbox("4 auto");
	}
};

// Director(распор€дитель) - конструирует объект (Pizza), пользу€сь интерфейсом Builder
class Waiter
{
	CarBuilder* carBuilder;
public:
	void SetPizzaBuilder(CarBuilder* pb)
	{
		carBuilder = pb;
	}
	Car GetPizza()
	{
		return carBuilder->GetCar();
	}
	void ConstructPizza()
	{
		carBuilder->BuildBody();
		carBuilder->BuildPropeller();
		carBuilder->BuildWheels();
		carBuilder->BuildGearbox();
	}
};

// клиент создает объект-распор€дитель Director и конфигурирует его нужным объектом-строителем Builder
void client(CarBuilder* builder)
{
	Waiter waiter;
	waiter.SetPizzaBuilder(builder);
	waiter.ConstructPizza();
	Car car = waiter.GetPizza();
	car.ShowCar();
}

void main()
{
	CarBuilder* builder = new DaewooLanosBuilder();
	client(builder);
	delete builder;

	builder = new FordProbeBuilder();
	client(builder);
	delete builder;

	builder = new UAZPatriotBuilder();
	client(builder);
	delete builder;

	builder = new HyndaiGetzBuilder();
	client(builder);
	delete builder;
	system("pause");
}