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
            fp, pathname, description = imp.find_module('_param_Directory_Controller', [dirname(__file__)])
        except ImportError:
            import _param_Directory_Controller
            return _param_Directory_Controller
        if fp is not None:
            try:
                _mod = imp.load_module('_param_Directory_Controller', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_Directory_Controller = swig_import_helper()
    del swig_import_helper
else:
    import _param_Directory_Controller
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


import param_RubyDirectoryMemory
import param_SimObject
import param_RubyMemoryControl
import param_RubyController
import param_RubySystem
class Directory_Controller(param_RubyController.AbstractController):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
Directory_Controller_swigregister = _param_Directory_Controller.Directory_Controller_swigregister
Directory_Controller_swigregister(Directory_Controller)

class Directory_ControllerParams(param_RubyController.RubyControllerParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def create(self): return _param_Directory_Controller.Directory_ControllerParams_create(self)
    directory = _swig_property(_param_Directory_Controller.Directory_ControllerParams_directory_get, _param_Directory_Controller.Directory_ControllerParams_directory_set)
    directory_latency = _swig_property(_param_Directory_Controller.Directory_ControllerParams_directory_latency_get, _param_Directory_Controller.Directory_ControllerParams_directory_latency_set)
    memBuffer = _swig_property(_param_Directory_Controller.Directory_ControllerParams_memBuffer_get, _param_Directory_Controller.Directory_ControllerParams_memBuffer_set)
    send_evictions = _swig_property(_param_Directory_Controller.Directory_ControllerParams_send_evictions_get, _param_Directory_Controller.Directory_ControllerParams_send_evictions_set)
    def __init__(self): 
        this = _param_Directory_Controller.new_Directory_ControllerParams()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_Directory_Controller.delete_Directory_ControllerParams
    __del__ = lambda self : None;
Directory_ControllerParams_swigregister = _param_Directory_Controller.Directory_ControllerParams_swigregister
Directory_ControllerParams_swigregister(Directory_ControllerParams)


