## Access control
### Mandatory access control

^ccbb7a

> An access control policy that is uniformly enforced across all subjects and objects within the boundary of an information system. A subject that has been granted access to information is constrained from doing any of the following: 
> 	(i) passing the information to unauthorized subjects or objects;
> 	(ii) granting its privileges to other subjects;
> 	(iii) changing one or more security attributes on subjects, objects, the information system, or system components;
> 	(iv) choosing the security attributes to be associated with newly-created or modified objects; or
> 	(v) changing the rules governing access control.
> Organization-defined subjects may explicitly be granted organization-defined privileges (i.e., they are trusted subjects) such that they are not limited by some or all of the above constraints.

Source: [US CNSS via NIST](https://csrc.nist.gov/glossary/term/mandatory_access_control)

## SSH
- error when copying SSH key from 42iMac-on-OS-X to 42iMac-on-Ubuntu:
> sign_and_send_pubkey: signing failed for RSA "/home/fallan/.ssh/id_rsa" from agent: agent refused operation
git@vogsphere.42lausanne.ch: Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
```
solution (thanks Rui !): change permissions from `-rw-r--r--` to `-rw-------` with `chmod 600 id_rsa`
=> you need to be the only one who can read and write from and to the private key(s)