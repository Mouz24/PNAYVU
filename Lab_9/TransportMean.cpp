#include "TransportMean.h"
#include <iostream>

using namespace std;
using namespace transporting;

MeanofTransport::MeanofTransport(string _name)
{
	name = _name;
}

string MeanofTransport::GetName()
{
	return name;
}
