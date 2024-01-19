# IP
- show my IPs (Linux): `ip a` => 

# SSH
- change passphrase of a private key: `ssh-keygen -p`
- SSH into a VM: `ssh -p <port> user@<ip-address-or-hostname>` (use `ip a` then take first inet IP without the part after /)

## Servers
### Lighttpd
- `lighttpd -tt -f path/to/lighttpd.conf`
- dd

### CGI (Common Gateway Interface)
>**Common Gateway Interface** (**CGI**) is an interface specification that enables [web servers](https://en.wikipedia.org/wiki/Web_server "Web server") to execute an external program to process HTTP/S user requests.
>
>Such programs are often written in a [scripting language](https://en.wikipedia.org/wiki/Scripting_language "Scripting language") and are commonly referred to as _CGI scripts_, but they may include [compiled](https://en.wikipedia.org/wiki/Compiler "Compiler") programs.
>
>A typical use case occurs when a web user submits a [web form](https://en.wikipedia.org/wiki/Web_form "Web form") on a web page that uses CGI. The form's data is sent to the web server within an [HTTP request](https://en.wikipedia.org/wiki/HTTP_request "HTTP request") with a [URL](https://en.wikipedia.org/wiki/URL "URL") denoting a CGI script. The web server then launches the CGI script in a new [computer process](https://en.wikipedia.org/wiki/Computer_process "Computer process"), passing the form data to it. The output of the CGI script, usually in the form of [HTML](https://en.wikipedia.org/wiki/HTML "HTML"), is returned by the script to the Web server, and the server relays it back to the browser as its [response](https://en.wikipedia.org/wiki/HTTP_response "HTTP response") to the browser's request.
>
Developed in the early 1990s, CGI was the earliest common method available that allowed a web page to be interactive. Due to a necessity to run CGI scripts in a separate process every time the request comes in from a client, various alternatives were developed.
([Wikipedia](https://en.wikipedia.org/wiki/Common_Gateway_Interface))

Examples: FastCGI that enables to use PHP with a lighttpd server.