###########################
# Pontificia Universidad Javeriana
#David Tobar Artunduaga
###############################

GCC = gcc

PROGRAMAS = lab01_Ficheros lab02_Ficheros lab03_Ficheros

lab01_Ficheros:
	$(GCC) $@.c -o $@

lab02_Ficheros:
	$(GCC) $@.c -o $@

lab03_Ficheros:
	$(GCC) $@.c -o $@

clean:
	$(RM) $(PROGRAMAS)
