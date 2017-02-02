#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RubyDirectoryMemory[] = {
    120,156,205,89,109,115,219,198,17,222,3,64,72,164,68,139,
    122,183,28,183,102,155,81,203,230,197,76,157,58,47,141,199,
    83,183,238,235,180,138,3,118,198,54,211,9,2,1,71,18,
    20,8,112,128,163,109,122,164,47,149,39,237,183,254,136,78,
    63,244,15,228,23,244,127,181,187,123,0,68,41,150,162,78,
    59,67,201,194,25,56,44,246,118,159,123,118,111,239,228,67,
    254,83,193,235,103,77,128,236,3,1,16,224,175,128,8,96,
    36,160,43,64,72,1,193,58,28,84,32,253,9,4,21,120,
    5,208,53,64,26,112,140,55,38,124,110,64,188,204,223,216,
    16,153,220,35,96,90,3,105,65,183,2,143,227,85,176,164,
    13,7,53,72,191,4,33,68,44,224,73,176,0,193,34,188,
    66,237,120,83,101,133,139,16,212,248,166,10,193,18,223,212,
    96,218,0,185,4,93,84,190,0,221,58,170,122,11,85,93,
    99,85,255,34,85,1,190,217,128,160,78,226,104,203,83,146,
    180,72,146,199,184,198,90,86,10,203,26,208,109,64,176,2,
    178,1,195,85,232,161,75,141,242,187,53,144,38,12,215,161,
    187,14,18,127,215,224,24,189,14,86,89,118,131,101,215,74,
    217,77,150,221,130,238,22,72,252,221,212,178,54,116,90,155,
    136,97,248,111,252,105,33,134,160,150,177,121,38,211,44,76,
    98,55,140,123,73,104,208,123,155,26,66,220,167,102,33,135,
    254,23,4,253,63,129,113,15,140,28,250,35,64,197,130,236,
    143,12,56,226,155,35,3,166,45,56,20,48,180,32,48,225,
    16,135,169,144,1,125,1,199,6,252,201,36,129,35,108,45,
    4,235,187,96,41,141,251,144,193,210,154,22,224,168,2,135,
    21,232,60,57,52,168,227,160,10,233,63,224,229,77,86,186,
    200,74,13,56,196,214,130,99,11,142,108,120,140,66,216,53,
    172,146,251,226,201,33,122,138,61,157,150,133,214,238,205,184,
    75,174,4,97,26,123,35,169,110,224,189,59,246,82,111,228,
    58,147,253,233,195,48,149,190,74,210,233,31,228,8,219,86,
    173,144,79,178,219,99,79,13,28,86,96,18,50,163,177,98,
    197,73,44,213,18,222,244,194,56,112,71,73,48,137,164,90,
    36,173,110,47,140,164,235,242,203,223,142,198,73,170,126,153,
    166,73,234,16,184,220,25,37,94,249,5,65,235,71,73,38,
    91,52,26,15,227,144,122,69,210,189,49,107,36,3,216,104,
    250,56,144,153,159,134,99,133,115,166,53,146,52,105,107,209,
    108,113,147,141,177,105,199,189,172,61,233,183,7,201,72,102,
    239,190,223,30,183,199,94,252,82,190,8,219,15,19,127,50,
    146,177,202,218,210,151,119,239,222,105,71,222,254,221,118,95,
    142,238,182,247,39,97,20,180,31,252,254,209,111,30,180,199,
    83,53,72,226,54,246,134,177,146,136,90,212,62,23,175,219,
    40,188,70,35,63,15,251,110,200,62,187,3,25,141,101,74,
    38,103,4,54,136,134,88,22,182,48,69,75,212,241,174,130,
    151,41,110,26,75,98,47,36,175,125,66,130,168,103,22,100,
    251,59,240,180,34,43,14,12,72,111,18,149,134,248,43,104,
    238,145,80,29,122,103,240,187,207,8,46,221,59,52,137,32,
    186,243,144,233,135,60,68,201,123,196,136,24,152,67,21,24,
    218,160,185,133,148,212,100,75,167,212,162,56,169,49,80,185,
    5,217,223,78,107,136,27,128,211,129,225,139,93,91,56,212,
    159,153,174,157,22,25,190,199,100,81,131,48,75,158,199,60,
    37,116,207,1,214,65,76,30,77,63,221,31,34,96,217,45,
    236,120,154,76,154,190,23,199,137,106,122,65,208,244,148,74,
    195,253,137,146,89,83,37,205,221,172,85,37,14,172,22,124,
    43,245,77,199,5,191,136,11,200,47,253,16,132,190,194,135,
    117,126,96,252,51,169,144,43,131,36,200,176,159,84,244,165,
    114,200,72,117,13,155,7,197,112,76,202,150,93,80,40,147,
    81,79,213,152,141,94,150,185,60,28,245,51,241,232,235,103,
    94,52,145,138,228,51,229,41,28,149,110,245,64,243,166,222,
    117,114,190,240,157,240,116,227,36,14,166,104,122,232,191,73,
    86,93,103,2,46,3,81,112,19,233,183,128,173,13,117,164,
    99,195,240,201,75,43,39,31,19,111,139,48,1,38,131,200,
    115,13,146,240,24,51,82,203,224,148,194,238,114,168,54,233,
    142,62,118,136,227,206,27,212,220,164,230,59,5,34,115,132,
    165,126,22,150,247,200,20,131,177,240,205,220,235,50,220,246,
    78,133,219,206,73,184,97,82,237,80,216,24,20,92,39,97,
    99,18,46,233,253,60,70,40,32,145,38,248,122,38,50,24,
    45,167,65,40,216,5,169,29,98,234,44,93,251,51,116,117,
    104,162,152,171,206,206,121,200,222,186,82,200,246,53,178,239,
    147,41,203,57,203,234,204,174,154,240,137,34,70,142,51,99,
    252,16,111,166,219,132,241,44,186,219,184,114,62,142,235,188,
    4,242,50,202,197,129,78,61,26,116,125,99,17,31,123,38,
    108,229,75,91,70,153,98,156,38,47,166,205,164,215,84,80,
    216,112,111,55,187,189,155,125,130,185,164,121,159,179,147,206,
    38,58,95,164,114,156,98,94,168,242,131,142,117,151,227,222,
    205,151,36,156,5,42,19,120,242,24,123,78,109,153,74,41,
    163,205,27,248,90,9,60,249,241,49,217,81,99,212,77,216,
    198,171,38,216,88,55,225,108,203,245,11,191,197,235,231,132,
    63,65,32,129,42,70,167,163,93,97,47,201,95,231,135,167,
    120,53,63,31,157,183,200,218,34,82,109,40,89,68,151,73,
    94,80,240,252,5,184,232,19,240,21,16,99,144,24,121,184,
    113,96,211,69,19,191,78,226,95,0,39,178,215,172,163,134,
    14,91,35,79,117,24,213,217,135,44,170,151,213,223,193,95,
    103,178,224,177,9,130,150,64,51,47,235,102,151,64,171,12,
    116,166,218,165,150,57,235,116,70,160,121,27,120,25,137,233,
    216,55,203,216,63,73,168,101,21,134,9,109,142,44,92,212,
    22,184,100,236,175,79,56,72,235,203,27,98,221,152,97,214,
    59,212,188,91,146,74,20,125,243,177,251,214,217,5,97,102,
    157,116,117,18,254,21,25,103,177,59,43,182,90,193,255,207,
    232,41,131,170,82,4,213,157,50,168,36,47,14,175,120,143,
    64,173,65,84,57,54,4,110,184,176,108,162,189,142,5,178,
    2,93,155,194,143,43,95,145,71,167,40,50,36,101,214,83,
    43,15,99,182,167,209,44,217,162,137,64,205,139,121,103,36,
    226,194,189,200,27,237,7,222,125,135,172,32,83,252,34,94,
    141,194,175,198,172,95,20,107,226,60,215,248,241,189,194,191,
    103,243,206,70,63,38,115,10,191,56,246,130,196,231,20,244,
    199,129,108,142,228,104,31,55,144,131,112,220,236,69,94,159,
    231,211,204,253,254,180,240,91,49,33,206,214,5,92,102,237,
    37,77,63,137,113,113,153,208,176,205,64,226,110,74,6,58,
    78,78,103,1,46,70,189,180,159,113,221,121,240,156,110,175,
    194,220,187,184,115,14,177,2,239,20,24,233,141,92,185,164,
    112,209,173,131,14,151,106,220,17,169,169,78,148,31,80,243,
    35,106,118,225,138,172,60,109,28,244,51,26,157,32,182,49,
    151,85,133,162,89,120,141,248,35,210,147,125,51,25,124,125,
    153,100,160,207,93,242,148,96,147,164,92,160,173,61,181,85,
    90,134,186,181,162,115,137,219,101,238,172,23,157,215,184,93,
    225,206,70,209,185,202,237,26,119,174,23,157,27,220,110,114,
    231,86,113,50,180,205,157,215,161,187,67,199,46,212,115,131,
    18,210,194,255,154,144,56,106,231,61,135,20,175,79,255,175,
    121,200,185,115,213,220,114,184,220,190,40,7,137,89,159,235,
    58,7,13,69,177,81,153,117,152,207,80,154,23,145,220,245,
    83,233,41,169,167,248,198,252,177,224,4,168,109,250,188,156,
    232,194,225,114,59,247,97,233,244,49,87,136,211,141,153,253,
    4,207,187,120,140,229,28,238,57,14,25,23,215,208,219,142,
    19,134,91,37,60,84,123,197,242,249,235,236,209,16,233,13,
    6,217,229,141,199,50,14,78,54,15,252,102,222,228,161,84,
    235,193,73,157,134,59,133,13,188,190,25,236,228,242,12,2,
    60,227,149,50,188,175,192,220,115,28,244,138,89,111,241,174,
    184,92,106,28,154,115,189,184,148,235,138,243,211,114,22,119,
    47,36,249,36,147,238,200,27,211,134,246,146,146,88,67,114,
    213,158,63,115,65,126,254,87,244,69,36,159,201,40,227,33,
    46,45,76,163,208,180,157,116,125,139,121,197,129,246,183,59,
    82,72,22,142,228,207,234,237,11,191,138,39,35,207,29,132,
    253,129,187,143,235,62,141,242,223,200,211,88,148,143,78,245,
    170,239,95,168,33,11,95,74,30,232,18,98,164,159,143,243,
    240,129,121,207,185,45,144,145,84,242,252,248,85,68,154,252,
    60,38,144,88,142,37,83,215,213,91,105,124,142,92,247,74,
    148,39,31,225,160,79,32,63,160,163,242,196,198,2,101,179,
    252,87,181,170,130,235,197,51,127,198,208,102,111,67,177,117,
    156,102,14,47,34,43,101,100,240,33,123,81,156,113,226,164,
    227,145,61,111,164,15,73,249,148,207,249,30,53,111,22,193,
    197,201,78,31,51,240,134,93,31,168,96,146,228,35,21,174,
    93,157,219,212,79,163,104,175,58,225,72,159,2,179,108,249,
    196,85,151,162,61,238,25,151,121,58,82,217,15,51,4,135,
    245,148,223,228,89,151,0,81,63,184,152,20,51,58,174,194,
    36,234,253,146,62,105,186,79,56,100,228,4,157,203,86,87,
    170,194,54,232,143,2,166,168,137,186,176,196,114,189,106,86,
    237,106,197,196,137,166,158,117,81,51,171,181,101,177,131,19,
    93,51,118,80,254,63,66,92,181,138,
};

EmbeddedPython embedded_m5_internal_param_RubyDirectoryMemory(
    "m5/internal/param_RubyDirectoryMemory.py",
    "/nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/build/ALPHA/python/m5/internal/param_RubyDirectoryMemory.py",
    "m5.internal.param_RubyDirectoryMemory",
    data_m5_internal_param_RubyDirectoryMemory,
    2186,
    7197);

} // anonymous namespace