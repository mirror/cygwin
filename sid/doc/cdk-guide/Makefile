
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
	mv -f book-cdk.sgml book-cdk.sgml.bak
	sgmlnorm -d -n book-cdk.sgml.bak > book-cdk.sgml && rm -f book-cdk.sgml.bak

pdf:
	rm -rf PDF
	mkdir PDF
	db2pdf book-cdk.sgml
	mv book-cdk.pdf PDF
	rm -f book-cdk.out

html:
	rm -rf HTML
	mkdir HTML
	db2html -o HTML book-cdk.sgml
	rm -rf book-cdk
