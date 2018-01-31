# Serial Interface Specifications
This doc contains the specifications for the `Serial` interface for the esp

## Layer 0
The ESP receives commands and executes them. The command format is one of the following:
- `[CMD (4 bytes)];` Executes command.
- `[CMD (4 bytes)]:[DATA (may not contain ';')];` Executes command with data.
- `[CMD (4 bytes)]=[DATA (may not contain ';')];` Sets var to data.
- `[CMD (4 bytes)]?;` Gets value or state.

The answer format is one of the following:
- `OK;\n` successful execution
- `OK:[data];` ok with data
- `ER:[error];` error
- `DT:[1 byte data size][data];` used for continuous data

## Layer 1
### Command list
- `PING;` Test ESP  
  Response: `OK;ER:[err];`
- `WIFI:[ssid]+[pw];` Connect to wifi.  
  Response: `OK;|ER:[error];`
- `WIFI?;` Get wifi state. (1: connected; 0: disconnected)  
  Response: `OK:(0|1);`
- `MYIP?;` Get IP  
  Response: `OK:[4 byte IP];|ER:No Connection;`
- `HNDL?;` Are there any events to handle  
  Response: `OK;|OK:[4 byte event CODE][2 byte data size][data];`
- `CNTI:[COMMAND];` initialize continuous data delivery  
  Response: `OK;|ER:[error];` over time: `DT:[1 byte data size][data];`

*Maybe later support for file system.*
## Layer 2
TODO: `HNDL` and `CNTI` protocol