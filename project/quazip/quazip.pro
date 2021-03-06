#-------------------------------------------------
#
# Quazip Project File
#
#-------------------------------------------------

TEMPLATE    = lib
CONFIG     += precompile_header
CONFIG     += staticlib qt warn_on

QT 	-= gui
TARGET      = quazip

#-------------------------------------------------
# Common Settings

include(../common.pri)

#-------------------------------------------------
# Source

#PRECOMPILED_HEADER = $${SOLUTION_DIR}../src/core/stable.hpp

include($${SOLUTION_DIR}../src/quazip/quazip.pri)

#-------------------------------------------------
# Package Config

# MAC AND LINUX:
unix:{
    PKGCONFIG += opentxs
}

# The ABI version.

!win32:VERSION = 1.0.0

# 1.0.0 is the first stable ABI.
# The next binary incompatible change will be 2.0.0 and so on.
# The existing QuaZIP policy on changing ABI requires to bump the
# major version of QuaZIP itself as well. Note that there may be
# other reasons for chaging the major version of QuaZIP, so
# in case where there is a QuaZIP major version bump but no ABI change,
# the VERSION variable will stay the same.

# For example:

# QuaZIP 1.0 is released after some 0.x, keeping binary compatibility.
# VERSION stays 1.0.0.
# Then some binary incompatible change is introduced. QuaZIP goes up to
# 2.0, VERSION to 2.0.0.
# And so on.


# This one handles dllimport/dllexport directives.
DEFINES += QUAZIP_BUILD

# You'll need to define this one manually if using a build system other
# than qmake or using QuaZIP sources directly in your project.
CONFIG(staticlib): DEFINES += QUAZIP_STATIC

unix: {
    	
#	headers.path=$$PREFIX/include/quazip
#    	headers.files=$$HEADERS
#    	target.path=$$PREFIX/lib/$${LIB_ARCH}
#    	INSTALLS += headers target

# This had to be added manually
LIBS += -lz
	OBJECTS_DIR=.obj
	MOC_DIR=.moc
	
}

win32 {
    headers.path=$$PREFIX/include/quazip
    headers.files=$$HEADERS
    target.path=$$PREFIX/lib
    INSTALLS += headers target
    # workaround for qdatetime.h macro bug
    DEFINES += NOMINMAX
}
