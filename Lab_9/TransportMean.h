#pragma once
#include <iostream>

using namespace std;

namespace transporting
{
	class MeanofTransport
	{
	protected:
		string name;

	public:
		MeanofTransport() {}

		MeanofTransport(string _name);

		string GetName();

		~MeanofTransport() {}
	};
}
