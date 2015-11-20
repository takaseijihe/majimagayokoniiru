TARGET=main
CC=gcc
CXX=g++
CFLAGS=-g -O2 -w -ldxlib -Ldxlib
CXXFLAGS=$(CFLAGS)
LDFLAGS=-static-libgcc -static-libstdc++
INCDIR=-I"./DxLib/4_8_1/"
LIBDIR=-L"./DxLib/4_8_1/"
LIBS=-lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltheora_static -lvorbis_static\
	 -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath -ltiff
LIBS+=-lgdi32
OBJS=main.o

.c.o:
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $@ $^ $(LIBS) 

clean:
	@rm -fr $(TARGET).exe $(OBJS) *~ *.swp