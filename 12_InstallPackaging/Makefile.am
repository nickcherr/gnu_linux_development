SUBDIRS = src test po

@DX_RULES@

DX_CONFIG = $(builddir)/Doxyfile

all-local:	doxygen-doc

doxygen-doc/man/man1/adder.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/adder.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)