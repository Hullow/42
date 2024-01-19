---
aliases:
  - computing-notes
tags:
  - computer-science
---
### [Bit numbering](https://en.wikipedia.org/wiki/Bit_numbering)
#### [Most significant bit (MSb)](https://en.wikipedia.org/wiki/Bit_numbering#Most_significant_bit)
a.k.a. the *high-order bit* or *left-most bit*. The highest-order place of the binary integer.

#### Least significant bit (MSb)
a.k.a. *low-order bit* or *right-most bit*, due to convention in positional notation of writing less significant digits further to the right.

[Two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)
- The most common method of representing signed (positive, negative, zero) integers on computers, and more generally, [fixed point binary](https://en.wikipedia.org/wiki/Fixed-point_arithmetic) values.
- Uses the binary digit with the greatest place value (MSb, see above) to indicate if positive (1) or negative (0).
- General method: take the absolute value of the number, invert all bits, add 1 to the entire inverted number, ignoring any overflow (n.b.: accounting for overflow will produce the wrong value).


## [Emulation](https://stackoverflow.com/questions/6234711/what-are-the-specific-differences-between-an-emulator-and-a-virtual-machine)
Emulation is using software to provide a different execution environment or architecture. In other words, emulators emulate hardware, aiming to accurately reproduce its behavior, including quirks and bugs. Given that software fills in for hardware, the processor takes a toll by allocating cycles to the emulation process, which therefore cannot be used to execute calculations. 
### vs virtualization
- Both aim for some level of independence from the hardware of the host machine
## Virtualization
A virtual machine's purpose is to create an isolated environment, allowing to raise virtual barriers between multiple virtual environments running isolated from each other in the same physical environment.
### [Full virtualization](https://www.virtualbox.org/wiki/Virtualization)
"Allows an ***unmodified*** operating system with all of its installed software to run in a special environment, a **virtual machine**, on top of [an existing] system. This process is created by intercepting access to certain hardware components and certain features. This approach, called "**native virtualization**" is different from emulation, where machine instructions are translated ("emulated"). Emulators typically allow running code written for one type of hardware on completely different hardware (e.g. 64-bit code on 32-bit hardware), they tend to be quite slow, whereas virtualizers can achieve near-native performance for the guest code, but can only run guest code that was written for the same hardware (e.g. 32-bit Linux on a 32-bit Windows host).
- "**Host**": the physical computer
- "**Guest**": the virtual machine

### [Benefits of using VMs](https://www.virtualbox.org/wiki/Virtualization) 
	- run software for other OS without rebooting
	- pack many VMs on a few powerful machines (e.g. servers), and enable efficient use of infrastructure
	- testing and disaster recovery – mess with a computing environment with little consequence: switching back easily to a previous snapshot and avoid need for frequent backups and restores. for instance when a physical server crashes, data recovery can be complicated, whereas switching to a VM snapshot is relatively simple.
	- security of data: isolate services on different (virtual) servers, limiting e.g. the risk of malware propagation in case of malware intrusion ([source](https://42-cursus.gitbook.io/guide/rank-01/born2beroot/whats-a-virtual-machine))
### [VirtualBox](https://www.virtualbox.org/manual/)
A *hosted*, a.k.a. *type 2* **hypervisor** (a.k.a. virtual machine monitor VMM), which requires a host operating system to run, as opposed to *bare-metal*, *type 1* hypervisors which runs directly on the hardware (more often used in industry)
#### [Disk image files](https://www.virtualbox.org/manual/ch05.html#vdidetails)
#storage
Reside on the host system and are seen by the guest systems as hard disks of a certain geometry. Can be expanded after creation, even if it has data already.
Types:
- Virtual Disk Image/VDI (VirtualBox container format for guest hard disks) ^1f390e
- Virtual Machine Disk/VMDK (popular format used by other virtualization products like VMware)
- Virtual Hard Disk/VHD (Microsoft's format)
- HDD (Parallels v2)
Options:
- fixed-size: image roughly the same size as the virtual disk's capacity. slower to create.
- dynamically allocated: grows every time a disk sector is written for the first time, until it reaches the maximum capacity chosen. Requires additional computing resources and write operations may be slower until the disk file size has stabilized, but mostly in the beginning when the rate of growth is high. fast to create, uses very little storage initially.

### [ISO image](https://en.wikipedia.org/wiki/Optical_disc_image)
"An optical disk image or ISO image is a disk image that contains everything that would be written to an optical disk, disk sector by disk sector, including the optical disk filet system. ISO images contain the binary image of an optical media file system (usually [ISO 9660](https://en.wikipedia.org/wiki/ISO_9660), a file system for optical disk media, or UDF)"

## Booting
#### [Boot sector](https://en.wikipedia.org/wiki/Boot_sector)
the sector of a persistent data storage device (e.g. hard disk, floppy disk, optical disk, etc.) containing machine code to be loaded into RAM and then executed by a computer system's built-in firmware (e.g. the [[Programming-notes#^e7c5f7 |BIOS]]). Usually the very first sector of the hard disk, regardless of sector size (512 or 4096 bytes) and partitioning flavor (MBR or [GPT/GUID Partition Table](https://en.wikipedia.org/wiki/GUID_Partition_Table))
#### [Master boot record](https://en.wikipedia.org/wiki/Master_boot_record) (MBR) partition scheme
a special type of boot sector at the very beginning of partitioned computer mass storage devices like fixed discs or removable drives intended for use with IBM PC-compatible systems and beyond. The MBR holds the information on how the disc's sectors (aka "blocks") are divided into partitions, each partition notionally containing a file system. The MBR also contains executable code to function as a loader for the installed operating system – this MBR code is usually referred to as a [[Programming-notes#^e6240f |boot loader]].  ^6da68e
#### [GUID Partition Table](https://en.wikipedia.org/wiki/GUID_Partition_Table)
a standard for the layout of partition tables of a physical computer storage device, such as an HDD or a solid-state drive, using universally unique identifiers, also known as globally unique identifiers (GUIDs). All modern PC OSes support GPT. GPT has less limits than MBR and does not need to use extended/logical partitions.

## Partitioning 
#storage
Sources: "[LVM vs partitioning (Red Hat)](https://www.redhat.com/sysadmin/lvm-vs-partitioning)", [42 Gitbook](https://42-cursus.gitbook.io/guide/rank-01/born2beroot/install-your-virtual-machine)
- "*traditional storage management*" : the process of partitioning, formatting, and mounting storage capacity from a basic hard disk drive (HDD)
=> admins think of storage based on max capacity of individual HDDs (e.g. 3 * 1TB => "I have three HDDs of one TB)
- disk partitioning or disk slicing
### **Primary** vs **logical** partitioning scheme
in the legacy [[Programming-notes#^6da68e|Master boot record]], only at most four partitions (called "primary") can be created; this limit can be bypassed by making one of them an "extended" partition (a.k.a. "[extended boot record](https://en.wikipedia.org/wiki/Extended_boot_record)"), which contains several "logical" partitions instead of files. Some OS's (such as Windows) are unable to boot from logical partitions (from [superuser](https://superuser.com/questions/337146/what-are-the-differences-between-primary-and-logical-partition))
```
	MBR: < primary | primary | primary | primary >
	MBR: < primary | primary | extended [logical, logical, logical] >
```
#### [Logical Volume Manager (LVM)](https://www.redhat.com/sysadmin/lvm-vs-partitioning)
LVM can be thought of as "dynamic partitions" which can be created/resized/deleted from the CLI while Linux is running, without needing to reboot the system to make the kernel aware of the partitioning changes. It combines the capacity of the available *Physical Volumes* (PV), which are then added to *Volume Groups* (VGs). VGs are then carved into one or more *Logical Volumes* (LVs), which are then treated as traditional partitions. LVMs allow for easy capacity reallocation; for instance if too much capacity was allocated to one VG, it can be reduced and added to another


### [Character vs block devices](https://www.baeldung.com/linux/dev-directory)
- Character special files are [[Linux#^dccf41|device files]] that interface to **character devices**, with which drivers communicate by sending single characters as data such as bytes. In addition, they don't require buffering when communicating with a driver. Examples: sound cards, serial ports, ptys.
- Block special files are device files that interface to **block devices**, with which drivers communicate by sending entire blocks of data. Examples: hard disks, USBs
- Identification: the first letter of the permissions (`ls -l`) : `c` or `d`

## Swap memory/area/space
- definition: section of a computer's hard disk or SSD that the OS uses to store inactive data from RAM/area on a hard disk which is part of the Virtual Memory of your machine
- two types: swap partition, swap file

## OS concepts and terminology
### [BIOS](https://www.intel.com/content/www/us/en/gaming/resources/how-to-update-bios.html#:~:text=BIOS%20stands%20for%20Basic%20Input,and%20load%20your%20operating%20system.)

^e7c5f7

Basic Input/Output System: "firmware that loads before your operating system, performing startup procedures that check system devices (from RAM to hard drive to keyboard) and load the operating system"

### [Boot loader](https://en.wikipedia.org/wiki/Bootloader)

^e6240f

A program that is responsible for booting a computer. 
#### First-stage boot loaders
[[Programming-notes#^e7c5f7|BIOS]], UEFI, coreboot, ...
(N.b.: the BIOS is not a boot loader, it loads a boot loader.)
#### Second-stage boot loaders
[GNU GRUB](https://en.wikipedia.org/wiki/GNU_GRUB), rEFInd, BOOTMGR, Syslinux, ... load an operating system properly and transfer execution to it; the OS subsequently initializes itself and may load extra device drivers. The ssbl does not require drivers for its own operation but may instead use generic storage access methods provided by system firmware such as the BIOS or Open Firmware. Can often be configured to give the user multiple booting choices: different OSes, versions of the same OS, loading options (e.g. booting into a rescue or safe mode), and some standalone programs that can function without an operating system, such as memory testers, a basic shell, or even games. 
^428b1b


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
#### Ext4
##### History
- Origin: Linus Torvalds didn't want to write a filesystem and so simply included the filesystem of Minix, a UNIX-like educational OS written by Andrew S. Tanenbaum, which was open source and appropriately licensed for Linus's purposes
- Minix structures:

## CPU
### CPU architecture
A CPU core, or processing unit, can only carry out one task at a time, which lead to the emergence of technologies of parallel processing:
#### Multi-processor
Two or more physical CPUs integrated into a single computer system
#### Multi-core
A single physical CPU with two or more separate cores (/processing units) that work in parallel
### Hyper threading
A single physical CPU core appears as two logical CPUs to an operating system (developed by Intel)
### CPU load versus usage
- **CPU load** is the number of processes using or waiting to use one core at a single point in time. E.g. for a single-core system, a CPU load average always below 0.6 means every process needing the CPU can use it. If the CPU load average is above 1, this indicates there are processes that cannot use the CPU at the moment due to its unavailability (n.b.: in a multi-core system, this isn't a problem).