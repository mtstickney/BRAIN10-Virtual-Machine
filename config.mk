# bvm version
VERSION=0.1

# includes
INCS = -I .

# libs
LIBS =

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\"
#CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
#LDFLAGS = -g ${LIBS}
LDFLAGS = -s ${LIBS}

# compiler and linker
CC = cc
