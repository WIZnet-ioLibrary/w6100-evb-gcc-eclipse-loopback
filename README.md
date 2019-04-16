# Index
- [Loopback Example for W6100-EVB with GCC and Eclipse IDE](#Loopback-Example-for-W6100-EVB-with-GCC-and-Eclipse-IDE)
- [Hardware Environment](#Hardware-Environment)
- [Software Environments](#Software-Environment)
- [Run](#Run)
- [Code review](#Code-review)
  - [Test packet capture file](#Test-packet-capture-file)


------
# Loopback Example for W6100-EVB with GCC and Eclipse IDE
Common to Any MCU, Easy to Add-on. Internet Offload co-Processor, HW TCP/IP chip,
best fits for low-end Non-OS devices connecting to Ethernet for the Internet of Things. These will be updated continuously.

## Hardware Environment
* W6100EVB
  - connecting Micro usb.
  - connecting Ethernet cable. <br>
<p align="center">
  <img width="60%" src="https://wizwiki.net/wiki/lib/exe/fetch.php?w=600&tok=eabde4&media=products:w6100:w6100_evb:w6100-evb_callout.png" />
</p>

## Software Environment
* Compile Program : ARM GCC Toolchain 2018-q4-major
* Flash Program : FLASHER-STM32 Ver2.8.0 or STM32CubeProgrammer V2.0.0
* Compile method <br>
  - Git-Hub source file download <br>
  - Select File -> Import in Eclipse <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56175872-029e3780-6034-11e9-85ca-1517654225fc.PNG" />
  </p>

  - Select "Existing Projects into Workspace" 
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56175933-409b5b80-6034-11e9-8dfe-73533017bf7b.PNG" />
  </p>
  - Select WorkSpace path. w6100-evb-gcc-eclipse-loopback\gcc-eclipse-projectfolder\w6100-evb-gcc-eclipse-loopback<br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56175946-45600f80-6034-11e9-8bce-9094543fbbbf.PNG" />
  </p>

  - Build the Project  <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176411-f2875780-6035-11e9-892b-43a040f3b17b.png" />
  </p>

  - Serial Flash Download<br>
    - Device Program upload, See site below.
      - [How to uploading to firmware ](https://wizwiki.net/wiki/doku.php?id=products:w6100:w6100_evb:getting_started#how_to_uploading_to_firmware)



## Run
* Demo Environment & Program <br>

  - Windows 10 <br>
  - [Hercules](https://www.hw-group.com/software/hercules-setup-utility) <br>
  - [ScriptCommunicator](https://sourceforge.net/projects/scriptcommunicator/) <br>
* Demo Result <br>
  - Power On and push Reset button to start Program<br>
  - Then, application displays its network information on Serial console<br>

  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176787-3169dd00-6037-11e9-9f7d-92d0884a2827.PNG" />
  </p>

  - There are 8 sockets available for loopback test.

    * UDP IPv4 / Port 50000
    * UDP IPv6 / Port 50001
    * UDP Dual / Port 50002
    * TCP Server IPv4 / Port 50003
    * TCP Server IPv6 / Port 50004
    * TCP Server Dual / Port 50005
    * TCP Client IPv4 / Port 50006
    * TCP Client IPv6 / Port 50007


  - Run ScriptCommunicator and set sockets for IPv4 connection. and connect.

  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176801-39298180-6037-11e9-85d0-5e88b49c9e29.PNG" />
  </p>

  - After connected, send a message to the W6100EVB. Then the W6100EVB reply with message you've sent.

  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176805-3f1f6280-6037-11e9-9807-e1284b79c190.PNG" />
  </p>

  - Run ScriptCommunicator and set sockets for IPv6 connection. and connect.

  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176809-4181bc80-6037-11e9-8f88-c13a336fdfc5.PNG" />
  </p>

  - After connected, send a message to the W6100EVB. Then the W6100EVB reply with message you've sent.

  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/2120691/56176812-434b8000-6037-11e9-821a-bfda620ba840.PNG" />
  </p>

  
    
