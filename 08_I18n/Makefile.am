AM_CFLAGS = -Wall -Wextra

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
