#pragma once
#include "Body.h"
#include <vector>

class CCompound final :
	public CBody
{
public:
	CCompound();
	~CCompound();

	bool AddBody(const std::shared_ptr<CBody> &body);

	size_t GetContentsCount() const;

	virtual double GetVolume() const override;
	virtual double GetDensity() const override;
	virtual double GetMass() const override;
	virtual std::string GetInformation() const override;

private:
	std::vector<std::shared_ptr<CBody>> m_contents;

	bool HasBodyInside(const CBody *body) const;
};
