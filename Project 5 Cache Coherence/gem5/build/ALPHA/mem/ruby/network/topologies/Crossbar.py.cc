#include "sim/init.hh"

namespace {

const uint8_t data_Crossbar[] = {
    120,156,189,83,205,110,211,64,16,158,181,227,252,81,113,0,
    65,85,33,164,72,92,44,4,93,9,20,113,65,8,104,122,
    64,160,30,146,94,136,40,198,63,219,212,77,188,27,188,27,
    145,160,228,84,30,137,215,226,25,96,102,98,55,192,3,212,
    178,199,223,120,119,230,155,217,111,156,66,117,249,248,188,238,
    1,216,23,8,50,188,5,204,0,78,43,36,16,121,160,60,
    56,23,144,249,240,3,224,10,224,227,216,135,172,65,206,184,
    1,89,0,163,176,137,177,249,111,188,66,129,200,145,121,236,
    218,104,143,74,99,109,18,151,105,77,71,75,111,137,238,54,
    2,133,25,4,145,142,61,24,142,56,118,72,38,164,162,56,
    62,138,116,92,168,40,114,93,118,10,147,45,102,228,222,162,
    98,149,77,203,124,238,114,163,67,74,189,51,246,11,26,169,
    207,173,92,76,228,133,41,148,125,250,92,206,229,60,214,223,
    213,50,151,3,147,46,10,165,157,149,42,85,253,254,51,57,
    139,147,190,156,168,162,47,109,153,202,66,21,178,92,36,43,
    169,149,251,102,202,169,116,102,110,102,102,146,43,43,235,126,
    14,231,43,174,180,71,108,30,154,166,72,3,124,117,171,231,
    136,90,252,69,93,240,137,109,2,152,240,185,56,15,214,248,
    69,208,225,238,227,107,112,118,15,54,77,88,227,57,226,74,
    19,247,138,207,30,124,237,193,58,128,200,231,160,70,21,49,
    56,59,132,79,30,237,222,180,96,237,147,28,24,128,58,172,
    91,36,2,6,92,242,151,131,43,240,41,199,123,206,17,236,
    40,55,237,106,211,245,151,131,77,231,255,186,152,232,9,215,
    228,49,69,155,114,238,103,205,191,8,50,228,239,64,69,243,
    147,105,120,121,20,146,100,39,57,207,64,7,77,105,22,78,
    149,81,158,185,22,122,179,92,79,9,211,38,181,116,145,54,
    153,98,39,215,149,67,99,68,32,138,119,48,9,91,245,88,
    56,58,225,50,214,19,229,104,64,102,40,97,235,154,197,50,
    163,210,168,108,25,59,181,245,144,133,88,183,107,68,195,94,
    216,173,147,17,131,229,36,134,231,104,139,223,105,247,1,247,
    49,62,94,110,49,213,51,100,34,71,114,167,9,15,121,206,
    86,243,116,114,123,169,89,104,135,146,1,44,113,74,110,120,
    34,221,30,146,20,241,84,157,110,151,87,143,136,249,14,241,
    7,29,209,23,190,120,35,246,196,93,225,123,199,226,36,12,
    106,149,138,254,225,60,46,227,194,114,27,232,153,228,82,165,
    206,178,54,117,42,22,96,248,224,159,223,236,6,59,163,82,
    94,110,255,254,87,15,137,149,244,232,138,174,119,223,255,3,
    79,190,23,218,
};

EmbeddedPython embedded_Crossbar(
    "Crossbar.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/ruby/network/topologies/Crossbar.py",
    "Crossbar",
    data_Crossbar,
    596,
    1226);

} // anonymous namespace