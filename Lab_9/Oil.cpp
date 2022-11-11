#include "Oil.h"
#include <iostream>

using namespace std;
using namespace transporting;

Oil::Oil(int _volume)
{
	volume = _volume;
}

int Oil::GetVolume()
{
	return volume;
}