#pragma once
#include "SolidBody.h"

class CParallelepiped final :
	public CSolidBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);
	~CParallelepiped(void);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;

	// методы, переопредел€ющие методы базовых классов, рекомендуетс€ 
	// объ€вл€ть со спецификатором override

	virtual double GetVolume() const override;
	virtual std::string GetInformation() const override;

private:
	double m_width, m_height, m_depth;
};

