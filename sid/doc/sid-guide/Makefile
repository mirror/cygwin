
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
	mv -f book-sid.sgml book-sid.sgml.bak
	sgmlnorm -d -n book-sid.sgml.bak > book-sid.sgml && rm -f book-sid.sgml.bak

pdf:
	rm -rf PDF
	mkdir PDF
	db2pdf book-sid.sgml
	mv book-sid.pdf PDF
	rm -f book-sid.out

html:
	rm -rf HTML
	mkdir HTML
	db2html -o HTML book-sid.sgml
	rm -rf book-sid
