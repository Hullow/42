#### [What Is an X.509 Certificate? ](https://www.ssl.com/faqs/what-is-an-x-509-certificate/)
**X.509** is a standard format for **public key certificates**, digital documents that securely associate cryptographic key pairs with identities such as websites, individuals, or organizations.

First introduced in 1988 alongside the X.500 standards for electronic directory services, X.509 has been adapted for internet use by the IETF’s Public-Key Infrastructure (X.509) (PKIX) working group. 
Common applications of X.509 certificates include:

- [SSL/TLS](https://www.ssl.com/faqs/faq-what-is-ssl/) and [HTTPS](https://www.ssl.com/faqs/what-is-https/) for authenticated and encrypted web browsing
- Signed and encrypted email via the [S/MIME](https://www.ssl.com/article/sending-secure-email-with-s-mime/) protocol
- [Code signing](https://www.ssl.com/faqs/what-is-code-signing/)
- [Document signing](https://www.ssl.com/s-mime-client-and-document-signing-certificates/)
- [Client authentication](https://www.ssl.com/s-mime-client-and-document-signing-certificates/)
- [Government-issued electronic ID](https://www.ssl.com/article/pki-and-digital-certificates-for-government/)

No matter its intended application(s), each X.509 certificate includes a **public key**, **digital signature**, and information about both the identity associated with the certificate and its issuing **certificate authority (CA)**.


### [**Privacy-Enhanced Mail** (**PEM**)](https://en.wikipedia.org/wiki/Privacy-Enhanced_Mail)
A [de facto](https://en.wikipedia.org/wiki/De_facto "De facto") file format for storing and sending cryptographic [keys](https://en.wikipedia.org/wiki/Key_(cryptography) "Key (cryptography)"), [certificates](https://en.wikipedia.org/wiki/Public_key_certificate "Public key certificate"), and other data, based on a set of 1993 [IETF](https://en.wikipedia.org/wiki/Internet_Engineering_Task_Force "Internet Engineering Task Force") standards defining "privacy-enhanced mail." While the original standards were never broadly adopted and were supplanted by [PGP](https://en.wikipedia.org/wiki/Pretty_Good_Privacy "Pretty Good Privacy") and [S/MIME](https://en.wikipedia.org/wiki/S/MIME "S/MIME"), the textual encoding they defined became very popular. The PEM format was eventually formalized by the IETF in [RFC 7468](https://tools.ietf.org/html/rfc7468 "rfc:7468").

PEM data is commonly stored in files with a ".pem" suffix, a ".cer" or ".crt" suffix (for certificates), or a ".key" suffix (for public or private keys).[[3]](https://en.wikipedia.org/wiki/Privacy-Enhanced_Mail#cite_note-3) The label inside a PEM file represents the type of the data more accurately than the file suffix, since many different types of data can be saved in a ".pem" file. In particular PEM refers to the header and base64 wrapper for a binary format contained within, but does not specify any type or format for the binary data, so that a PEM file may contain "almost anything base64 encoded and wrapped with BEGIN and END lines".