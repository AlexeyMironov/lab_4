#include "stdafx.h"
#include "Compound.h"
#include <numeric>

using namespace std;

CCompound::CCompound(void)
{
}

CCompound::~CCompound(void)
{
}

bool CCompound::AddBody(const shared_ptr<CBody> &body)
{
	if (this == body.get())
		return false;

	shared_ptr<CCompound> bodyAsCompound = dynamic_pointer_cast<CCompound>(body);

	if (bodyAsCompound.get() != nullptr)
	{
		if (bodyAsCompound->HasBodyInside(this))
		{
			return false;
		}
	}

	m_contents.push_back(body);
	return true;
}

size_t CCompound::GetContentsCount() const
{
	return m_contents.size();
}

double CCompound::GetVolume() const
{
	return accumulate(m_contents.cbegin(), m_contents.cend(), 0.0,
		[](double sum, const shared_ptr<CBody> &body){ return sum + body->GetVolume(); });
}

double CCompound::GetMass() const
{
	return accumulate(m_contents.cbegin(), m_contents.cend(), 0.0,
		[](double sum, const shared_ptr<CBody> &body){ return sum + body->GetMass(); });
}

double CCompound::GetDensity() const
{
	return (GetMass() / GetVolume());
}

bool CCompound::HasBodyInside(const CBody *body) const
{
	for (auto & curBody : m_contents)
	{
		if (body == curBody.get())
		{
			return true;
		}

		shared_ptr<CCompound> curBodyAsCompound = dynamic_pointer_cast<CCompound>(curBody);
		if (curBodyAsCompound)
		{
			if (curBodyAsCompound->HasBodyInside(body))
			{
				return true;
			}
		}
	}

	return false;
}

string CCompound::GetInformation() const
{
	ostringstream out;
	out << "Compound: " << endl;
	out << "Density: " << GetDensity() << ", mass: " << GetMass() << ", volume: " << GetVolume();
	return out.str();
}


