import m5.internal
import m5.util

buildEnv = m5.util.SmartDict([('PROTOCOL', 'MSI'), ('NO_VECTOR_BOUNDS_CHECKS', True), ('USE_FENV', True), ('SS_COMPATIBLE_FP', True), ('TARGET_ISA', 'alpha'), ('CP_ANNOTATE', False), ('USE_POSIX_CLOCK', True)])

compileDate = m5.internal.core.compileDate
_globals = globals()
for key,val in m5.internal.core.__dict__.iteritems():
    if key.startswith('flag_'):
        flag = key[5:]
        _globals[flag] = val
del _globals
