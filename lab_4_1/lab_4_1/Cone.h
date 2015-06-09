#pragma once
#include "SolidBody.h"

class CCone final :
	public CSolidBody
{
public:
	CCone(double radius, double height, double density);
	~CCone();

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetInformation() const override;

private:
	double m_radius;
	double m_height;
};
