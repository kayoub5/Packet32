# $Id: $

make=nmake

# Building npcap-guide-wrapper.html from the XML source:
# This is where docbook.xsl is on my machine, but maybe we should find a better way to generalize this.
DOCBOOKXSL=C:\msys64\mingw64\share\xml\docbook\xsl-stylesheets-1.79.2\xhtml\docbook.xsl
XSLTPROC = xsltproc

all: help

help:
	@ echo Run one of the following commands:
	@ echo $(make) npcap-guide
	@ echo $(make) authors
	@ echo $(make) changelog

npcap-guide: dummy
	$(XSLTPROC) -o npcap-guide-wrapper.html $(DOCBOOKXSL) npcap-guide-wrapper.xml

authors:
	rm -f AUTHORS
	git shortlog -s -e | cut -c 8- | sort > AUTHORS

# XXX - make changelog target work in cmd
changelog:
	rm -f CHANGELOG
#	git --no-pager log --no-merges --pretty=format:' %x20%x20 - %s (%an)' `git tag | grep -v -- -rc | tail -n 1`..HEAD .. > CHANGELOG
	git --no-pager log --no-merges --pretty=format:' %x20%x20 - %s (%an)' ..HEAD .. > CHANGELOG

dummy:
