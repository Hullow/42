## Servers
### Lighttpd
- `lighttpd -tt -f path/to/lighttpd.conf`
- dd
### MariaDB/MySQL
- `sudo mysql -u root -p` : login to mysql as user root (-p)
- `SHOW DATABASES;` shows databases
- `SELECT User, Host FROM mysql.user;` show users
- `USE <database_name>;` selects a database to work with
- `SHOW TABLES;` list all tables in the selected database
- `DESCRIBE <table_name>` : view the structure of a specific table
- `SHOW TABLE STATUS;` : get more detailed information about tables, including storage engine, row format, and table size