#linux
## Linux filesystems
#### Ext4
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures:

## Security
#security
### Password policies
Using sudo, one can do things prohibited by /etc/login.defs, because root can do pretty much anything. For instance, setting PASS_MIN_DAYS to 2 prevents a user from changing their password for two days, but `sudo passwd <username>` will still work.

### [Linux PAM (Pluggable Authentication Modules)](https://en.wikipedia.org/wiki/Linux_PAM)
	See: "man pam"
- A suite of libraries that allow Linux sysadmins to configure methods to authenticate users. It provides a flexible and centralized way to switch authentication methods for secured applications by using configuration files instead of changing application code.
- Separates the tasks of authentication into four independent management groups:
	- account management
	- authentication management
	- password management
	- session management (things to be done prior to a service being given and after it is withdrawn; e.g. maintenance of audit trails, mounting of the user's home directory)
### Security enhancement modules
#### SELinux
- "Security-Enhanced Linux (SELinux) is a Linux kernel security module that provides a mechanism for supporting access control security policies, including mandatory access controls (MAC). SELinux is a set of kernel modifications and user-space tools that have been added to various Linux distributions." (Wikipedia)
- [Developed by the NSA](https://web.archive.org/web/20201022103915/https://www.nsa.gov/what-we-do/research/selinux/), handed over to the Linux community in 2008.
- [Self-definition](https://selinuxproject.org/page/Main_Page): "a security enhancement to Linux which allows users and administrators more control over access control":
	- Standard Linux access controls like file modes are modifiable by the user and applications the user runs, whereas SELinux access controls are determined by a policy loaded on the system which can not be changed.
	- SELinux also adds finer granularity to ACs, e.g. by letting one specific who can unlink, append only, move a file, etc. It also works on non-file resources such as network resources and interprocess communication (IPC)
- Used in RHEL([Red Hat Entreprise Linux](https://en.wikipedia.org/wiki/Red_Hat_Enterprise_Linux))-based distributions ([source](https://www.techtarget.com/searchdatacenter/tip/Compare-two-Linux-security-modules-SELinux-vs-AppArmor))
- Highly complex to use, sometimes leading admins to disable it, leaving systems vulnerable ([source](https://www.techtarget.com/searchdatacenter/tip/Compare-two-Linux-security-modules-SELinux-vs-AppArmor))
[SELinux](https://en.wikipedia.org/wiki/Security-Enhanced_Linux)

### AppArmor
- Uses profiles to determine what files and permissions an application requires
- Security policies based on paths
- Provides mandatory access control
- Certain features used differently by each system
- Much easier to learn and use than SELinux, thus often considered the safer choice ([source](https://www.techtarget.com/searchdatacenter/tip/Compare-two-Linux-security-modules-SELinux-vs-AppArmor))
- Used in Ubuntu/Debian distributions among others


^14c7ce
