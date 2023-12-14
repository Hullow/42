### [Bit numbering](https://en.wikipedia.org/wiki/Bit_numbering)
#### [Most significant bit (MSb)](https://en.wikipedia.org/wiki/Bit_numbering#Most_significant_bit)
a.k.a. the *high-order bit* or *left-most bit*. The highest-order place of the binary integer.

#### Least significant bit (MSb)
a.k.a. *low-order bit* or *right-most bit*, due to convention in positional notation of writing less significant digits further to the right.

[Two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)
- The most common method of representing signed (positive, negative, zero) integers on computers, and more generally, [fixed point binary](https://en.wikipedia.org/wiki/Fixed-point_arithmetic) values.
- Uses the binary digit with the greatest place value (MSb, see above) to indicate if positive (1) or negative (0).
- General method: take the absolute value of the number, invert all bits, add 1 to the entire inverted number, ignoring any overflow (n.b.: accounting for overflow will produce the wrong value).

## Virtualization
### [Full virtualization](https://www.virtualbox.org/wiki/Virtualization)
"Allows an ***unmodified*** operating system with all of its installed software to run in a special environment, a **virtual machine**, on top of [an existing] system. This process is created by intercepting access to certain hardware components and certain features. This approach, called "**native virtualization**" is different from emulation, where machine instructions are translated ("emulated"). Emulators typically allow running code written for one type of hardware on completely different hardware (e.g. 64-bit code on 32-bit hardware), they tend to be quite slow, whereas virtualizers can achieve near-native performance for the guest code, but can only run guest code that was written for the same hardware (e.g. 32-bit Linux on a 32-bit Windows host).
- "**Host**": the physical computer
- "**Guest**": the virtual machine

### [Benefits of using VMs](https://www.virtualbox.org/wiki/Virtualization)
	- run software for other OS without rebooting
	- pack many VMs on a few powerful machines (e.g. servers), and enable efficient use of infrastructure
	- testing and disaster recovery – mess with a computing environment with little consequence: switching back easily to a previous snapshot and avoid need for frequent backups and restores
### [VirtualBox](https://www.virtualbox.org/manual/)
A *hosted*, a.k.a. *type 2* **hypervisor**, which requires a host operating system to run, as opposed to *bare-metal*, *type 1* hypervisors which runs directly on the hardware
#### [Disk image files](https://www.virtualbox.org/manual/ch05.html#vdidetails)
Reside on the host system and are seen by the guest systems as hard disks of a certain geometry. Can be expanded after creation, even if it has data already.
Types:
- Virtual Disk Image/VDI (VirtualBox container format for guest hard disks)
- Virtual Machine Disk/VMDK (popular format used by other virtualization products like VMware)
- Virtual Hard Disk/VHD (Microsoft's format)
- HDD (Parallels v2)
Options:
- fixed-size: image roughly the same size as the virtual disk's capacity. slower to create.
- dynamically allocated: grows every time a disk sector is written for the first time, until it reaches the maximum capacity chosen. Requires additional computing resources and write operations may be slower until the disk file size has stabilized, but mostly in the beginning when the rate of growth is high. fast to create, uses very little storage initially.

## [Partitioning](https://www.redhat.com/sysadmin/lvm-vs-partitioning)
- "*traditional storage management*" : the process of partitioning, formatting, and mounting storage capacity from a basic hard disk drive (HDD)
=> admins think of storage based on max capacity of individual HDDs (e.g. 3*1TB => "I have three HDDs of one TB)
- disk partitioning or disk slicing

## OS concepts and terminology
### [BIOS](https://www.intel.com/content/www/us/en/gaming/resources/how-to-update-bios.html#:~:text=BIOS%20stands%20for%20Basic%20Input,and%20load%20your%20operating%20system.)
Basic Input/Output System: "firmware that loads before your operating system, performing startup procedures that check system devices (from RAM to hard drive to keyboard) and load the operating system"

### DOS: disk operating system, an operating system that runs from a disk drive

### [Filesystem](https://opensource.com/article/17/5/introduction-ext4-filesystem)
Components:
- *Data storage*: a structured place to store and retrieve data
- *Namespace*: a naming and organizational methodology for naming and structuring data
- *Security model*: a scheme for defining access rights
- *API*: system function calls to manipulate filesystem objects like directories and files
- *Implementation*: the software to implement all these components

#### [Mount point](https://www.techtarget.com/whatis/definition/mount-point)
- A directory on a filesystem that is logically linked to another filesystem. Mount points allow data present on different physical devices and logical volumes to be put on the same filesystem, allowing all data needed on the system to be accessed from the root directory. 
- Virtual machines and containers make extensive use of mount points. Servers also use mount points, for instance to enable use of network-attached storage devices (a mount point is made on the server pointing to the NAS data).
- The `mount` command is used to make a device or file system accessible to the system, and then to connect its root directory to a mount point on the local file system. The mount point location is typically an empty folder.

### Linux filesystems
#### Ext4
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures:
	- boot sector: the sector of a persistant data storage device containing machine code to be loaded into RAM and then executed by a computer system's built-in firmware (e.g. the BIOS). Usually the very first sector of the hard disk, regardless of sector size (512 or 4096 bytes) and partitioning flavor (MBR or GPT)
	- 


## Linux

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


