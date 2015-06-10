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
	if (m_contents.size() == 0)
		throw runtime_error("Empty body has no density");

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
	out << "Number of bodies in compount body: " << m_contents.size() << endl;
	out << "Massa " << GetMass() << ", volume " << GetVolume() << " , density " << GetDensity() << endl;

	out << "Contents:" << endl;
	for (auto body : m_contents)
		out << body->GetInformation() << endl;

	return out.str();
}
