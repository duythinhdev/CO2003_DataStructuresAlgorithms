#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/dsacpp/include/FE-SUMMER-2022.o \
	${OBJECTDIR}/dsacpp/src/geom/Point3D.o \
	${OBJECTDIR}/dsacpp/src/geom/Vector3D.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dsaframework

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dsaframework: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dsaframework ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/dsacpp/include/FE-SUMMER-2022.o: dsacpp/include/FE-SUMMER-2022.cpp
	${MKDIR} -p ${OBJECTDIR}/dsacpp/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -Idsacpp/include -Idoctest -Iopencv-4.5.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dsacpp/include/FE-SUMMER-2022.o dsacpp/include/FE-SUMMER-2022.cpp

${OBJECTDIR}/dsacpp/src/geom/Point3D.o: dsacpp/src/geom/Point3D.cpp
	${MKDIR} -p ${OBJECTDIR}/dsacpp/src/geom
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -Idsacpp/include -Idoctest -Iopencv-4.5.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dsacpp/src/geom/Point3D.o dsacpp/src/geom/Point3D.cpp

${OBJECTDIR}/dsacpp/src/geom/Vector3D.o: dsacpp/src/geom/Vector3D.cpp
	${MKDIR} -p ${OBJECTDIR}/dsacpp/src/geom
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -Idsacpp/include -Idoctest -Iopencv-4.5.2/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dsacpp/src/geom/Vector3D.o dsacpp/src/geom/Vector3D.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
