
all:
	@echo "make targets:"
	@echo
	@echo "check:     SGML correctness check"
	@echo "normalize: SGML canonical formatting"
	@echo "pdf:       Create PDF"
	@echo "html:      Create HTML"

check:
	sgmlnorm -e book-sid.sgml > /dev/null

normalize:
	(echo '<!DOCTYPE BOOK PUBLIC "-//Davenport//DTD DocBook V3.0//EN" ['; \
	echo '<!ENTITY % PRINTONLY "IGNORE">'; \
	echo '<!ENTITY % HTMLONLY "IGNORE">'; \
	echo ']>'; \
	sgmlnorm -m -n book-sid.sgml ) > book-sid.sgml.new
	mv -f book-sid.sgml.new book-sid.sgml

pdf:
	rm -rf PDF
	mkdir PDF
	db2pdf -i PRINTONLY book-sid.sgml
	mv book-sid.pdf PDF
	rm -f book-sid.out

html:
	rm -rf HTML
	mkdir HTML
	db2html -i HTMLONLY -o HTML book-sid.sgml
	rm -rf book-sid
