# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.4
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_debug', [dirname(__file__)])
        except ImportError:
            import _debug
            return _debug
        if fp is not None:
            try:
                _mod = imp.load_module('_debug', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _debug = swig_import_helper()
    del swig_import_helper
else:
    import _debug
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


def _swig_setattr_nondynamic_method(set):
    def set_attr(self,name,value):
        if (name == "thisown"): return self.this.own(value)
        if hasattr(self,name) or (name == "this"):
            set(self,name,value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr


class SwigPyIterator(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _debug.delete_SwigPyIterator
    __del__ = lambda self : None;
    def value(self): return _debug.SwigPyIterator_value(self)
    def incr(self, n = 1): return _debug.SwigPyIterator_incr(self, n)
    def decr(self, n = 1): return _debug.SwigPyIterator_decr(self, n)
    def distance(self, *args): return _debug.SwigPyIterator_distance(self, *args)
    def equal(self, *args): return _debug.SwigPyIterator_equal(self, *args)
    def copy(self): return _debug.SwigPyIterator_copy(self)
    def next(self): return _debug.SwigPyIterator_next(self)
    def __next__(self): return _debug.SwigPyIterator___next__(self)
    def previous(self): return _debug.SwigPyIterator_previous(self)
    def advance(self, *args): return _debug.SwigPyIterator_advance(self, *args)
    def __eq__(self, *args): return _debug.SwigPyIterator___eq__(self, *args)
    def __ne__(self, *args): return _debug.SwigPyIterator___ne__(self, *args)
    def __iadd__(self, *args): return _debug.SwigPyIterator___iadd__(self, *args)
    def __isub__(self, *args): return _debug.SwigPyIterator___isub__(self, *args)
    def __add__(self, *args): return _debug.SwigPyIterator___add__(self, *args)
    def __sub__(self, *args): return _debug.SwigPyIterator___sub__(self, *args)
    def __iter__(self): return self
SwigPyIterator_swigregister = _debug.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)


def breakpoint():
  return _debug.breakpoint()
breakpoint = _debug.breakpoint
class Flag(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _debug.delete_Flag
    __del__ = lambda self : None;
    def name(self): return _debug.Flag_name(self)
    def desc(self): return _debug.Flag_desc(self)
    def kids(self): return _debug.Flag_kids(self)
    def enable(self): return _debug.Flag_enable(self)
    def disable(self): return _debug.Flag_disable(self)
Flag_swigregister = _debug.Flag_swigregister
Flag_swigregister(Flag)

class SimpleFlag(Flag):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _debug.new_SimpleFlag(*args)
        try: self.this.append(this)
        except: self.this = this
    def status(self): return _debug.SimpleFlag_status(self)
    def __nonzero__(self):
        return _debug.SimpleFlag___nonzero__(self)
    __bool__ = __nonzero__


    def enable(self): return _debug.SimpleFlag_enable(self)
    def disable(self): return _debug.SimpleFlag_disable(self)
    __swig_destroy__ = _debug.delete_SimpleFlag
    __del__ = lambda self : None;
SimpleFlag_swigregister = _debug.SimpleFlag_swigregister
SimpleFlag_swigregister(SimpleFlag)

class CompoundFlag(SimpleFlag):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _debug.new_CompoundFlag(*args)
        try: self.this.append(this)
        except: self.this = this
    def enable(self): return _debug.CompoundFlag_enable(self)
    def disable(self): return _debug.CompoundFlag_disable(self)
    __swig_destroy__ = _debug.delete_CompoundFlag
    __del__ = lambda self : None;
CompoundFlag_swigregister = _debug.CompoundFlag_swigregister
CompoundFlag_swigregister(CompoundFlag)


def romMicroPC(*args):
  return _debug.romMicroPC(*args)
romMicroPC = _debug.romMicroPC

def normalMicroPC(*args):
  return _debug.normalMicroPC(*args)
normalMicroPC = _debug.normalMicroPC

def isRomMicroPC(*args):
  return _debug.isRomMicroPC(*args)
isRomMicroPC = _debug.isRomMicroPC

def schedBreakCycle(*args):
  return _debug.schedBreakCycle(*args)
schedBreakCycle = _debug.schedBreakCycle

def takeCheckpoint(*args):
  return _debug.takeCheckpoint(*args)
takeCheckpoint = _debug.takeCheckpoint

def eventqDump():
  return _debug.eventqDump()
eventqDump = _debug.eventqDump

def getRemoteGDBPort():
  return _debug.getRemoteGDBPort()
getRemoteGDBPort = _debug.getRemoteGDBPort

def setRemoteGDBPort(*args):
  return _debug.setRemoteGDBPort(*args)
setRemoteGDBPort = _debug.setRemoteGDBPort
class AllFlags(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def iterator(self): return _debug.AllFlags_iterator(self)
    def __iter__(self): return self.iterator()
    def __nonzero__(self): return _debug.AllFlags___nonzero__(self)
    def __bool__(self): return _debug.AllFlags___bool__(self)
    def __len__(self): return _debug.AllFlags___len__(self)
    def pop(self): return _debug.AllFlags_pop(self)
    def __getslice__(self, *args): return _debug.AllFlags___getslice__(self, *args)
    def __setslice__(self, *args): return _debug.AllFlags___setslice__(self, *args)
    def __delslice__(self, *args): return _debug.AllFlags___delslice__(self, *args)
    def __delitem__(self, *args): return _debug.AllFlags___delitem__(self, *args)
    def __getitem__(self, *args): return _debug.AllFlags___getitem__(self, *args)
    def __setitem__(self, *args): return _debug.AllFlags___setitem__(self, *args)
    def append(self, *args): return _debug.AllFlags_append(self, *args)
    def empty(self): return _debug.AllFlags_empty(self)
    def size(self): return _debug.AllFlags_size(self)
    def clear(self): return _debug.AllFlags_clear(self)
    def swap(self, *args): return _debug.AllFlags_swap(self, *args)
    def get_allocator(self): return _debug.AllFlags_get_allocator(self)
    def begin(self): return _debug.AllFlags_begin(self)
    def end(self): return _debug.AllFlags_end(self)
    def rbegin(self): return _debug.AllFlags_rbegin(self)
    def rend(self): return _debug.AllFlags_rend(self)
    def pop_back(self): return _debug.AllFlags_pop_back(self)
    def erase(self, *args): return _debug.AllFlags_erase(self, *args)
    def __init__(self, *args): 
        this = _debug.new_AllFlags(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(self, *args): return _debug.AllFlags_push_back(self, *args)
    def front(self): return _debug.AllFlags_front(self)
    def back(self): return _debug.AllFlags_back(self)
    def assign(self, *args): return _debug.AllFlags_assign(self, *args)
    def resize(self, *args): return _debug.AllFlags_resize(self, *args)
    def insert(self, *args): return _debug.AllFlags_insert(self, *args)
    def reserve(self, *args): return _debug.AllFlags_reserve(self, *args)
    def capacity(self): return _debug.AllFlags_capacity(self)
    __swig_destroy__ = _debug.delete_AllFlags
    __del__ = lambda self : None;
AllFlags_swigregister = _debug.AllFlags_swigregister
AllFlags_swigregister(AllFlags)
cvar = _debug.cvar
MaxTick = cvar.MaxTick
MicroPCRomBit = cvar.MicroPCRomBit
MaxAddr = cvar.MaxAddr
InvalidThreadID = cvar.InvalidThreadID
InvalidPortID = cvar.InvalidPortID


def getAllFlagsVersion():
  return _debug.getAllFlagsVersion()
getAllFlagsVersion = _debug.getAllFlagsVersion

def getAllFlags():
  return _debug.getAllFlags()
getAllFlags = _debug.getAllFlags

