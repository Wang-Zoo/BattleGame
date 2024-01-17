#include "output.h"

COutput::COutput()
{

}

COutput& COutput::getInstance()
{
	static COutput instance;
	return instance;
}
