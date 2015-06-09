#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double radius, double height, double density)
	: CSolidBody(density)
	, m_radius(radius)
	, m_height(height)
{
}

CCone::~CCone()
{
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return ((M_PI * pow(m_radius, 2) * m_height) / 3);
}

std::string CCone::GetInformation() const
{
	std::ostringstream out;

	out << "Cone: " << std::endl;
	out << "Radius: " << m_radius << " , height: " << m_height << " , density: " << GetDensity();
	out  << " , volume: " << GetVolume() << " , massa: " << GetMass() << std::endl;

	return out.str();
}