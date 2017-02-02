#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Sinic[] = {
    120,156,197,89,109,115,219,198,17,222,3,95,100,82,162,245,
    46,89,47,182,104,43,78,24,55,54,29,167,110,250,226,241,
    212,177,211,36,157,68,118,169,206,216,65,59,65,32,224,72,
    66,34,1,14,112,146,77,87,250,82,121,218,126,235,143,232,
    228,67,255,71,127,65,255,80,187,187,199,3,65,42,146,61,
    211,142,36,145,55,199,189,189,189,219,221,103,119,239,0,15,
    6,127,5,252,254,186,10,144,252,91,0,248,248,17,208,1,
    232,10,176,5,8,41,192,159,135,189,2,196,63,5,191,0,
    111,0,108,11,164,5,199,216,201,193,31,44,8,167,120,78,
    17,58,57,166,8,232,151,65,230,193,46,192,243,112,22,242,
    178,8,123,101,136,191,7,33,68,40,224,133,63,1,254,37,
    120,131,210,177,83,98,129,151,192,47,115,167,4,254,36,119,
    202,208,159,1,57,9,54,10,159,0,187,130,162,110,161,168,
    203,44,234,95,36,202,199,145,5,240,43,196,142,123,249,150,
    56,243,196,201,107,92,102,41,211,102,103,51,96,207,152,254,
    44,216,179,166,63,7,246,156,233,207,131,61,111,250,11,96,
    47,152,254,34,216,139,166,191,4,246,146,233,47,131,189,108,
    250,87,192,190,98,250,43,96,175,152,254,42,216,171,166,191,
    6,246,154,233,175,131,189,110,250,87,193,190,10,254,52,200,
    25,216,189,6,77,52,247,76,170,211,6,200,28,236,86,193,
    174,130,196,207,6,28,163,71,252,89,230,189,206,188,115,41,
    239,13,230,221,4,123,19,36,126,110,104,222,34,108,215,22,
    209,191,193,127,240,175,134,254,5,53,133,205,129,140,147,32,
    10,157,32,108,70,129,69,227,69,106,8,13,30,53,19,3,
    88,60,38,88,252,19,24,19,190,53,128,197,17,160,96,65,
    251,239,88,112,196,157,35,11,250,53,56,20,176,155,7,63,
    7,135,184,76,129,54,208,18,112,108,193,31,115,196,112,132,
    109,30,29,121,13,242,74,99,98,151,29,169,37,77,192,81,
    1,14,11,176,253,226,208,34,194,94,9,226,31,224,245,58,
    11,189,196,66,45,56,196,54,15,199,121,56,42,194,115,100,
    66,210,110,137,212,23,47,14,81,83,164,108,215,242,184,219,
    173,140,186,164,138,31,196,161,219,149,172,186,211,115,99,183,
    235,108,7,97,224,213,202,134,35,74,238,244,92,213,110,240,
    148,28,217,162,219,83,44,42,10,165,154,196,78,51,8,125,
    167,27,249,251,29,169,46,145,28,167,25,116,164,227,240,224,
    87,221,94,20,171,207,227,56,138,27,100,78,38,118,34,55,
    157,65,198,244,58,81,34,107,180,26,47,211,32,241,138,184,
    155,61,150,72,27,224,109,210,100,95,38,94,28,244,20,122,
    73,75,36,110,146,86,35,255,112,147,236,96,83,15,155,73,
    125,191,85,111,71,93,153,220,254,164,222,171,247,220,240,181,
    124,21,212,159,68,222,126,87,134,42,169,75,79,222,191,127,
    175,222,113,119,238,215,91,178,123,191,190,179,31,116,252,250,
    163,175,159,125,249,168,222,235,171,118,20,214,145,26,132,74,
    162,157,58,245,140,133,238,224,240,28,173,245,50,104,57,1,
    107,233,180,101,167,39,99,218,100,178,74,251,16,51,98,74,
    20,69,78,212,68,5,123,5,252,230,196,186,53,41,182,2,
    210,211,35,221,9,94,57,3,168,127,0,187,14,61,191,103,
    65,188,78,112,217,197,143,32,255,34,104,182,105,204,226,177,
    223,145,129,52,117,55,71,32,208,196,67,134,24,98,13,57,
    31,144,215,67,96,156,20,96,183,8,26,63,8,59,13,168,
    184,79,45,178,147,24,11,133,231,33,249,251,168,132,112,6,
    208,1,152,62,144,180,132,75,253,153,33,185,93,163,141,111,
    49,60,84,59,72,162,151,33,59,129,250,140,164,109,180,201,
    179,254,211,157,93,233,169,100,3,9,223,70,251,85,207,13,
    195,72,85,93,223,175,186,74,197,193,206,190,146,73,85,69,
    213,155,73,173,68,94,159,53,8,75,229,245,123,6,81,228,
    125,68,148,254,225,7,158,194,31,243,252,131,237,159,72,133,
    232,104,71,126,130,116,18,209,146,170,65,155,84,151,177,121,
    100,150,99,24,214,138,6,52,137,236,52,85,153,241,231,38,
    137,195,203,17,157,161,70,179,15,220,206,190,84,196,159,40,
    87,225,170,212,213,11,157,63,216,174,144,186,70,91,178,160,
    19,70,161,223,199,205,6,222,38,237,227,10,67,110,10,8,
    116,139,8,184,9,108,139,80,65,0,206,88,30,233,149,31,
    192,141,161,182,68,86,0,118,191,24,100,16,132,221,49,230,
    153,154,197,137,130,21,228,112,172,82,143,38,55,8,213,141,
    53,106,214,169,185,106,108,112,174,134,168,140,27,226,46,45,
    110,177,246,94,110,160,103,26,82,91,35,33,181,50,12,41,
    76,142,219,20,26,22,5,208,48,52,114,100,137,248,225,32,
    14,40,232,16,10,56,156,65,63,219,167,49,67,122,23,13,
    112,27,132,198,44,36,91,25,72,54,200,53,140,199,198,202,
    105,182,220,184,96,91,182,180,45,63,161,197,167,6,72,170,
    48,130,202,194,35,24,88,3,203,178,85,159,96,167,191,76,
    86,205,218,115,25,107,222,243,176,194,197,139,11,32,31,57,
    116,66,209,102,214,157,60,97,174,153,131,165,65,81,74,40,
    254,123,113,244,170,95,141,154,85,5,102,15,15,110,38,119,
    110,38,191,194,12,81,125,200,57,71,231,8,157,5,98,217,
    139,49,218,75,252,67,71,176,195,209,236,12,74,11,218,157,
    10,60,187,139,173,205,9,43,81,49,229,169,243,55,117,57,
    53,53,237,252,23,180,114,153,237,156,131,101,252,150,5,111,
    207,137,56,107,242,89,131,71,241,251,25,89,156,148,150,64,
    39,207,198,182,222,60,235,69,26,54,62,24,193,206,121,106,
    213,184,69,251,51,241,87,132,20,41,244,205,209,190,41,36,
    254,10,124,36,19,240,23,32,84,160,243,7,65,196,225,74,
    95,114,238,60,177,127,7,156,144,126,164,2,90,58,24,173,
    65,202,194,88,77,62,101,86,93,16,127,11,127,203,100,179,
    227,28,8,42,94,185,193,161,43,91,188,242,105,248,50,156,
    222,169,64,229,71,227,156,60,213,118,19,98,211,17,157,75,
    35,122,152,24,211,19,19,166,169,115,69,218,37,189,166,67,
    219,251,98,136,51,170,12,107,98,222,202,160,231,35,106,110,
    167,192,17,134,118,94,59,221,24,79,229,153,154,230,232,244,
    249,27,218,78,158,21,152,46,114,130,229,217,206,227,167,95,
    63,221,218,118,158,200,131,192,147,105,184,20,76,184,220,75,
    195,69,114,106,127,195,39,117,106,45,130,196,177,37,240,74,
    134,7,27,186,13,229,65,22,192,46,82,96,241,105,84,12,
    226,78,152,108,71,89,114,164,110,176,165,182,180,13,83,84,
    104,135,83,243,234,252,179,11,249,252,65,199,237,238,248,238,
    67,135,214,165,197,61,19,137,150,209,100,38,171,9,69,145,
    56,77,25,254,121,215,104,116,112,254,153,229,99,194,134,209,
    132,227,200,143,60,78,39,191,111,203,106,87,118,119,240,170,
    214,14,122,213,102,199,109,177,207,114,3,77,159,26,77,21,
    59,125,188,114,243,209,103,43,170,122,81,136,197,96,223,83,
    81,92,245,37,222,98,164,175,35,96,52,162,249,72,232,198,
    173,132,79,127,123,47,169,123,49,254,117,240,86,26,224,201,
    247,123,99,21,125,101,74,75,0,31,118,117,56,97,49,197,
    155,136,234,235,52,247,51,106,62,164,230,38,92,88,165,168,
    227,50,148,221,19,50,99,17,51,81,73,240,125,142,25,158,
    17,111,114,50,140,191,19,239,16,198,250,153,202,32,152,139,
    196,41,39,232,106,76,109,137,10,133,93,54,196,73,110,167,
    152,88,49,196,203,220,78,51,113,198,16,103,185,157,99,226,
    188,33,46,112,187,200,196,37,67,92,230,246,10,19,87,12,
    113,149,219,53,38,174,27,226,85,110,175,49,113,195,16,171,
    220,94,103,226,13,67,220,228,246,61,38,222,52,196,247,185,
    253,128,137,53,67,252,144,219,91,76,252,137,33,126,196,237,
    109,38,222,49,79,167,234,76,188,11,246,199,244,120,133,40,
    247,40,229,77,252,175,41,143,179,196,197,228,135,230,255,53,
    211,53,238,93,188,34,13,62,128,159,149,229,68,86,203,138,
    206,114,187,194,92,86,178,42,242,211,145,185,209,16,115,188,
    88,186,74,106,199,173,94,132,190,156,70,245,46,218,169,251,
    140,82,233,181,237,211,84,177,99,62,51,246,23,50,183,8,
    246,166,120,142,7,60,188,105,28,178,238,142,165,47,27,67,
    164,230,83,19,76,99,19,202,151,78,198,12,250,34,65,59,
    113,123,61,25,250,195,75,2,143,156,63,8,40,69,31,192,
    240,172,134,55,130,5,252,158,12,76,82,43,163,37,251,177,
    144,134,226,133,120,148,17,252,39,227,203,26,33,120,88,148,
    26,228,73,93,134,210,10,212,248,101,234,155,107,99,240,124,
    45,227,200,241,162,94,223,73,130,215,146,110,165,111,99,193,
    147,35,23,190,81,178,218,60,117,150,106,199,50,105,71,29,
    159,165,191,11,31,45,49,63,178,68,58,166,170,99,243,227,
    87,78,51,104,70,78,39,122,233,116,221,120,143,23,121,43,
    19,173,64,54,26,31,80,215,199,102,170,1,195,168,18,111,
    231,162,5,24,243,227,35,39,230,198,239,180,194,73,46,179,
    194,137,17,181,114,170,137,73,242,233,163,36,177,148,53,187,
    90,59,185,139,174,251,106,40,235,172,113,146,54,169,247,103,
    104,167,241,35,206,227,179,228,241,248,152,60,162,157,234,135,
    118,208,106,15,209,240,118,174,113,111,165,35,39,118,164,222,
    98,1,245,35,22,200,208,212,234,24,191,47,59,110,127,40,
    238,140,97,146,70,201,106,72,82,235,99,220,7,65,172,246,
    221,142,131,87,106,109,207,51,25,72,32,191,130,201,16,213,
    213,83,102,120,209,126,168,88,230,217,28,36,180,146,17,202,
    84,206,182,92,25,113,243,82,201,108,101,224,48,28,60,195,
    243,37,94,16,162,190,227,232,71,51,164,189,227,92,208,241,
    249,231,192,39,97,72,222,7,125,124,46,226,1,122,241,212,
    255,82,190,36,248,14,51,246,18,75,111,252,61,48,143,38,
    250,73,131,40,141,233,52,35,243,11,23,115,125,224,50,76,
    49,184,229,118,245,227,115,126,26,220,32,8,55,54,77,82,
    231,66,170,31,92,241,3,33,253,80,14,75,46,63,150,227,
    251,84,227,142,49,185,214,235,115,213,150,49,94,222,63,115,
    209,67,179,39,200,120,167,231,178,173,169,207,188,96,64,187,
    60,164,117,92,213,140,226,110,102,242,87,24,130,143,35,108,
    162,14,3,105,96,193,126,162,100,151,165,201,112,191,235,124,
    35,187,81,220,255,38,242,165,162,34,245,104,7,125,236,122,
    74,147,157,3,73,247,65,181,144,78,31,29,231,215,2,177,
    27,182,178,219,195,33,253,174,35,67,219,14,78,210,158,116,
    221,147,170,5,209,128,70,59,206,90,133,47,76,195,202,49,
    250,192,131,241,25,203,86,128,186,197,108,214,236,212,193,25,
    135,32,195,175,13,178,225,145,157,120,49,80,214,207,42,244,
    51,218,135,132,20,134,32,189,181,40,77,151,68,209,162,151,
    100,57,81,22,21,145,23,83,149,82,174,84,44,21,114,8,
    119,162,204,139,114,174,84,158,18,167,255,175,32,240,203,214,
    202,114,73,252,23,61,142,148,237,
};

EmbeddedPython embedded_m5_internal_param_Sinic(
    "m5/internal/param_Sinic.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/build/ALPHA/python/m5/internal/param_Sinic.py",
    "m5.internal.param_Sinic",
    data_m5_internal_param_Sinic,
    2553,
    8135);

} // anonymous namespace