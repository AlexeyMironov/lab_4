#include "stdafx.h"
#include "../lab_4_1/Parallelepiped.h"

struct ParallelepipedFixture
{
	CParallelepiped parallelepiped = CParallelepiped(3, 5, 6, 5700);
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(ParallelepipedHasWidth)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), 3);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasHeight)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), 5);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasDepth)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), 6);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasDensity)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetDensity(), 5700);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasVolume)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetVolume(), 3 * 5 * 6);

	CBody & parallelepipedAsBody = parallelepiped;
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetVolume(), 3 * 5 * 6);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasMass)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetMass(), parallelepiped.GetDensity() * parallelepiped.GetVolume());
}

BOOST_AUTO_TEST_CASE(HasInformation)
{
	const std::string info = parallelepiped.GetInformation();
	std::ostringstream out;

	out << "Parallelepiped: " << std::endl;
	out << "width: " << parallelepiped.GetWidth() << " , height: " << parallelepiped.GetHeight() << " , depth: " << parallelepiped.GetDepth();
	out << " , density: " << parallelepiped.GetDensity() << " , volume: " << parallelepiped.GetVolume() << " , massa: " << parallelepiped.GetMass() << std::endl;

	BOOST_CHECK_EQUAL(out.str(), info);
}

BOOST_AUTO_TEST_SUITE_END();