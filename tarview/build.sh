#!/bin/sh

if [ ! -n "$TARGET" ]; then
TARGET="UNIX"
fi

if [ "$TARGET" == "windows" ]; then
EXEEXT=".exe"
fi

if [ "$TARGET" == "WINDOWS" ]; then
EXEEXT=".exe"
fi

if [ ! -n "$INFILE" ]; then
INFILE="untar.c"
fi

if [ ! -n "$EXEEXT" ]; then
EXEEXT=""
fi

if [ ! -n "$OUTFILE" ]; then
OUTFILE="untar$EXEEXT"
fi

if [ ! -n "$RMFILE" ]; then
RMFILE="$(which rm) -rf"
fi

if [ ! -n "$CC" ]; then
CC="$(which gcc)"
fi

if [ ! -n "$CXX" ]; then
CXX="$(which g++)"
fi

if [ ! -n "$STRIP" ]; then
STRIP="$(which strip)"
fi

if [ ! -n "$UNAME" ]; then
UNAME="$(which uname)"
if [ "$($UNAME -p)" == "unknown" ]; then
UNAME="$UNAME -smr"
else
UNAME="$UNAME -smpr"
fi
fi

if [ ! -n "$LDFLAGS" ]; then
LDFLAGS=""
fi

if [ ! -n "$CFLAGS" ]; then
CFLAGS=""
fi

if [ ! -n "$CPPFLAGS" ]; then
CPPFLAGS=""
fi

if [ -n "$TARGET" ]; then
CFLAGS="$CFLAGS -D$TARGET"
CPPFLAGS="$CFLAGS -D$TARGET"
fi

printandrun() {
echo $1
$1
}

buildwithc() {
if [ "$3" == "" ]; then
printandrun "$CC $1 -o $2"
else
printandrun "$CC $3 $1 -o $2"
fi
}

buildwithcpp() {
if [ "$3" == "" ]; then
printandrun "$CXX $1 -o $2"
else
printandrun "$CXX $3 $1 -o $2"
fi
}

buildstrip() {
printandrun "$STRIP $1"
}

echo Running make script $0

echo Making $OUTFILE on $($UNAME)

if [ -f $OUTFILE ]; then
printandrun "$RMFILE $OUTFILE"
fi

buildwithc "$INFILE" "$OUTFILE" "$LDFLAGS $CFLAGS"

buildstrip "$OUTFILE"

