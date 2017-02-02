#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_AlphaTLB[] = {
    120,156,205,88,255,111,219,198,21,127,71,82,180,41,91,177,
    28,127,107,154,108,209,80,4,213,138,54,106,211,101,221,218,
    32,152,211,110,109,135,192,73,169,0,73,180,162,44,77,158,
    36,202,20,73,144,231,36,10,236,95,230,96,219,111,251,35,
    134,253,176,255,99,255,215,246,222,59,146,150,157,100,40,176,
    34,170,32,30,142,119,199,119,239,203,231,125,185,11,160,252,
    53,240,249,93,7,160,184,35,0,66,252,11,136,1,166,2,
    6,2,132,20,16,110,192,65,3,242,95,65,216,128,23,0,
    3,3,164,1,39,216,49,225,79,6,36,171,252,141,13,177,
    201,35,2,102,77,144,22,12,26,240,48,89,7,75,218,112,
    208,132,252,123,16,66,36,2,30,133,75,16,46,195,11,164,
    142,29,135,9,46,67,216,228,142,3,225,10,119,154,48,107,
    131,92,129,1,18,95,130,65,11,73,189,135,164,46,48,169,
    127,19,169,16,103,54,33,108,209,114,228,229,49,173,180,104,
    37,239,113,129,169,172,85,156,181,97,208,174,250,235,48,88,
    135,112,13,100,27,38,23,97,136,226,181,107,26,27,32,77,
    152,108,194,96,19,36,254,55,224,4,53,16,174,243,218,45,
    94,123,177,94,187,205,107,119,96,176,3,18,255,219,122,173,
    13,253,238,22,234,51,250,15,254,186,168,79,80,171,216,60,
    145,121,17,165,137,23,37,195,52,50,104,222,166,134,180,31,
    80,179,84,154,225,115,50,195,191,128,109,16,26,165,25,142,
    1,9,11,226,63,54,224,152,59,199,6,204,186,112,36,96,
    98,65,104,194,17,110,211,32,6,70,2,78,12,248,214,164,
    5,199,216,90,168,184,159,131,165,180,13,38,172,56,77,105,
    9,142,27,112,212,128,254,163,35,131,6,14,28,200,255,9,
    207,175,48,209,101,38,106,192,17,182,22,156,88,112,108,195,
    67,92,132,67,19,135,196,23,143,142,80,82,28,233,119,45,
    228,118,111,78,92,18,37,140,242,196,159,74,181,134,125,47,
    243,115,127,234,237,198,217,216,127,112,247,78,183,89,45,74,
    139,235,153,175,198,46,127,101,146,58,166,153,98,106,105,34,
    213,10,118,134,81,18,122,211,52,60,140,165,90,38,82,222,
    48,138,165,231,241,228,215,211,44,205,213,239,243,60,205,93,
    210,40,15,198,169,95,127,65,250,12,226,180,144,93,218,141,
    183,113,137,188,162,213,195,140,41,18,3,204,41,125,28,202,
    34,200,163,76,161,161,52,69,90,77,212,186,100,34,110,10,
    137,77,47,25,22,189,195,81,111,156,78,101,241,193,199,189,
    172,151,249,201,115,249,44,234,125,145,6,135,83,153,168,162,
    39,3,121,243,230,141,94,236,239,223,236,141,228,244,102,111,
    255,48,138,195,222,238,221,251,95,237,246,178,153,26,167,73,
    15,71,163,68,73,84,85,220,59,171,164,235,184,226,34,109,
    247,52,26,121,17,11,234,141,101,156,201,156,248,44,222,38,
    86,68,91,172,10,91,152,162,43,90,216,107,224,99,138,43,
    198,138,216,139,72,212,128,196,39,144,153,21,172,254,1,108,
    64,180,255,129,1,249,21,2,205,4,255,130,172,140,208,233,
    211,156,193,115,223,144,142,244,232,196,36,40,232,193,35,6,
    26,34,14,87,222,34,219,39,192,104,105,192,196,6,141,34,
    4,159,134,85,62,163,22,151,19,25,3,137,91,80,252,253,
    44,133,164,13,104,3,116,90,28,218,198,173,254,204,192,236,
    119,137,241,61,70,136,26,71,69,250,52,97,59,80,159,93,
    169,143,58,185,63,187,183,63,145,129,42,174,226,192,227,244,
    176,19,248,73,146,170,142,31,134,29,95,169,60,218,63,84,
    178,232,168,180,115,173,232,58,100,248,245,10,100,53,189,89,
    86,129,138,0,128,160,210,47,97,20,40,124,217,224,23,214,
    127,33,21,2,100,156,134,5,142,19,137,145,84,46,49,169,
    46,96,179,91,109,199,72,236,218,21,110,10,25,15,85,147,
    33,232,23,133,199,219,209,56,163,141,190,126,226,199,135,82,
    209,250,66,249,10,119,165,174,222,104,33,120,123,139,36,174,
    4,38,37,122,73,154,132,51,228,55,10,222,33,86,222,98,
    212,173,2,225,110,11,49,183,132,173,13,45,196,96,219,8,
    72,52,171,68,28,163,109,155,20,1,140,0,81,134,18,68,
    222,9,6,156,174,193,17,131,101,100,167,236,80,143,62,118,
    9,216,238,101,106,174,80,243,179,74,13,111,90,23,173,243,
    186,248,144,246,55,88,1,129,89,138,90,59,214,222,25,199,
    186,116,234,88,24,40,251,228,32,6,185,209,169,131,152,164,
    140,252,118,233,13,228,122,8,8,156,158,243,1,86,145,219,
    38,209,237,10,190,46,97,114,30,152,163,57,96,186,100,29,
    70,165,123,233,117,234,188,186,120,117,142,180,58,63,166,253,
    87,75,60,181,24,71,77,17,16,24,140,82,185,172,216,47,
    176,51,219,33,197,206,171,116,7,83,224,195,164,197,185,140,
    243,33,103,124,29,89,180,166,117,199,34,228,13,77,216,46,
    115,84,65,129,32,203,211,103,179,78,58,236,40,168,120,184,
    117,173,184,126,173,248,12,67,69,231,54,7,31,29,44,116,
    56,200,101,150,163,219,59,252,162,93,217,99,183,246,202,52,
    131,170,167,124,207,22,99,133,115,228,42,84,78,1,107,33,
    218,110,214,218,38,230,127,75,155,55,89,213,38,236,224,211,
    20,204,161,151,114,4,229,234,131,103,241,185,67,74,39,185,
    145,89,172,253,220,190,230,159,69,35,33,221,119,207,32,232,
    13,11,230,190,71,44,86,142,104,67,141,23,122,76,98,157,
    124,227,175,192,117,154,128,191,0,97,3,33,80,122,19,251,
    45,61,100,226,13,90,254,29,112,112,122,69,66,52,180,87,
    26,101,248,66,167,45,62,225,165,58,63,254,17,254,54,23,
    217,78,76,16,148,203,204,178,18,155,207,101,86,237,199,12,
    170,31,148,175,172,179,14,79,198,26,251,5,45,211,174,109,
    214,174,125,26,36,235,26,10,227,213,155,198,219,178,222,214,
    35,14,191,60,69,27,37,138,203,98,195,152,195,208,251,212,
    124,80,195,71,84,99,111,144,217,171,231,35,251,92,150,243,
    116,52,253,3,113,100,177,12,107,54,199,91,38,240,117,127,
    215,251,252,222,221,123,123,125,15,105,213,126,211,168,252,230,
    70,237,55,146,35,253,11,46,226,169,53,8,24,39,134,192,
    211,17,86,59,116,48,177,64,54,96,96,147,135,113,149,42,
    74,7,20,85,228,163,136,121,38,141,176,178,246,180,26,107,
    108,104,179,83,243,108,33,145,134,44,127,43,246,167,251,161,
    127,187,79,91,211,254,65,229,146,70,37,76,123,94,24,114,
    39,241,58,121,248,245,195,74,168,39,11,137,50,31,225,78,
    181,48,236,83,97,26,112,104,121,48,150,157,169,156,238,227,
    89,110,28,101,157,97,236,143,216,114,102,41,236,189,74,88,
    197,166,63,159,206,185,36,218,75,59,65,154,96,122,56,12,
    84,154,119,66,137,103,28,25,106,87,56,235,221,92,45,250,
    249,168,224,194,240,224,41,117,23,102,101,15,79,174,17,214,
    197,15,42,197,232,51,85,157,20,184,20,214,126,133,25,22,
    207,41,106,166,163,222,175,169,249,37,53,215,96,145,185,163,
    71,44,208,150,164,76,27,3,147,35,116,249,94,174,185,79,
    95,20,47,123,245,254,15,241,106,125,219,81,250,182,77,43,
    229,18,29,162,169,117,40,123,12,154,213,221,201,10,15,174,
    210,69,69,104,243,200,5,138,2,75,255,111,20,96,175,89,
    152,191,12,126,84,231,119,111,252,36,100,113,185,74,253,95,
    142,47,230,5,109,105,199,159,136,170,168,159,151,146,175,19,
    182,94,194,155,23,228,210,87,82,91,240,237,5,73,205,241,
    69,51,242,109,109,199,74,180,250,144,243,73,45,222,9,23,
    86,179,205,185,130,155,205,42,30,98,21,132,69,249,17,107,
    192,51,116,93,126,138,90,171,86,4,93,109,36,242,169,119,
    86,25,186,236,38,102,252,44,147,73,120,90,82,243,204,66,
    0,65,225,139,202,196,170,166,193,250,121,19,159,151,93,149,
    132,155,147,149,13,218,168,157,115,81,166,101,64,7,149,81,
    187,116,29,119,26,179,93,50,169,142,210,117,128,118,63,173,
    141,180,243,50,90,139,232,185,164,35,220,107,231,176,166,210,
    151,31,248,194,186,99,204,135,50,150,74,158,179,182,162,141,
    203,131,108,40,49,33,166,51,60,89,241,201,4,223,99,207,
    91,92,174,248,13,238,244,152,182,164,4,65,185,194,198,108,
    177,37,28,203,17,156,158,207,93,224,106,30,233,252,173,43,
    240,89,225,114,248,88,171,85,201,55,141,85,90,100,71,162,
    243,228,158,63,213,151,70,124,1,226,254,130,154,119,42,107,
    176,31,232,35,26,159,123,244,9,20,157,134,207,160,92,42,
    184,215,105,156,194,142,22,225,142,95,72,148,128,47,93,245,
    72,63,154,234,123,50,214,107,57,207,169,80,117,224,149,101,
    45,219,35,151,163,168,64,237,48,237,242,171,210,69,73,53,
    234,242,43,172,63,247,217,194,12,167,235,81,125,44,191,77,
    250,42,8,205,116,93,229,172,57,194,54,232,130,212,20,77,
    209,18,150,88,109,57,166,99,59,13,19,141,75,35,27,162,
    105,58,205,85,92,123,9,205,220,52,46,173,56,226,191,71,
    226,141,41,
};

EmbeddedPython embedded_m5_internal_param_AlphaTLB(
    "m5/internal/param_AlphaTLB.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/build/ALPHA/python/m5/internal/param_AlphaTLB.py",
    "m5.internal.param_AlphaTLB",
    data_m5_internal_param_AlphaTLB,
    2083,
    6433);

} // anonymous namespace