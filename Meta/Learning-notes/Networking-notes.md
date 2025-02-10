### [Localhost](https://phoenixnap.com/kb/127-0-0-1-localhost)
A pseudo name for the 127.0.0.1, the IP address of the local computer, allowing the machine to connect to and communicate with itself. IPv4 reserves the whole range 127.0.0.1 – 127.255.255.255 for localhost, also known as the **loopback address**. The IPv6 standard assigns one address to loopback - `:: 1`

## Socket
A network socket is an endpoint for sending or receiving data across a computer network. In web server configurations, including Lighttpd, sockets are crucial for defining how the server listens for and handles incoming network connections. Let's break down the concept:

- **Network Communication Endpoint:** A socket in networking is an endpoint of a bidirectional communication flow across a network. In simpler terms, it's like a virtual "port" through which data enters and exits a computer or server.
    
- **IP Address and Port Number:** A socket is defined by an IP address and a port number. The IP address identifies the host (like a server), and the port number identifies a specific application or service on this host (like a web server).
([ChatGPT](https://chat.openai.com/c/fc2493ce-5f71-4439-a5a2-b1ad411ee945#:~:text=the%20term%20%22socket%22%20refers%20to%20a%20network%20socket))
## Servers
### [Virtual Private Servers](https://webhostinggeeks.com/howto/how-to-display-the-number-of-processors-vcpu-on-linux-vps/)
Virtualized environments running multiple instances of an OS on a single physical server. In a VPS environment, the number of virtual CPUs (vCPUs) allocated to a VM determines its computing power.
[General article](https://webhostinggeeks.com/blog/what-is-vps-hosting/)
A pseudo name for the 127.0.0.1, the IP address of the local computer, allowing the machine to connect to and communicate with itself. IPv4 reserves the whole range 127.0.0.1 – 127.255.255.255 for localhost, also known as the **loopback address**. The IPv6 standard assigns one address to loopback - `:: 1`

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