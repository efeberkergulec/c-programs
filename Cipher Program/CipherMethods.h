#ifndef CIPHER_METHODS_H_INCLUDED
#define CIPHER_METHODS_H_INCLUDED

#include "Basics.h"

extern char *encryptCaesar(const char *org_text);

extern char *decryptCaesar(const char *cip_text);

extern char *encryptVigenere(const char *org_text);

extern char *decryptVigenere(const char *cip_text);

#endif //CIPHER_METHODS_H_INCLUDED

