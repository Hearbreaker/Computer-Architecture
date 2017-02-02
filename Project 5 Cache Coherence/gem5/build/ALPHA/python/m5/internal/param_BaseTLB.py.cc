#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BaseTLB[] = {
    120,156,205,88,109,143,219,198,17,158,37,41,222,81,119,242,
    201,190,243,57,118,156,88,69,96,84,13,26,43,117,234,164,
    69,13,163,118,156,180,9,130,139,67,5,176,173,4,97,120,
    228,74,162,142,34,5,238,158,109,5,119,95,114,70,154,111,
    249,17,69,63,228,127,228,127,37,51,179,36,79,186,52,69,
    128,22,86,5,113,177,92,46,119,231,229,121,102,102,25,65,
    249,107,224,245,215,14,128,122,91,0,196,248,23,144,2,76,
    5,12,4,8,41,32,222,134,131,6,20,127,132,184,1,207,
    1,6,22,72,11,78,176,99,195,103,22,100,155,252,142,11,
    169,205,35,2,230,77,144,14,12,26,240,48,59,15,142,116,
    225,160,9,197,151,32,132,200,4,60,138,215,32,94,135,231,
    184,58,118,60,94,112,29,226,38,119,60,136,55,184,211,132,
    121,27,228,6,12,112,241,53,24,180,112,169,215,113,169,115,
    188,212,15,180,84,140,79,118,32,110,209,116,148,229,49,205,
    116,104,38,239,113,142,87,217,170,36,107,195,160,13,241,22,
    200,54,76,206,195,16,85,106,215,239,93,0,105,195,100,27,
    6,219,32,241,127,1,78,80,235,248,60,207,221,225,185,23,
    234,185,23,121,238,46,12,118,65,226,255,162,153,235,66,191,
    123,17,109,152,252,136,191,46,218,16,244,38,54,79,100,161,
    146,60,11,146,108,152,39,22,61,119,169,33,139,71,212,172,
    149,166,127,151,76,255,61,176,221,99,171,52,253,49,224,194,
    130,228,79,45,56,230,206,177,5,243,46,28,9,152,56,16,
    219,112,132,219,52,72,128,145,128,19,11,62,183,105,194,49,
    182,14,26,235,85,112,180,177,251,132,141,101,86,90,131,227,
    6,28,53,160,255,232,200,162,129,3,15,138,127,193,87,87,
    121,209,117,94,212,130,35,108,29,56,113,224,216,133,135,56,
    9,135,38,30,169,47,30,29,161,166,56,210,239,58,40,237,
    222,130,186,164,74,156,20,89,56,149,250,28,246,131,89,88,
    132,211,224,94,168,228,167,31,221,235,54,171,57,185,186,49,
    11,245,216,231,151,108,178,198,116,166,121,177,60,147,122,3,
    59,195,36,139,131,105,30,31,166,82,175,211,74,193,48,73,
    101,16,240,195,15,166,179,188,208,239,21,69,94,248,100,80,
    30,76,243,176,126,131,204,25,165,185,146,93,218,141,183,241,
    105,121,77,179,135,51,94,145,4,96,65,233,229,88,170,168,
    72,102,26,253,100,86,164,217,180,90,151,60,196,141,66,141,
    161,151,13,85,239,112,212,27,231,83,169,222,120,171,55,235,
    205,194,236,43,249,44,233,221,207,163,195,169,204,180,234,201,
    72,222,186,117,179,151,134,251,183,122,35,57,189,213,219,63,
    76,210,184,119,247,163,7,127,191,219,155,205,245,56,207,122,
    56,154,100,90,162,165,210,222,146,141,110,224,132,11,180,219,
    211,100,20,36,172,103,48,150,233,76,22,36,166,186,66,146,
    136,182,216,20,174,176,69,87,180,176,215,192,203,22,87,173,
    13,177,151,144,166,17,105,79,16,179,43,80,253,19,216,125,
    232,253,3,11,138,171,4,153,9,254,5,249,24,129,211,167,
    103,22,63,251,132,76,100,70,39,54,1,193,12,30,49,204,
    16,111,56,243,54,121,62,3,198,74,3,38,46,24,12,33,
    244,12,168,138,57,181,56,157,150,177,112,113,7,212,119,203,
    43,100,109,64,23,32,77,113,104,23,183,250,154,97,217,239,
    146,224,123,12,16,61,78,84,254,52,99,55,80,159,137,212,
    71,155,60,152,127,188,63,145,145,86,215,112,224,113,126,216,
    137,194,44,203,117,39,140,227,78,168,117,145,236,31,106,169,
    58,58,239,92,87,93,143,252,126,190,194,88,189,222,124,86,
    97,138,252,143,152,50,55,113,18,105,188,217,230,27,182,191,
    146,26,241,49,206,99,133,227,180,196,72,106,159,132,100,112,
    223,173,182,99,32,118,221,10,54,74,166,67,221,100,4,134,
    74,5,188,29,141,51,216,232,237,39,97,122,40,53,205,87,
    58,212,184,43,117,205,70,171,128,219,75,164,112,165,47,217,
    48,200,242,44,158,163,184,73,244,26,73,242,18,131,110,19,
    8,118,23,17,114,107,216,186,208,66,8,182,173,136,52,115,
    74,192,49,216,118,201,14,192,0,16,101,28,65,224,157,96,
    180,233,90,28,46,88,69,166,100,135,122,244,178,79,184,246,
    95,166,230,42,53,175,84,86,120,193,166,104,157,53,197,155,
    180,189,197,250,71,118,169,105,77,171,189,37,90,93,62,165,
    21,6,201,62,209,195,34,18,157,210,195,38,91,20,119,74,
    46,16,241,16,14,248,120,129,1,108,33,191,77,154,187,21,
    120,125,66,228,34,44,71,11,176,244,201,57,140,73,255,242,
    47,89,243,218,202,173,57,50,214,124,139,182,223,44,209,212,
    98,20,53,69,68,80,176,74,219,178,93,239,99,103,126,137,
    236,186,104,209,75,152,253,30,102,45,78,99,156,10,57,193,
    155,176,98,12,109,58,14,225,110,104,195,110,153,158,20,69,
    129,89,145,63,155,119,242,97,71,67,37,195,237,235,234,198,
    117,245,23,140,19,157,59,28,121,76,164,48,177,160,144,179,
    2,57,239,241,141,225,113,192,156,14,202,20,131,150,167,84,
    207,14,99,123,115,216,82,186,160,104,181,10,99,55,107,99,
    147,236,127,166,189,155,108,105,27,46,225,213,20,44,96,144,
    115,244,228,186,131,159,226,117,143,108,78,106,75,160,74,207,
    239,27,241,89,51,210,209,255,237,18,126,94,172,94,254,235,
    36,97,197,66,23,106,180,208,101,147,228,68,140,127,0,23,
    104,2,190,1,66,6,2,160,164,18,147,150,46,114,240,54,
    77,255,2,56,48,253,155,92,104,25,74,90,101,232,66,198,
    170,119,120,170,73,141,31,194,183,11,81,237,196,6,65,105,
    204,46,75,176,197,52,230,212,36,102,72,253,170,84,229,44,
    179,157,124,53,14,21,77,51,188,182,107,94,159,6,200,186,
    122,194,96,245,130,209,182,110,118,13,72,192,191,157,98,141,
    114,196,203,98,219,90,64,208,239,169,121,163,6,143,168,198,
    94,156,172,215,206,6,245,133,252,22,152,64,250,62,9,228,
    176,10,91,46,27,191,124,191,38,74,163,34,202,205,154,40,
    146,3,251,115,174,215,169,181,8,10,39,150,192,195,15,150,
    54,116,238,112,64,54,96,224,18,165,184,34,21,37,227,68,
    21,233,40,66,46,101,13,182,207,158,177,92,141,6,227,104,
    106,158,173,34,178,144,175,111,167,225,116,63,14,239,248,180,
    51,109,31,85,28,180,42,93,218,139,186,16,127,196,47,169,
    195,183,111,86,58,61,89,69,84,249,3,137,80,233,194,28,
    138,243,136,67,201,167,99,217,153,202,233,62,30,218,198,201,
    172,51,76,195,17,251,205,46,117,253,184,210,85,179,227,207,
    230,110,46,127,246,242,78,148,103,152,12,14,35,157,23,157,
    88,226,105,70,198,6,251,203,108,230,194,48,44,70,138,107,
    192,131,167,212,93,149,143,3,60,161,38,88,1,247,43,187,
    152,195,83,157,2,204,137,142,137,132,233,20,79,36,122,110,
    130,220,219,212,252,142,154,235,176,194,76,209,195,141,62,161,
    29,201,148,46,198,33,79,112,9,82,78,121,64,243,213,207,
    9,125,255,215,16,218,124,199,40,105,237,130,92,163,115,50,
    125,166,104,148,159,41,144,226,238,127,75,113,230,196,170,216,
    240,248,127,202,108,255,230,255,131,42,62,23,156,255,137,213,
    22,44,212,243,239,24,86,27,63,97,25,49,223,89,40,46,
    89,109,241,16,115,62,22,160,71,92,154,6,150,169,65,79,
    157,202,89,156,191,31,144,77,50,249,52,88,2,159,169,48,
    9,39,225,108,38,179,248,180,122,228,39,171,176,23,113,247,
    51,56,77,224,88,42,238,224,245,115,28,147,106,11,154,50,
    94,27,53,114,175,172,208,221,95,214,241,106,99,41,94,249,
    228,79,19,161,234,224,100,98,21,123,104,135,20,146,169,212,
    114,217,73,154,222,40,79,90,177,196,32,158,207,177,246,231,
    226,25,239,211,32,88,89,128,251,19,110,244,168,242,21,5,
    56,87,120,142,39,56,155,156,249,176,104,196,187,4,85,129,
    56,87,62,19,98,171,86,159,63,129,85,97,156,145,79,135,
    157,189,112,106,62,103,240,217,220,255,13,53,175,85,22,100,
    228,154,3,4,151,229,230,120,132,40,231,3,18,103,54,255,
    6,141,211,46,70,250,126,50,53,223,107,120,110,125,199,177,
    154,61,80,170,199,230,46,228,40,81,168,60,191,95,207,45,
    169,67,202,235,43,112,38,156,47,189,183,42,199,152,10,201,
    156,11,239,144,158,138,132,165,175,37,222,150,39,92,139,62,
    207,217,162,41,90,194,17,155,45,207,246,92,175,97,163,243,
    104,100,91,52,109,175,185,41,46,163,35,155,214,101,207,19,
    63,1,162,79,38,113,
};

EmbeddedPython embedded_m5_internal_param_BaseTLB(
    "m5/internal/param_BaseTLB.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/build/ALPHA/python/m5/internal/param_BaseTLB.py",
    "m5.internal.param_BaseTLB",
    data_m5_internal_param_BaseTLB,
    1974,
    6031);

} // anonymous namespace