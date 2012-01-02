# bvm - BRAIN10 virtual machine
# see LICENSE file for copyright and license details

include config.mk

SRC = loader.c mem.c vm.c
OBJS = ${SRC:.c=.o}

all: options brain

options:
	@echo bvm build options
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJS}: mem.h vm.h config.mk

brain: ${OBJS}
	@echo CC -o $@
	@${CC} -o $@ ${OBJS} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f ${OBJS} brain

dist: clean
	@echo creating dist tarball
	@mkdir -p bvm-${VERSION}
	@cp -R LICENSE Makefile README config.mk \
		${SRC} bvm-${VERSION}
	@tar -cf bvm-${VERSION}.tar bvm-${VERSION}
	@gzip bvm-${VERSION}.tar
	@rm -rf bvm-${VERSION}

.PHONY: all options clean dist
