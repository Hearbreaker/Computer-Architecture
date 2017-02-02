#ifndef __PARAMS__OpDesc__
#define __PARAMS__OpDesc__

class OpDesc;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/OpClass.hh"

#include "params/SimObject.hh"

#include "enums/OpClass.hh"

struct OpDescParams
    : public SimObjectParams
{
    OpDesc * create();
    int issueLat;
    int opLat;
    Enums::OpClass opClass;
};

#endif // __PARAMS__OpDesc__
