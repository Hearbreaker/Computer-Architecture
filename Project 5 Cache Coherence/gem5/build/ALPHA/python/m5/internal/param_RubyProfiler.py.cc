#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RubyProfiler[] = {
    120,156,205,88,235,115,219,198,17,223,3,64,72,160,68,137,
    178,94,81,226,214,108,51,158,176,153,198,76,157,186,233,195,
    227,169,211,244,57,29,197,5,51,99,155,205,20,133,128,35,
    9,10,4,88,224,104,155,25,233,75,229,105,251,173,127,67,
    167,211,15,253,63,250,127,181,187,123,0,4,61,210,106,166,
    157,50,18,121,115,92,44,246,246,241,219,189,189,11,160,248,
    107,224,247,135,29,128,252,35,1,16,226,71,64,12,48,21,
    48,16,32,164,128,112,27,142,27,144,125,27,194,6,188,6,
    24,24,32,13,56,195,137,9,191,54,32,89,231,119,108,136,
    77,166,8,88,52,65,90,48,104,192,211,100,11,44,105,195,
    113,19,178,223,130,16,34,17,240,44,92,129,112,21,94,163,
    116,156,56,44,112,21,194,38,79,28,8,215,120,210,132,69,
    27,228,26,12,80,248,10,12,90,40,234,93,20,181,193,162,
    254,65,162,66,124,178,3,97,139,216,81,151,231,196,105,17,
    39,175,177,193,82,54,75,205,218,48,104,151,243,45,24,108,
    65,184,9,114,11,38,183,96,136,230,181,43,25,219,32,77,
    152,236,192,96,7,36,126,182,225,12,61,16,110,49,239,46,
    243,222,170,120,247,152,119,31,6,251,32,241,179,167,121,109,
    232,119,119,209,159,209,63,241,175,139,254,4,181,142,195,11,
    153,229,81,154,120,81,50,76,35,131,158,219,52,144,247,3,
    26,86,138,48,252,136,194,240,119,224,24,132,70,17,134,83,
    64,193,130,244,143,13,56,229,201,169,1,139,46,156,8,152,
    88,16,154,112,130,203,52,72,129,145,128,51,3,62,51,137,
    225,20,71,11,29,247,85,176,148,142,193,132,29,167,37,173,
    192,105,3,78,26,208,127,118,98,16,225,216,129,236,111,240,
    249,109,22,186,202,66,13,56,193,209,130,51,11,78,109,120,
    138,76,72,154,56,100,190,120,118,130,150,34,165,223,181,80,
    219,195,154,185,100,74,24,101,137,63,149,106,27,231,222,204,
    207,252,169,231,206,143,22,79,178,116,24,197,50,235,54,75,
    198,52,191,55,243,213,216,229,55,77,114,201,116,166,88,98,
    154,72,181,134,147,97,148,132,222,52,13,231,177,84,171,36,
    206,35,17,158,199,15,127,62,157,165,153,250,113,150,165,153,
    75,94,101,98,156,250,213,27,228,211,32,78,115,217,165,213,
    120,25,151,196,43,226,30,206,88,34,41,192,218,210,203,161,
    204,131,44,154,41,12,150,150,72,220,36,173,75,97,226,33,
    167,176,245,146,97,222,155,143,122,227,116,42,243,247,62,232,
    205,122,51,63,249,92,190,138,122,31,167,193,124,42,19,149,
    247,100,32,31,60,184,223,139,253,163,7,189,145,156,62,232,
    29,205,163,56,236,61,254,229,147,159,61,238,205,22,106,156,
    38,61,164,70,137,146,232,174,184,119,213,81,247,144,235,22,
    45,249,50,26,121,17,27,235,141,101,60,147,25,233,154,191,
    73,234,136,182,88,23,182,48,69,87,180,112,214,192,175,41,
    110,27,107,226,48,34,115,3,114,1,129,205,44,225,245,87,
    224,64,34,14,142,13,200,110,19,120,38,248,17,20,109,132,
    80,159,158,25,252,236,87,228,39,77,157,152,4,9,77,60,
    97,192,33,242,144,243,33,97,32,1,70,77,3,38,54,104,
    52,33,8,53,188,178,5,141,200,78,98,12,20,110,65,254,
    231,139,18,146,54,96,28,48,121,145,180,135,75,253,158,1,
    218,239,146,226,135,140,18,53,142,242,244,101,194,177,160,57,
    167,84,31,125,242,100,241,201,209,68,6,42,191,131,132,231,
    233,188,19,248,73,146,170,142,31,134,29,95,169,44,58,154,
    43,153,119,84,218,185,155,119,29,10,254,86,9,180,74,222,
    98,86,2,139,64,128,192,210,63,194,40,80,248,131,17,236,
    177,255,115,169,16,36,227,52,204,145,78,34,70,82,185,164,
    164,218,192,225,113,185,28,163,177,107,151,216,201,101,60,84,
    77,134,161,159,231,30,47,71,116,70,28,189,253,194,143,231,
    82,17,127,174,124,133,171,210,84,47,180,52,204,189,65,86,
    151,70,147,35,189,36,77,194,5,234,28,5,111,147,58,111,
    48,242,214,129,176,183,139,184,91,193,209,134,22,226,176,109,
    4,100,158,85,160,142,17,183,71,206,0,70,129,40,202,10,
    162,239,12,139,79,215,224,234,193,118,114,114,118,104,70,47,
    187,4,110,247,45,26,110,211,240,149,210,21,203,240,71,235,
    178,63,222,39,29,12,118,66,96,22,230,86,9,118,120,33,
    193,14,206,19,12,11,103,159,18,197,160,116,58,79,20,147,
    28,146,61,42,178,130,82,16,129,129,143,107,185,192,110,114,
    219,100,190,93,194,216,37,108,214,1,58,170,1,212,165,8,
    49,58,221,131,47,114,233,157,47,135,75,71,218,165,31,144,
    14,235,5,174,90,140,167,166,8,8,20,70,225,96,118,238,
    199,56,89,236,147,115,235,110,221,199,109,241,105,210,226,253,
    141,247,72,238,2,116,149,209,222,214,19,139,16,56,52,97,
    175,216,183,114,42,10,179,44,125,181,232,164,195,142,130,82,
    135,135,119,243,123,119,243,31,96,217,232,60,226,66,164,11,
    135,46,13,153,156,101,88,2,28,254,161,211,218,227,20,247,
    138,109,7,221,79,61,0,71,141,157,206,85,44,87,25,21,
    175,165,121,188,89,121,156,12,248,30,41,208,100,119,155,176,
    143,223,166,96,45,189,148,43,42,119,37,252,20,191,31,145,
    227,201,118,9,212,19,186,125,109,3,155,71,134,186,239,92,
    64,210,18,140,115,223,37,53,203,164,180,161,194,13,125,77,
    82,159,242,228,143,192,61,156,128,63,0,97,4,161,80,100,
    22,231,48,125,41,212,219,196,254,27,224,98,117,205,38,105,
    232,12,53,138,114,134,9,156,127,200,172,122,207,252,5,252,
    169,86,233,206,76,16,180,191,153,69,151,86,223,223,172,42,
    167,25,92,55,218,195,172,139,201,79,1,27,251,57,177,233,
    52,55,171,52,63,47,154,85,111,133,181,107,25,184,91,213,
    75,123,164,229,79,207,81,71,155,199,91,98,219,168,97,233,
    155,52,188,87,193,72,148,180,255,179,194,119,46,87,251,218,
    238,231,233,10,251,19,210,202,98,59,54,109,182,176,20,80,
    37,78,163,76,156,251,85,226,72,46,249,175,185,187,167,209,
    32,84,156,25,2,143,77,216,254,208,137,197,2,217,128,129,
    77,41,198,173,171,40,50,80,148,229,143,202,230,133,253,132,
    189,116,168,253,87,1,67,199,156,134,87,75,43,55,228,148,
    135,177,63,61,10,253,71,125,90,158,116,8,202,156,52,74,
    131,218,117,131,40,159,196,23,217,196,63,223,47,13,123,177,
    180,82,243,45,92,173,50,136,19,43,76,3,174,47,159,142,
    101,103,42,167,71,120,216,27,71,179,206,48,246,71,28,65,
    179,48,248,147,210,96,197,16,184,188,191,115,159,116,152,118,
    130,52,193,189,98,30,168,52,235,132,18,15,64,50,212,185,
    112,49,197,185,141,244,179,81,206,29,227,241,75,154,46,53,
    218,30,30,111,35,108,154,63,45,157,163,15,93,213,14,193,
    125,178,78,44,220,114,241,16,163,22,186,252,125,135,134,111,
    208,112,23,150,189,145,244,72,13,90,150,156,106,99,133,114,
    4,31,193,234,124,79,232,205,252,106,166,255,229,38,153,174,
    175,70,138,124,183,137,83,174,208,137,155,70,135,182,147,65,
    179,36,174,241,184,206,196,86,73,220,224,113,147,137,237,146,
    184,197,227,45,38,110,151,247,52,59,76,220,133,193,30,93,
    124,16,101,159,10,203,202,127,91,88,56,9,151,154,126,131,
    255,105,61,113,239,127,105,236,113,185,11,254,119,181,68,212,
    141,109,233,90,50,17,229,193,161,110,41,95,95,28,92,11,
    93,47,200,164,175,164,142,230,155,75,180,158,75,151,86,230,
    179,42,166,165,137,213,129,234,195,202,204,51,110,220,22,59,
    181,198,158,67,44,158,98,151,133,205,255,9,123,194,51,116,
    255,127,142,98,171,114,8,213,216,68,190,244,174,58,69,183,
    248,164,144,63,155,201,36,60,111,223,249,201,210,0,66,213,
    209,135,243,190,9,123,245,29,252,94,77,97,50,178,102,51,
    7,183,81,37,237,50,195,204,32,31,150,1,238,242,217,180,
    218,22,92,10,175,222,8,170,61,192,253,126,21,176,238,245,
    8,78,230,83,47,29,98,135,246,187,185,76,2,204,18,58,
    71,222,156,25,59,59,69,81,189,242,68,125,253,122,17,25,
    146,188,124,145,43,57,229,149,110,192,70,107,208,61,93,141,
    166,58,215,191,54,78,149,23,227,70,175,173,248,143,76,36,
    153,142,159,21,69,189,115,253,43,126,28,227,166,172,187,137,
    8,219,10,22,127,83,94,90,133,194,114,249,1,35,146,43,
    75,40,99,169,228,53,185,196,239,21,215,18,33,170,151,165,
    11,60,35,243,249,18,127,199,158,183,220,77,254,187,184,218,
    115,90,118,7,244,38,111,227,54,191,91,252,59,150,35,184,
    203,186,116,81,223,173,176,171,79,83,139,220,229,146,189,89,
    65,149,111,147,203,206,134,139,22,5,233,208,159,234,75,65,
    190,220,114,191,70,195,219,37,218,185,222,232,35,55,159,97,
    245,173,2,22,40,190,87,224,142,207,189,71,116,114,232,185,
    49,125,141,166,205,138,216,143,166,250,42,148,5,84,191,184,
    157,81,148,106,165,249,28,147,76,142,34,20,144,177,128,138,
    185,40,131,228,28,62,3,93,131,145,250,203,75,13,161,62,
    94,232,235,150,71,100,114,78,21,131,174,35,157,77,71,216,
    6,93,130,155,162,41,90,194,18,235,45,199,116,108,167,97,
    98,152,137,178,45,154,166,211,92,71,222,3,12,117,211,56,
    216,112,196,191,0,126,215,74,45,
};

EmbeddedPython embedded_m5_internal_param_RubyProfiler(
    "m5/internal/param_RubyProfiler.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/build/ALPHA/python/m5/internal/param_RubyProfiler.py",
    "m5.internal.param_RubyProfiler",
    data_m5_internal_param_RubyProfiler,
    2169,
    6925);

} // anonymous namespace