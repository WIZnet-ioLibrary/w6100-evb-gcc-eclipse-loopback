# Index
- [Loopback Example for W6100-EVB](#Loopback-Example-for-W6100-EVB)
- [Hardware Environment](#Hardware-Environment)
- [Software Environments](#Software-Environment)
- [Run](#Run)
- [Code review](#Code-review)
  - [Test packet capture file](#Test-packet-capture-file)


------
# Loopback Example for W6100-EVB
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
* Compile Program : TrueStudio Ver 9.2.0
* Flash Program : FLASHER-STM32 Ver2.8.0
* Compile method <br>
  - Git-Hub source file download <br>
  - TrueStudio -> W6100EVB-HTTP_Server in folder, run TrueStudio Project file <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55785003-a47dcb80-5aec-11e9-8955-a4c1ebf95918.png" />
  </p>

  - WorkSpace path select<br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55773235-9f0f8980-5aca-11e9-825c-7f362cbfc7fd.png" />
  </p>

  - ① open main.c file and build ② build icon or Key CTRL + B  <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55773236-9f0f8980-5aca-11e9-95f4-5e68b0045935.png" />
  </p>

  - If you have ST-LINK, Run Debug - Click debug button or Key F8<br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55773705-c404fc00-5acc-11e9-84dd-d0774a1d17db.png" />
  </p>

  - Serial Flash Download<br>
    - Check Serial Port<br>
    <p align="center">
      <img width="60%" src="https://user-images.githubusercontent.com/48539052/55779775-544d3c00-5ae1-11e9-8a5c-625062b4a40d.png" />
    </p>

    - Check Hex file <br>
    <p align="center">
      <img width="60%" src="https://user-images.githubusercontent.com/48539052/55779776-544d3c00-5ae1-11e9-91a3-024eca4ad7d2.png" />
    </p>

    - Device Program upload, See site below.
      - [How to uploading to firmware ](https://wizwiki.net/wiki/doku.php?id=products:w6100:w6100_evb:getting_started#how_to_uploading_to_firmware)



## Run
* Demo Environment & Program <br>

  - Windows 10 <br>
  - [Hercules](https://www.hw-group.com/software/hercules-setup-utility) <br>
  - [ScriptCommunicator](https://sourceforge.net/projects/scriptcommunicator/) <br>

* Demo Result <br>
  - Power On and push Reset button to start Program<br>
  - Program Run Serial display <br>

  <p align="center">
    <img width="60%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/UART-Hercules.jpg" />
  </p>

  - There are 4 sockets available for connection.

    * UDP IPv4 / Port 50000
    * TCP IPv4 / Port 50003
    * TCP IPv6 / Port 50004
    * TCP Dual / Port 50005

  - Run ScriptCommunicator and set sockets for IPv4 connection. and connect.

  <p align="center">
    <img width="60%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/TCPclient-IPv4-Settings.jpg" />
  </p>

  - After connected, send a message to the W6100EVB. Then the W6100EVB reply with message you've sent.

  <p align="center">
    <img width="60%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/TCPclient-IPv4-Send.jpg" />
  </p>

  - Run ScriptCommunicator and set sockets for IPv6 connection. and connect.

  <p align="center">
    <img width="60%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/TCPclient-IPv6-Settings.jpg" />
  </p>

  - After connected, send a message to the W6100EVB. Then the W6100EVB reply with message you've sent.

  <p align="center">
    <img width="60%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/TCPclient-IPv6-Send.jpg" />
  </p>

  ## Code review
  * main.c code flow <br>
  <p align="center">
    <img width="35%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Dia/W6100EVB-Loopback.png" />
  </p>

   ## Test packet capture file
   <p align="center">
   <img width="100%" src="https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Jpg/W6100EVB-Loopback-DualIP.jpg" />
    </p>

    
    -Test packet capture file : [W6100EVB-Loopback-DualIP.zip](https://github.com/WIZnet-ioLibrary/W6100EVB-Loopback/wiki/Packet/W6100EVB-Loopback-DualIP.zip)
    
    
