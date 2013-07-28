CC?=gcc
STRIP?=strip
CFLAGS?=
LDFLAGS?=
DESTDIR?=/
PREFIX?=$(DESTDIR)/usr/local
BINDIR?=$(PREFIX)/bin
ifeq ($(OS),Windows_NT)
TARGET?=untar.exe
DEFINE=-DWINDOWS
else
TARGET?=untar
DEFINE=-DUNIX
endif
INSTALL?=install -m
RM?=rm -f
SOURCES=untar.c
OBJECTS=untar.o

.PHONY: all install strip install-strip uninstall clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(DEFINE) $(OBJECTS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(DEFINE) -c $(SOURCES) $(CFLAGS)

install: $(TARGET)
	$(INSTALL) $(TARGET) $(BINDIR)/$(TARGET)

strip: $(TARGET)
	$(STRIP) $(TARGET)

install-strip: $(TARGET)
	$(INSTALL) $(TARGET) $(BINDIR)/$(TARGET)
	$(STRIP) $(BINDIR)/$(TARGET)

uninstall:
	-$(RM) $(BINDIR)/$(TARGET)

clean:
	-$(RM) $(OBJECTS) $(TARGET)
