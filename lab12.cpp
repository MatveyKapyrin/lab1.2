#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Car {
public:
	Car(const std::string& _company, const std::string& _model):
		comp(_company),
		mod(_model) {}

	virtual ~Car() {
		std::cout << "Car{company=" << comp << "," << "model=" << mod << "}\n";
	}

private:
	const std::string comp;
	const std::string mod;
};

class Mercedes:public Car {
public:
	Mercedes(const std::string& model) :Car("Mercedes",model) {}
	~Mercedes() = default;
};

class Audi: public Car {
public:
	Audi(const std::string& model) : Car("Audi",model) {}
	~Audi() = default;
};

class Bmw: public Car {
public:
	Bmw(const std::string& model) :Car("Bmw",model) {}
	~Bmw() = default;
};

class Kia : public Car {
public:
	Kia(const std::string& model) :Car("Kia",model) {}
	~Kia() = default;
};

int main() {
	std::ifstream file("cars.txt");

	std::vector<Car*> base;
	std::string company, model;

	while (file >> company >> model) {
		if (company == "Mercedes") {
			base.push_back(new Mercedes(model));
		}
		else if (company == "Bmw") {
			base.push_back(new Bmw(model));
		}
		else if (company == "Audi") {
			base.push_back(new Audi(model));
		}
		else if (company == "Kia") {
			base.push_back(new Kia(model));
		}
	}

	for (const Car* car : base) {
		delete car;
	}
}
