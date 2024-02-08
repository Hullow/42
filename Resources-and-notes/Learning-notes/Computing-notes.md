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

## Memory
The physical devices used to store programs or data on a temporary or permanent basis. It is a group of basic registers

### Types of memory
#### Primary
Semiconductors, divided into Read-Only Memory (ROM) and Random Access Memory (RAM).

#### Secondary
A physical device for the permanent storage of programs and data (Hard disk, compact disk, flash drive, etc.), meaning even after the computer is turned off.

### [Virtual memory](https://www.geeksforgeeks.org/virtual-memory-in-operating-system/)
- A storage allocation scheme in which [secondary memory](#secondary) can be addressed as though it were part of the main memory. A memory hierarchy, consisting of a computer system’s memory and a disk, that enables a process to operate with only some portions of its address space in memory. A virtual memory is what its name indicates- it is an illusion of a memory that is larger than the real memory.

- Modern OSes [generally divide](https://www.educative.io/answers/what-is-the-difference-between-the-kernel-and-user-spaces) the virtual memory into [user space](#user space) and [kernel space](#kernel-space). The primary reason for this separation is to protect memory and hardware from malicious or third-party software's errant behavior.

#### [Page table](https://en.wikipedia.org/wiki/Page_table)
- A data structure used by a virtual memory system in a computer to store mappings between virtual addresses and physical addresses.
- Virtual addresses are used by the program executed by the accessing [process](#process), while physical addresses are used by the hardware or more specifically the RAM subsystem.

#### [Kernel space](https://www.educative.io/answers/what-is-the-difference-between-the-kernel-and-user-spaces)
- The memory space where the core of the operating system (kernel) executes and provides its services. It is reserved for running device drivers, OS kernel, and all other kernel extensions.
- One of the roles of the kernel is to manage all user processes or applications within user space and to prevent them from interfering.
- User process can access the kernel space through [system calls](#system-calls).
- Contains the page table for process, kernel data structure, threads, and kernel code
- Has full access to all memory and machine hardware

#### [User space](https://www.educative.io/answers/what-is-the-difference-between-the-kernel-and-user-spaces)
- The memory space where all user applications or application software executes. Everything other than OS cores and kernel runs here. It is thus a form of sandboxing. Also known as "userland".
- Contains the program code, data, stacks, and heap of the process.
- Has limited access to memory and access kernel through system calls only


#### CPU rings
The layers between the installed applications on a computer system and the core processes of the system. These structural rings are for the protection of the processes from interference. In x86 protected mode, the CPU is always in one of 4 rings. For example, the Linux kernel only uses 0, for the kernel space, and 3, for the user space.


### [System calls](https://en.wikipedia.org/wiki/System_call)
- The programmatic way in which a computer program requests a service from the operating system. In other words, the "tool" used by a software in the userspace to request a "service" to the kernel.
- Implementations: FreeBSD has over 400 system calls. In Linux, syscalls are implemented using CPU registers, whereas in BSD they are implemented using stack, where the parameters must be pushed before calling the syscall.
- May include hardware-related services (e.g. accessing a hard drive or the device's camera), creation and execution of new processes, and communication with integral kernel services such as process scheduling.

## [Process](https://en.wikipedia.org/wiki/Process_(computing))
The instance of a computer program that is being executed by one or many threads.

## [Handle](https://en.wikipedia.org/wiki/Handle_(computing))
>In computer programming, a handle is an abstract reference to a resource that is used when application software references blocks of memory or objects that are managed by another system like a database or an operating system.
> Common resource handles include file descriptors, network sockets, database connections, process identifiers (PIDs), and job IDs. 

## [Callback](https://en.wikipedia.org/wiki/Callback_(computer_programming))
A callback or callback function is any reference to executable code that is passed as an argument to another piece of code; that code is expected to *call back* (execute) the callback function as part of its job. This execution may be immediate as in a *synchronous callback* (also called *blocking callbacks* or simply *callbacks*), or at a later point in time as in an *asynchronous callback* (*non-blocking callbacks*). Programming languages support callbacks in different ways, often implementing them with subroutines, lambda expressions, blocks, or function pointers.

The following C code demonstrates the use of callbacks to display two numbers:
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The calling function takes a single callback as a parameter. */
void PrintTwoNumbers(int (*numberSource)(void)) {
    int val1 = numberSource();
    int val2 = numberSource();
    printf("%d and %d\n", val1, val2);
}

/* A possible callback */
int overNineThousand(void) {
    return (rand()%1000) + 9001;
}

/* Another possible callback. */
int meaningOfLife(void) {
    return 42;
}

/* Here we call PrintTwoNumbers() with three different callbacks. */
int main(void) {
    time_t t;
    srand((unsigned)time(&t)); // Init seed for random function
    PrintTwoNumbers(&rand);
    PrintTwoNumbers(&overNineThousand);
    PrintTwoNumbers(&meaningOfLife);
    return 0;
}
```
Example output:
```
16884 and 32191
9549 and 9456
42 and 42
```

# [Disk controller](https://en.wikipedia.org/wiki/Disk_controller)
The controller circuit which enables the CPU to communicate with a hard disk, a floppy disk, or other kind of disk drive. It also provides an interface between the disk drive and the bus connecting it to the rest of the system. 


## Programs

### [Interrupt](https://en.wikipedia.org/wiki/Interrupt)
In digital computers, an interrupt (sometimes referred to as a trap) is a request for the [processor](#cpu) to *interrupt* currently executing code (when permitted), so that the event can be processed in a timely manner. If the request is accepted, the processor will suspend its current activities, save its state, and execute a function called an interrupt handler (or *interrupt service routine*) to deal with the event. This interruption is often temporary, allowing the software to resume normal activities after the interrupt handler finishes, although the interrupt could instead indicate a fatal error.
Interrupts are commonly used by hardware devices to indicate electronic or physical state changes that require time-sensitive attention. Interrupts are also commonly used to implement computer multitasking and system calls, especially in real-time computing. Systems that use interrupts in these ways are said to be interrupt-driven.

#### Terminology
The terms *interrupt*, *trap*, *exception*, *fault*, and *abort* are used to distinguish types of interrupts, although "there is no clear consensus as to the meaning of these terms".

#### Types of interrupts
##### Hardware interrupts
A hardware interrupt is a condition related to the state of the hardware may be signaled by an external hardware device, e.g. an interrupt request (IRQ) line on a PC, or detected by devices embedded in processor logic (e.g., the CPU timer in IBM System/370), to communicate that the device needs attention from the operating system (OS), or, if there is no OS, from the bare metal program running on the CPU. Such external devices may be part of the computer (e.g. [disk controller](#disk-controller)), or they may be external peripherals. For example, pressing a keyboard key or moving a mouse plugged into a PS/2 port triggers hardware interrupts that cause the processor to read the keystroke or mouse position.
Hardware interrupts can arrive asynchronously with respect to the processor clock, and at any time during instruction execution. Consequently, all incoming hardware interrupt signals are conditioned by synchronizing them to the processor clock, and acted upon only at instruction execution boundaries.

##### Software interrupt
A software interrupt is requested by the processor itself upon executing particular instructions or when certain conditions are met. A software interrupt may be intentionally caused by executing a special instruction which, by design, invokes an interrupt when executed. Software interrupts may also be triggered by program execution errors or by the [virtual memory](#virtual-memory) system. Every software interrupt signal is associated with a particular interrupt handler.
Typically, the operating system will catch and handle such interrupts. Some are handled transparently to the program - for example, the normal resolution of a page fault is to make the required page accessible in physical memory. In other words, this transparent handling means that some interrupts are managed in a way that the program doesn’t even realize they occurred. For example, when a page fault happens (an attempt to access a portion of memory that is not currently in physical RAM), the operating system steps in to load the required data into RAM from the disk and then resumes the program execution as if nothing happened. This process is essential for virtual memory management, allowing the system to use disk space as an extension of RAM (from [ChatGPT explanation](https://chat.openai.com/share/3018844e-e773-4cb6-bd4d-f5d655a40e62)). But in other cases such as a [segmentation fault](#segmentation-fault) the operating system executes a process [callback](#callback). ChatGPT: the OS may terminate the program or trigger a specific response defined by the program (a callback). A process callback here is a specific function or set of instructions predefined by the application or system to deal with such errors. For instance, cleaning up resources, logging information about the fault for debugging purposes, or attempting a recovery operation.
On Unix-like OSes this involves sending a signal such as SIGSEGV, SIGBUS, SIGILL or SIGFPE, which may either call a signal handler or execute a default action (terminating the program). On Windows the callback is made using Structured Exception Handling with an exception code such as STATUS_ACCESS_VIOLATION or STATUS_INTEGER_DIVIDE_BY_ZERO.
In a kernel [process](#process), it is often the case that some types of software interrupts are not supposed to happen. If they occur nonetheless, an operating system crash may result.

#### Segmentation fault
A segfault or access violation is a [fault](#terminology), or failure condition, raised by hardware with memory protection, notifying an operating system the software has attempted to access a restricted area of memory (a memory access violation). On standard x86 computers, this is a form of general protection fault. The OS kernel will, in response, usually perform some corrective action, generally passing the fault on to the offending [process](#process) by sending the process a [signal](#signal). Processes can in some cases install a custom signal handler, allowing them to recover on their own, but otherwise the OS default signal handler is used, generally causing abnormal termination of the process (a program crash), and sometimes a core dump.

#### Bus error
>A [fault](#interrupt) raised by hardware, notifying an OS that a process is trying to access memory that the CPU cannot physically address: an invalid address for the address bus, hence the name. In modern use on most architectures these are much rarer than [segmentation faults](#segmentation-fault), which occur primarily due to memory access violations: problems in the logical address or permissions.

### Memory management of programs
#### General memory layout in C
Organised in segments, from lower to higher addresses in memory:
- Text segment: where the compiled program (machine code, a.out) resides. Read-only to prevent accidental modification of the program.
- [Data segment](https://en.wikipedia.org/wiki/Data_segment): size determined by size of the values in the source code, and does not change at run time. Is read/write.
	- Initialized variables: global, static and external variables that are explicitly initialized
	- [Uninitialized Data Section (BSS: block starting symbol)](https://en.wikipedia.org/wiki/.bss): contains the statically allocated variables that are declared but have not been assigned a value yet. Typically only its length is stored in the object file, to reduce the file's size, with the program loader allocating memory when it loads the program.
- Heap: used for dynamic memory allocation during program execution. Grows upward toward higher memory addresses.
- Stack: used for automatic memory allocation and deallocation as functions are called and return during the program execution. Stores local (automatic) variables, function parameters, return addresses, and is managed in LIFO (Last-In-First-Out). Grows downward toward lower memory addresses.


#### Call stack
A structure that tracks function calls and returns, ensuring that each function call leads back to the point from which it was called, in the correct order. Each time a function is called, a new frame is added to the call stack, which contains the function's parameters, local variables, and the return address.

## [Signal](https://en.wikipedia.org/wiki/Signal_(computing))

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