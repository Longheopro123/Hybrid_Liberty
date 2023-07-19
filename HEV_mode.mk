# Copyright 1994-2012 The MathWorks, Inc.
#
# File    : grt_lcc64.tmf
#
# Abstract:
#	Template makefile for building a PC-based stand-alone generic real-time
#       version of Simulink model using	generated C code and LCC compiler
#       Version 2.4
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win64.
#
# 	Note that this template is automatically customized by the build
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is none. To enable
#                          debugging specify as OPT_OPTS=-g4.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the
#			   file name instead of a '\' .
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc

#------------------------- Path to Avl_grt_dll.c ------------------------------


PATH_TO_AVL_GRT_DLL = C:\PROGRA~2\AVL\R2021.2\CRUISE\matlab\INSTAL~1\Src\c

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win64\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = avl_grt.tlc
BUILD_SUCCESS	= *** Created
COMPILER_TOOL_CHAIN = lcc


MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.


MODEL                = HEV_mode
MODULES              = rt_logging.c HEV_mode_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c
MAKEFILE             = HEV_mode.mk
MATLAB_ROOT          = C:/Program Files/MATLAB/R2023a
ALT_MATLAB_ROOT      = C:/PROGRA~1/MATLAB/R2023a
MATLAB_BIN           = C:/Program Files/MATLAB/R2023a/bin
ALT_MATLAB_BIN       = C:/PROGRA~1/MATLAB/R2023a/bin
MASTER_ANCHOR_DIR    = 
START_DIR            = C:/Users/Longh/OneDrive/Desktop/DATN
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DTID01EQ=0"
MULTITASKING         = 0
MAT_FILE             = 1
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

CLASSIC_INTERFACE    = 1
# Optional for GRT
ONESTEPFCN           = 0
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = HEV_mode_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications ------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc64\lcc64
include $(MATLAB_ROOT)\rtw\c\tools\lcc64tools.mak

#----------------------------- External mode -----------------------------------

# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc64\lcc64\lib64\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c rtiostream_serial_interface.c rtiostream_serial.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#------------------------------ Include Path ----------------------------------

# see MATLAB_INCLUDES and COMPILER_INCLUDES from lcctools.mak

ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/HEV_mode_avl_rtw \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

#------------------------ rtModel ----------------------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------------- C Flags --------------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(ANSI_OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(ANSI_OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMT=$(MULTITASKING) -DHAVESTDIO -DMAT_FILE=$(MAT_FILE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE)

CFLAGS = $(CC_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES) -noregistrylookup

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LDFLAGS = -dll -s -entry DLLMain -L$(LIB)
else
LDFLAGS = -dll -entry DLLMain -L$(LIB)
endif


#------------------------- Additional Libraries -------------------------------

LIBS =


LIBS += $(EXT_LIB) $(S_FUNCTIONS_LIB)

#----------------------------- Source Files ------------------------------------

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).dll
    BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT) $(SYSLIBS)
    BUILD_PRODUCT_TYPE = dll

REQ_SRCS           = $(MODEL).c $(MODULES) $(EXT_SRC) $(MAIN_SRC) $(OTHER_SRC) \
                     avl_grt_dll.c rt_sim.c
else
    # Model reference coder target
    PRODUCT  = $(MODELLIB)
    REQ_SRCS = $(MODULES)
endif

USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS      = $(REQ_SRCS) $(S_FUNCTIONS)
OBJS      = $(SRCS:.c=.obj)  $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.obj) $(LOCAL_USER_OBJS)

SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))
AVL_SRC = $(PATH_TO_AVL_GRT_DLL)\avl_grt_dll.c
#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) @$(MODELREF_LINK_RSPFILE) $(SHARED_LIB) $(LIBS)
	@cmd /C "echo $(BUILD_SUCCESS) $(MODEL).dll"
else

$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	$(LIBCMD) /out:$(MODELLIB) $(LINK_OBJS)
	@cmd /C "echo $(BUILD_SUCCESS) static library $(MODELLIB)"
endif

%.obj : %.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : %.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

avl_grt_dll.obj : $(AVL_SRC)
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

ifeq ($(CLASSIC_INTERFACE), 1)
%.obj : $(MATLAB_ROOT)/rtw/c/grt/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/grt/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<
else
%.obj : $(MATLAB_ROOT)/rtw/c/src/common/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/common/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<
endif

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/serial/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/serial/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

rt_logging.obj : $(MATLAB_ROOT)/rtw/c/src/rt_logging.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/rt_logging.c



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c
	$(CC) -c -Fo$@ $(CFLAGS) $<

$(SHARED_LIB) : $(SHARED_OBJS)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@cmd /C "echo ### $@ Created"

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@cmd /C "echo ### Deleting the generated source code for $(MODEL)"
	@del $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@cmd /C "echo ### Deleting the objects and $(PROGRAM)"
	@del $(LINK_OBJS) ..\$(MODEL).dll



# EOF: grt_lcc64.tmf
