#include "stdafx.h"
//AddBody

#include "../lab_4_1/Sphere.h"
#include "../lab_4_1/Parallelepiped.h"
#include "../lab_4_1/Cone.h"
#include "../lab_4_1/Cylinder.h"
#include "../lab_4_1/Compound.h"

using namespace std;

struct CompoundFixture
{
	CSphere sphere = CSphere(5, 1025);
	CParallelepiped parallelepiped = CParallelepiped(2, 3, 4, 8920);
	CCone cone = CCone(2, 3, 5023);
	CCylinder cylinder = CCylinder(2, 3, 8920);
	CCompound compound;
};

BOOST_FIXTURE_TEST_SUITE(Compound, CompoundFixture)

BOOST_AUTO_TEST_CASE(AddBody)
{
	compound.AddBody(make_shared<CSphere>(sphere));
	BOOST_CHECK_EQUAL(compound.GetVolume(), sphere.GetVolume());
	BOOST_CHECK_EQUAL(compound.GetDensity(), sphere.GetDensity());
	BOOST_CHECK_EQUAL(compound.GetMass(), sphere.GetMass());
}

BOOST_AUTO_TEST_CASE(AddBodies)
{
	compound.AddBody(make_shared<CSphere>(sphere));
	compound.AddBody(make_shared<CParallelepiped>(parallelepiped));
	compound.AddBody(make_shared<CCone>(cone));
	compound.AddBody(make_shared<CCylinder>(cylinder));

	double mass = sphere.GetMass() + parallelepiped.GetMass() + cylinder.GetMass() + cone.GetMass();
	double volume = sphere.GetVolume() + parallelepiped.GetVolume() + cylinder.GetVolume() + cone.GetVolume();

	BOOST_CHECK_EQUAL(compound.GetVolume(), volume);
	BOOST_CHECK_EQUAL(compound.GetDensity(), mass / volume);
	BOOST_CHECK_EQUAL(compound.GetMass(), mass);
}

BOOST_AUTO_TEST_CASE(AddCompoundInCompound)
{
	shared_ptr<CCompound> compound(new CCompound());
	BOOST_CHECK_EQUAL(compound->AddBody(compound), false);
}

BOOST_AUTO_TEST_CASE(AddCompoundToItselfChained)
{
	shared_ptr<CCompound> compound1(new CCompound());
	shared_ptr<CCompound> compound2(new CCompound());

	compound2->AddBody(shared_ptr<CParallelepiped>(new CParallelepiped(10, 3.6, 6, 40)));
	BOOST_CHECK_EQUAL(compound1->AddBody(compound2), true);
	BOOST_CHECK_EQUAL(compound2->AddBody(compound1), false);
}


BOOST_AUTO_TEST_CASE(HasInformation)
{
	const string info = compound.GetInformation();
	ostringstream out;
	out << "Compound: " << endl;
	out << "Density: " << compound.GetDensity() << ", mass: " << compound.GetMass() << ", volume: " << compound.GetVolume();

	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();

