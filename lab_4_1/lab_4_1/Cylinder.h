#pragma once
#include "SolidBody.h"

class CCylinder final :
	public CSolidBody
{
public:
	CCylinder(double radius, double height, double density);
	~CCylinder();

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetInformation() const override;

private:
	double m_radius;
	double m_height;
};

