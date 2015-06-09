#pragma once
#include "SolidBody.h"

class CSphere final : 
	public CSolidBody
{
public:
	CSphere(double radius, double density);
	~CSphere(void);

	double GetRadius() const;

	// методы, переопредел€ющие методы базовых классов, рекомендуетс€ 
	// объ€вл€ть со спецификатором override

	double GetVolume() const override final;
	std::string GetInformation() const override;

private:
	double m_radius;
};

