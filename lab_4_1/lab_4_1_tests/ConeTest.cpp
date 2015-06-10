#include "stdafx.h"
#include "../lab_4_1/Cone.h"

struct ConeFixture
{
	CCone cone = CCone(4, 5, 5700);
};

BOOST_FIXTURE_TEST_SUITE(Cone, ConeFixture)

BOOST_AUTO_TEST_CASE(ConeHasRadius)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), 4);
}

BOOST_AUTO_TEST_CASE(ConeHasHeight)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), 5);
}

BOOST_AUTO_TEST_CASE(ConeHasVolume)
{
	const double EXPECTED_VOLUME = (M_PI * pow(cone.GetRadius(), 2) * cone.GetHeight()) / 3;
	BOOST_CHECK_EQUAL(cone.GetVolume(), EXPECTED_VOLUME);

	CBody & coneAsBody = cone;
	BOOST_CHECK_EQUAL(coneAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(ConeHasMass)
{
	BOOST_CHECK_EQUAL(cone.GetMass(), cone.GetVolume() * cone.GetDensity());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = cone.GetInformation();
	std::ostringstream out;

	out << "Cone: " << std::endl;
	out << "Radius: " << cone.GetRadius() << " , height: " << cone.GetHeight() << " , density: " << cone.GetDensity();
	out << " , volume: " << cone.GetVolume() << " , massa: " << cone.GetMass() << std::endl;

	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();