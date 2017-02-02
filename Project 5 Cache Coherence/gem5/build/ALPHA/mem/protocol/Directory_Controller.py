from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class Directory_Controller(RubyController):
    type = 'Directory_Controller'
    directory = Param.RubyDirectoryMemory("")
    memBuffer = Param.RubyMemoryControl("")
    directory_latency = Param.Int(12, "")
    send_evictions = Param.Bool(False, "")
