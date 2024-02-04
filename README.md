# Minitalk
<img alt="Minitalk" src="https://img.shields.io/static/v1?label=Minitalk&message=110+/+125&color=gree&style=plastic"/>

# Project
Push Swap is one of the three projects in the 42 program third circle. The purpose of this project is to code a small data exchange program using UNIX signals.

# Constraints
According to the subject there is 3 contraints for this project:
*  Only one global variable allower per program.
*  Only use two signals: SIGUSR1 and SIGUSR2
*  The whole files of the projects need to follow 42 norm ([Link](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf))

# External function(s) allowed
* write
* signal
* sigemptyset
* sigaddset
* sigaddset
* kill
* getpid
* malloc
* free
* pause
* sleep
* usleep
* exit

# Behavior
For this project, a server program needs to be able to receive multiple client program message.

## Argument(s)

 ### Server
*  Nothing

 ### Client
*  The server PID.
*  The string to send.

## Output
The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.

# Bonus part
| Description | Mark |
|      --     |:----:|
| The server acknowledges every message received by sending back a signal to the client. | :x: |
| Unicode characters support! | :white_check_mark: |


# Usage

``make`` to compile both client and server.

``make server`` to compile the server.

``make client`` to compile the client.

``make clean`` to clean all compiled files without the programs.

``make fclean`` to clean all compiled files with the program.

``make re`` to fclean then make.

```
1. ./server 
2. Copy the server printed PID
3. ./client <PID> <message>
