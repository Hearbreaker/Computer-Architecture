#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_IntrControl[] = {
    120,156,181,80,77,75,195,64,16,157,77,210,168,213,131,87,
    15,66,192,75,16,236,130,146,155,20,81,47,34,168,52,94,
    204,37,108,147,233,23,217,36,100,183,216,120,173,255,91,103,
    210,170,253,3,110,118,223,190,153,44,111,222,76,6,219,229,
    210,185,9,0,204,144,72,78,91,64,1,160,5,36,2,4,
    199,14,20,14,188,110,153,75,204,5,20,48,17,144,123,240,
    9,176,6,120,75,60,200,123,16,135,62,73,204,191,104,133,
    130,152,61,32,136,231,250,121,188,192,204,110,82,12,231,246,
    144,240,161,180,205,93,69,80,21,217,174,151,91,246,114,70,
    4,129,45,80,221,196,1,116,97,225,1,246,96,225,179,193,
    181,3,201,30,140,226,208,161,119,35,6,115,194,234,51,12,
    76,107,44,234,224,29,3,213,96,80,171,198,6,213,36,220,
    231,191,12,105,90,42,141,105,106,251,93,160,171,124,89,112,
    232,241,131,182,70,219,35,242,162,26,165,45,55,19,119,106,
    29,165,36,150,214,178,69,85,182,221,77,181,66,182,253,7,
    230,145,64,150,19,35,151,83,57,171,52,154,139,43,89,203,
    90,149,31,184,154,203,251,42,91,106,82,49,18,51,140,162,
    75,89,168,113,36,167,168,35,105,154,76,102,245,82,238,140,
    101,80,183,93,111,1,11,179,65,95,248,226,41,100,135,246,
    136,64,71,131,223,233,142,224,103,224,148,173,217,191,233,250,
    229,168,169,86,27,161,127,54,219,21,188,222,140,116,120,202,
    5,120,110,199,162,79,223,55,136,94,138,141,
};

EmbeddedPython embedded_m5_objects_IntrControl(
    "m5/objects/IntrControl.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/cpu/IntrControl.py",
    "m5.objects.IntrControl",
    data_m5_objects_IntrControl,
    348,
    623);

} // anonymous namespace