AM_CFLAGS = -Wall -Wextra

all-local: doxygen-clean doxygen-doc

doxygen-doc/man/man1/guess.1: doxygen-doc

man1_MANS = doxygen-doc/man/man1/guess.1

doxygen-clean:
	rm -rf doxygen-doc

doxygen-doc: doxygen-clean
	doxygen Doxyfile

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

http: doxygen-doc
	python3 -m http.server --directory $</html 5000

bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

ru/LC_MESSAGES/guess.mo: ru.po
	mkdir -p `dirname ru/LC_MESSAGES/guess.mo`
	msgfmt ru.po -o ru/LC_MESSAGES/guess.mo

ru.po:	translation.pot
	msgmerge -U ru.po translation.pot

translation.pot:	guess.pot guess.c
	xgettext -c guess.c -o messages.new.pot
	cp guess.pot translation.pot
	msgmerge -U translation.pot messages.new.pot

gitclean:
	git clean -df
