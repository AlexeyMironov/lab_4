#include "stdafx.h"
#include "../lab_4_1/Cylinder.h"

struct CylinderFixture
{
	CCylinder cylinder = CCylinder(4, 5, 5700);
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, CylinderFixture)

BOOST_AUTO_TEST_CASE(ConeHasRadius)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), 4);
}

BOOST_AUTO_TEST_CASE(ConeHasHeight)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), 5);
}

BOOST_AUTO_TEST_CASE(ConeHasVolume)
{
	const double EXPECTED_VOLUME = M_PI * pow(cylinder.GetRadius(), 2) * cylinder.GetHeight();
	BOOST_CHECK_EQUAL(cylinder.GetVolume(), EXPECTED_VOLUME);

	CBody & cylinderAsBody = cylinder;
	BOOST_CHECK_EQUAL(cylinderAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(ConeHasMass)
{
	BOOST_CHECK_EQUAL(cylinder.GetMass(), cylinder.GetVolume() * cylinder.GetDensity());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = cylinder.GetInformation();
	std::ostringstream out;

	out << "Cylinder: " << std::endl;
	out << "Radius: " << cylinder.GetRadius() << " , height: " << cylinder.GetHeight() << " , density: " << cylinder.GetDensity();
	out << " , volume: " << cylinder.GetVolume() << " , massa: " << cylinder.GetMass() << std::endl;

	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();