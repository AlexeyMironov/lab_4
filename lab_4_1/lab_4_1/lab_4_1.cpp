// lab_4_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <algorithm>
#include <memory>
#include <vector>

#include "Body.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Cylinder.h"
#include "Cone.h"

using namespace std;

shared_ptr<CBody> AddBody();
vector<shared_ptr<CBody>> bodies;

typedef shared_ptr<CBody> CBodyPointer;

CBodyPointer CreateSphere()
{
	double radius, density;
	cout << "Enter radius: "; cin >> radius;
	cout << "Enter density: "; cin >> density;
	return make_shared<CSphere>(radius, density);
}

CBodyPointer CreateParallelepiped()
{
	double width, height, depth, density;
	cout << "Enter width: "; cin >> width;
	cout << "Enter height: "; cin >> height;
	cout << "Enter depth: "; cin >> depth;
	cout << "Enter density: "; cin >> density;
	return make_shared<CParallelepiped>(width, height, depth, density);
}

CBodyPointer CreateCone()
{
	double radius, height, density;
	cout << "Enter radius: "; cin >> radius;
	cout << "Enter height: "; cin >> height;
	cout << "Enter density: "; cin >> density;
	return make_shared<CCone>(radius, height, density);
}

CBodyPointer CreateCylinder()
{
	double radius, height, density;
	cout << "Enter radius: "; cin >> radius;
	cout << "Enter height: "; cin >> height;
	cout << "Enter density: "; cin >> density;
	return make_shared<CCylinder>(radius, height, density);
}


shared_ptr<CBody> AddBody()
{
	string bodyName;
	shared_ptr<CBody> body;

	cin.clear();
	fflush(stdin);
	cout << "Enter body name (cone, cylinder, parallelepiped, sphere, compound)"
		" or empty string to exit" << endl;
	getline(cin, bodyName);

	if (bodyName == "cone")
	{
		body = CreateCone();
	}
	else if (bodyName == "cylinder")
	{
		body = CreateCylinder();
	}
	else if (bodyName == "parallelepiped")
	{
		body = CreateParallelepiped();
	}
	else if (bodyName == "sphere")
	{
		body = CreateSphere();
	}

	else
	{
		if (bodyName.empty())
		{
			return nullptr;
		}
		else
		{
			cout << "Invalid body name" << endl;
			return AddBody();
		}
	}

	return body;
}

bool MassCompareFunct(const shared_ptr<CBody> &a, const shared_ptr<CBody> &b)
{
	return a->GetMass() < b->GetMass();
}

double GetArchimedesForce(const shared_ptr<CBody> &body)
{
	static const double waterDensity = 1000;
	static const double g = 9.81;

	return (body->GetDensity() - waterDensity) * g * body->GetVolume();
}

bool FloatCompareFunct(const shared_ptr<CBody> &a, const shared_ptr<CBody> &b)
{
	return GetArchimedesForce(a) < GetArchimedesForce(b);
}

int main(int argc, char * argv[])
{
	shared_ptr<CBody> body;

	while (body = AddBody())
	{
		bodies.push_back(body);
	}

	if (bodies.empty())
	{
		cout << "You didn't add any bodies" << endl;
		system("PAUSE");
		return 0;
	}

	shared_ptr<CBody> maxMass = *max_element(bodies.begin(), bodies.end(), MassCompareFunct);
	cout << "The body having the greatest mass is:" << endl;
	cout << maxMass->GetInformation() << endl << endl;

	shared_ptr<CBody> lightestInWater = *min_element(bodies.begin(), bodies.end(), FloatCompareFunct);
	cout << "The body which is lightest in water is:" << endl;
	cout << lightestInWater->GetInformation() << endl << endl;

	system("PAUSE");
	return 0;
}


