
## Credentials:
- Root password: Keychain-1993 (old: Debianunlock-1993)
- Additional user full name: Francis
- Additional user username: fallan
- Passwords:
	- (disk: still Debianunlock-1993)
	- fallan: password-2024 (nb: error message when shorter than 9 characters, and when trying to change right after, but no error for lack of uppercase character)
	- testusr: password-2025
- MariaDB: db name 'wordpress', user 'wordpressuser', password 'webadmin-1991'

## Commands:

### Partitioning
- `lsblk` to list storage volumes (partitions) ^9f40d4
### Package management
- `apt list su* --installed` to show all installed packages starting with "su" ^b03539
### Users
- `chage -l <\username>` : see age information of user password
## Server
### Lighttpd
Lighttpd ("Lighty") is a light FOSS server software. Lighter than Apache so more efficient.
- `sudo lighttpd -tt -f /etc/lighttpd/lighttpd.conf` to check the configuration
- `sudo lighttpd -D -f /etc/lighttpd/lighttpd.conf` start lighttpd directly in the foreground and not in the background as a daemon, without using systemd. To use when testing or debugging in the console, and systemctl for regular operation and production environments
- `sudo systemctl start/stop/restart/reload lighttpd` : running, stopping, restarting, reloading the server using systemd (init-V systems use the `service` command)
- `sudo systemctl enable lighttpd` 
- `sudo systemctl status lighttpd`
- `sudo lighttpd -D -f /etc/lighttpd/lighttpd.conf`: 
- data handled by the www-data user (and group) and in the `/var/www/servers` folder
- `sudo lighttpd-enable-mod` : to enable modules but not used afair
### PHP and HTML webpages
- `vim /var/www/servers/hello.php/index.html` to modify webpage
- FastCGI setup: see Lighttpd.conf file + .../..../php.ini `cgi.fix....=1;`
- ddd

### MariaDB
- `sudo mysql -u root -p` : to start MariaDB interactive prompt
- ddd
- 
- 
### Wordpress
- configuration file: /usr/share/wordpress/wpconfig.php
- set up 
## Questions/Answers
- Pourquoi Debian ?
	- plus simple, utilise partout
- LVM: a dynamic partition. Physical disks are united into Volume groups, which are then subdivided into logical volumes. LVM allows for dynamic partitioning, i.e. during system run, no need to reboot.
- apt vs aptitude: aptitude is a front-end to APT (Advanced Package Tool), the Debian (and Debian-based distros) native package manager tool. APT automates the retrieval, configuration and installation of software packages, from precompiled files or by compiling source code. APT is technically a frontend on dpkg
- Debian vs Rocky:
	- Debian: community Linux distribution, since 1993 (the 2nd oldest distro still active). Debian based include Ubuntu, Mint and Kali
	- Rocky developed by Rocky Software Foundation to continue CentOS (discontinued 2020). RHEL-based, focused on entreprise customers
- AppArmor vs SELinux: 
	- SELinux:
			- used in RHEL (Red Hat Entreprise Linux)
			- Built into Debian kernel but disabled. Can be installed
			- quite complex to use, leading many sysadmins to disable it, which causes security risks.
		- a Linux kernel module providing secure mechanisms for supporting access control security policies. For instance, SELinux can determine file mode modification policy in a way that is not changeable, and adds granularity to access control (who can unlink, append only, move a file, etc.), including for non-file resources like network and interprocess communications.
		- check if enabled: `sudo getenforce`
	- AppArmor:
			- Used in Ubuntu and Debian
			- Much easier to learn and use than SELinux, thus often considered the safer choice
			- Uses profiles to determine what files and permissions an application requires
			- Security policies based on paths
			- Provides [[Security-notes#^ccbb7a|Mandatory Access control]]
		- Checking if AppArmor is active: `sudo /usr/sbin/aa-status`
- SSH: `sudo vim /etc/ssh/sshd_config`: uncomment line "Port 22" and change to "Port 4242" (check with sudo grep Port /etc/ssh/sshd_config)
- Hostname: `hostname` to display current hostname, `sudo hostnamectl hostname <new_hostname>` to change name,  `hostnamectl` to display more details
- UFW: `sudo ufw enable,  ufw allow ssh, ufw allow 4242, ufw status, ufw delete [X] ddd`
- User permissions and groups: 
	- `groups fallan`: display group membership of user fallan
	- `groupadd --users fallan user42` to create user42 group with fallan in it
	- `getent group sudo` : list users part of the sudo group ^7fc8e8
	- `usermod -aG sudo <username>` ^77cbc1 (append Groups)
- Password policy: `sudo apt install libpam-pwquality`
	- What is PAM: a suite of libraries to configure methods to authenticate users, providing a flexible and centralized way to handle authentication methods for secured applications through configuration files rather than application code.
	- modified `/etc/login.defs` with sudo:
	```bash
	PASS_MAX_DAYS  30
	PASS_MIN_DAYS  2
	PASS_WARN_AGE  7
	```
	(n.b.: this setting only impact when creating a user)
	- used `chage --mindays 2 --maxdays 30 --warndays 7 fallan` and `chage --mindays 2 --maxdays 30 --warndays 7 root
	- PAM:
		- `/etc/security/pwquality.conf`
			- difok = 7, minlen = 10, dcredit = 1, ucredit = 1, lcredit = 1, maxrepeat = 3, usercheck = 1, enforce_for_root
- Configuration sudo:
	- `sudo visudo /etc/sudoers`:
	- Defaults    badpass_message="Wrong password, please retype"
	- Defaults    passwd_tries=3
	- Defaults    logfile="/var/log/sudo/sudo.log". ==> file to write logs to
	- Defaults    log_input, log_output ==> to log I/O for sudo
	- Defaults    requiretty.    ==> forces sudo to require we are in a logged in tty session. test with `ssh -T localhost 'sudo test'`=> should return `sudo: sorry, you must have a tty to run sudo`. See [article](https://www.baeldung.com/linux/sudo-requiretty-option)
	- usable paths: left as is (`/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/`)
- cf TTYs: "*While Linux systems can have multiple TTYs, their number is usually limited by the configuration. Actually, we can change this by modifying _/etc/init/tty*.conf_, _/etc/securetty_, _/etc/systemd/logind.conf, or similar configuration files depending on the Linux distribution._" (same [article](https://www.baeldung.com/linux/sudo-requiretty-option) as above)

- 