
all:
	@echo "make targets:"
	@echo
	@echo "check:     SGML correctness check"
	@echo "normalize: SGML canonical formatting"
	@echo "pdf:       Create PDF"
	@echo "html:      Create HTML"

check:
	sgmlnorm -e book-cdk.sgml > /dev/null

normalize:
	(echo '<!DOCTYPE BOOK PUBLIC "-//Davenport//DTD DocBook V3.0//EN" ['; \
	echo '<!ENTITY % PRINTONLY "IGNORE">'; \
	echo '<!ENTITY % HTMLONLY "IGNORE">'; \
	echo ']>'; \
	sgmlnorm -m -n book-cdk.sgml ) > book-cdk.sgml.new
	mv -f book-cdk.sgml.new book-cdk.sgml

pdf:
	rm -rf PDF
	mkdir PDF
	db2pdf -i PRINTONLY book-cdk.sgml
	mv book-cdk.pdf PDF
	rm -f book-cdk.out

html:
	rm -rf HTML
	mkdir HTML
	db2html -i HTMLONLY -o HTML book-cdk.sgml
	rm -rf book-cdk
