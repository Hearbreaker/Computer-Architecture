COPYING = 'Please see individual files for details of the license on each file.\nThe preferred license can be found in LICENSE.\n\nAll files in this distribution (other than in the ext directory) have\nlicenses based on the BSD or MIT licenses.  Some files in the ext\ndirectory are GNU LGPL.  No other licenses are found in this\ndistribution.\n\nBeyond the BSD license, some files include the following clarification\nof the license as required by the copyright holder:\n\n    The license below extends only to copyright in the software and\n    shall not be construed as granting a license to any other\n    intellectual property including but not limited to intellectual\n    property relating to a hardware implementation of the\n    functionality of the software licensed hereunder.  You may use the\n    software subject to the license terms below provided that you\n    ensure that this notice is replicated unmodified and in its\n    entirety in all distributions of the software, modified or\n    unmodified, in source code or in binary form.\n\nThe copyright holders include (not counting the ext directory):\n\nCopyright (c) 2000-2011 The Regents of The University of Michigan\nCopyright (c) 1990,1993-1995,2007-2010 The Hewlett-Packard Development Company\nCopyright (c) 1999-2009,2011 Mark D. Hill and David A. Wood\nCopyright (c) 2009-2011 ARM Limited\nCopyright (c) 2008-2009 Princeton University\nCopyright (c) 2007 MIPS Technologies, Inc.\nCopyright (c) 2009-2011 Advanced Micro Devices, Inc.\nCopyright (c) 2009 The University of Edinburgh\nCopyright (c) 2007-2008 The Florida State University\nCopyright (c) 2010 Massachusetts Institute of Technology\nCopyright (c) 1990-1993 The Regents of the University of California\nCopyright (c) 2006-2009 Nathan Binkert\nCopyright (c) 2001 The NetBSD Foundation, Inc.\nCopyright (c) 2010-2011 Gabe Black\nCopyright (c) 1994 Adam Glass\nCopyright (c) 1990-1992 MIPS Computer Systems, Inc.\nCopyright (c) 2004 Richard J. Wagner\nCopyright (c) 2000 Computer Engineering and Communication Networks Lab\nCopyright (c) 2001 Eric Jackson\nCopyright (c) 1990 Hewlett-Packard Development Company\nCopyright (c) 1994-1996 Carnegie-Mellon University.\nCopyright (c) 1993-1994 Christopher G. Demetriou\nCopyright (c) 1997-2002 Makoto Matsumoto and Takuji Nishimura\nCopyright (c) 1998,2001 Manuel Bouyer.\n'
LICENSE = 'Copyright (c) <date> <copyright holder>\nAll rights reserved.\n\nRedistribution and use in source and binary forms, with or without\nmodification, are permitted provided that the following conditions are\nmet: redistributions of source code must retain the above copyright\nnotice, this list of conditions and the following disclaimer;\nredistributions in binary form must reproduce the above copyright\nnotice, this list of conditions and the following disclaimer in the\ndocumentation and/or other materials provided with the distribution;\nneither the name of the copyright holders nor the names of its\ncontributors may be used to endorse or promote products derived from\nthis software without specific prior written permission.\n\nTHIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\nLIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\nA PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\nOWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\nSPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\nLIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\nDATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\nTHEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\nOF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n'
README = "This is the M5 simulator.\n\nFor detailed information about building the simulator and getting\nstarted please refer to http://www.m5sim.org.\n\nSpecific pages of interest are:\nhttp://www.m5sim.org/wiki/index.php/Compiling_M5\nhttp://www.m5sim.org/wiki/index.php/Running_M5\n\nShort version:\n\n1. If you don't have SCons version 0.98.1 or newer, get it from\nhttp://wwww.scons.org.\n\n2. If you don't have SWIG version 1.3.31 or newer, get it from\nhttp://wwww.swig.org.\n\n3. Make sure you also have gcc version 3.4.6 or newer, Python 2.4 or newer\n(the dev version with header files), zlib, and the m4 preprocessor.\n\n4. In this directory, type 'scons build/ALPHA_SE/tests/debug/quick'.  This\nwill build the debug version of the m5 binary (m5.debug) for the Alpha\nsyscall emulation target, and run the quick regression tests on it.\n\nIf you have questions, please send mail to m5-users@m5sim.org\n\nWHAT'S INCLUDED (AND NOT)\n-------------------------\n\nThe basic source release includes these subdirectories:\n - m5:\n   - configs: simulation configuration scripts\n   - ext: less-common external packages needed to build m5\n   - src: source code of the m5 simulator\n   - system: source for some optional system software for simulated systems\n   - tests: regression tests\n   - util: useful utility programs and files\n\nTo run full-system simulations, you will need compiled system firmware\n(console and PALcode for Alpha), kernel binaries and one or more disk images. \nThese files for Alpha are collected in a separate archive, m5_system.tar.bz2.\nThis file can he downloaded separately.\n\nDepending on the ISA used, M5 may support Linux 2.4/2.6, FreeBSD, and the\nproprietary Compaq/HP Tru64 version of Unix. We are able to distribute Linux\nand FreeBSD bootdisks, but we are unable to distribute bootable disk images of\nTru64 Unix. If you have a Tru64 license and are interested in\nobtaining disk images, contact us at m5-users@m5sim.org\n"