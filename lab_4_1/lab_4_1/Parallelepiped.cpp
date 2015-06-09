#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
	: CSolidBody(density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

CParallelepiped::~CParallelepiped(void)
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return GetWidth() * GetHeight() * GetDepth();
}

std::string CParallelepiped::GetInformation() const
{
	std::ostringstream out;

	out << "Parallelepiped: " << std::endl;
	out << "width: " << m_width << " , height: " << m_height << " , depth: " << m_depth;
	out << " , density: " << GetDensity() << " , volume: " << GetVolume() << " , massa: " << GetMass() << std::endl;

	return out.str();
}