#linux
## Linux filesystems
Linux and Unix-like operating systems follow a Filesystem Hierarchy Standard (FHS), which defines the structure of the file system, i.e. the main directories and their contents.

See `man 7 file-hierarchy`

### [Directory structure/Filesystem hierarchy](linuxfoundation.org/blog/blog/classic-sysadmin-the-linux-filesystem-explained)
#### [/dev](https://www.baeldung.com/linux/dev-directory)

^dccf41

Consists of files, named device files or special files, representing devices that are attached to the local system. These special files help the user interface with the various devices on the system. 

#### [/etc](https://www.linux.com/training-tutorials/linux-directory-structure-explainedetc-folder/)
- The `/etc` directory contains most, if not all *system-wide configuration files*
- Examples: name of the system, users and their passwords, names of machines on the network, when and where partitions on hard disks should be mounted, and so on.
- Origin of the name and history: "etcaetera", because in the initial days of UNIX there was a folder for each type of data like `/bin` for all executable binaries, `/boot` for all booting related information, and `/dev` for all hardware devices attached to the machine. The `/etc` directory was added to keep other files: config files, data files, socket file, and some other files. The meaning of the folder changed to be a **central location for all configuration files**, but the old name stayed.
- Mnemotechnic: "everything to configure"

#### /home
- Users' personal directories

#### /lib
- Where libraries live, i.e. files containing code that applications use. For instance, snippets of code that applications use to draw windows on the desktop, control peripherals, send files to the hard disk, etc.
- There are more *lib* directories scattered around the file system, but this one contains the all-important kernel modules. These are drivers that make things like the video card, sound card, WiFi, printer, etc. work.

#### /media
- Where external storage is automatically mounted when plugged in
- More recent than other root directories (i.e. not from the 1970s), because inserting and detecting storage (pendrives, USB hard disks, SD cards, external SSDs, etc.) on the fly, while a computer is running, is a relatively new thing

#### /mnt
- Where storage devices and partitions would be manually mounted. A bit of a remnant from the past, and not so used today.

#### /opt
- Where software locally built and compiled sometimes lands. Applications end up in the `/opt/bin` directory and libraries in `/opt/lib`.

#### /proc
- A virtual directory like `/dev`. Contains information about the computer, e.g. the CPU and kernel. As with `/dev`, the files and directories are generated when the computer starts, or on the fly, as the system is running and things change

#### /root
Home directory of the superuser (also known as the Administrator of the system). Separate from the other users' home directories because it is not meant to be touched

#### /run
Used by system processes to store temporary data

#### /sbin
Similar to `/bin`, but containing applications that only the superuser will need. Typically contains tools that can install, delete and format stuff.

#### /usr
- Where the users' home directories were originally kept in the early days of Unix. Today, contains a mish-mash of directories which in turn contain applications, libraries, documentation, wallpapers, icons, and other things that need to be shared by applications and services. It contains `usr/bin`, `usr/sbin`, `usr/lib` directories as well. Originally, the most basic commands were in `/bin`, like `ls`, `mv` and `rm`, while `/usr/bin` contained other applications such as word processors, web browsers, etc. However, many Linux distributions, including Debian and Ubuntu, put everything is `/usr/bin` and `/usr/sbin` and have `/bin` and `/sbin` point to it.

#### /srv
Contains data for servers, e.g. HTML files for web servers go into `/srv/http`, whereas FTP server files would go into `/srv/ftp`

#### /sys
Another virtual directory like `/proc` and `/dev`, also containing information from devices connected to the computer. In some cases, it can manipulate those devices, e.g. device brightness

#### /tmp
Contains temporary files, usually placed there by applications that are running. Oftentimes, these files and directories contain data than an application doesn't need right now, but may need later on. It can also be accessed and used by regular users (i.e. non superusers) to store temporary files; one of the few directories hanging off `/` that such users can interact with


#### /var
- Originally given its name because its contents were deemed *variable*, in that they changed frequently; today, there are many other directories in this case (especially the virtual directories), which makes it a bit of a misnomer. 
- Contains things like logs in the `/var/log` subdirectories. Logs are files that register events that happen on the system (kernel failures, attempts to break into the computer-> logged by firewall, etc.).
- Also contains *spools* for tasks, e.g. jobs sent to a shared printer that have to wait because another user is printing a long document, or mail that is waiting to be delivered to users on the system.

#### Other directories (e.g. /snap)
- `/snap` packages are a way of distributing software; `/snap` is where all the fles and software is installed from snaps

See subdirectory structure on linuxfoundation.org (see above for link)

### Ext4 filesystem
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures: ...

#### Ext4 filesystem
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures: ...

#### Ext4
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures:



## Terminals and shells

In Linux, the shell is a command line interpreter (CLI).
### Shell types
- Interactive shell: receives commands from the user and displays output to the user
- Non-interactive shell: a shell that doesn't interact with the user, eg that can be run through a script or similar, or some automated processes. A shell running a script is always non-interactive, although it can emulate an interactive shell
- Login shell: `echo $0` => returns `-` if login shell. "A login shell loads the profile of the submission user whereas the non-login shell loads the default environment." ([forum](https://community.broadcom.com/communities/community-home/digestviewer/viewthread?MID=795300#:~:text=The%20difference%20is%20that%20with,use%20the%20non%2Dlogin%20shell.))
### Terminal types
- [A TTY](https://www.baeldung.com/linux/pty-vs-tty#what-is-a-tty) (teletypewriter) is a device that enables typing from a distance. Linux uses a device file to represent a virtual TTY, which enables interaction with the OS by handling input (usually a keyboard) and output (usually a screen).
- [A pseudo-TTY (PTY)](https://www.baeldung.com/linux/pty-vs-tty#what-is-a-pty) connects its input and output to the respective streams of another device, behaving like a TTY but for any two endpoints. Multiple PTYs can co-exist within the context of the same TTY. One of PTYs main function is to enable terminal emulators such as *xterm* or *GNOME terminal*, which request as many PTYs as it needs from the OS, often presenting them as tabs or windows in the GUI.
- PTS (as in `/dev/pts`): 
- Communication protocols like *ssh* and *telnet* depend on terminal emulation to interact with the OS. 
 Terminal allocation

## Security
#security
### File permissions
- `ls` on a directory requires both read (`r`) and execute (`x`) to list contents

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

## Distributions
- Distro version (e.g. Debian 12/Bookworm ; `cat /etc/os-release`) != Kernel version (e.g. Linux kernel 6.7 ; `uname -v`)
