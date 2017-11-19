# $Id: $

# A simple Makefile for building npcap-guide-wrapper.html from the XML source
# This is where docbook.xsl is on my machine, but maybe we should find a better way to generalize this.
DOCBOOKXSL=C:\msys64\mingw64\share\xml\docbook\xsl-stylesheets-1.79.2\xhtml\docbook.xsl
XSLTPROC = xsltproc

npcap-guide: dummy
	$(XSLTPROC) -o npcap-guide-wrapper.html $(DOCBOOKXSL) npcap-guide-wrapper.xml


dummy:
