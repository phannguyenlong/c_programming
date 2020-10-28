import pyfiglet;
import sys;
import socket;
from datetime import datetime;

def scan_target(target):
    # Display target
    print(20 * "-")
    print("Scanning: " + target)
    print("Scanning at time: " + str(datetime.now()))
    print(20 * "-")

    # scan port
    try:
        for port in range(1, 1000):
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            socket.setdefaulttimeout(1)

            # return result
            res = s.connect_ex((target, port))
            if (res == 0):
                print("Port {} is open".format(port))
            s.close()
    except KeyboardInterrupt:
        print("\nExiting...")
        sys.exit()
    except socket.gaierror: 
        print("\n Hostname Could Not Be Resolved !!!!") 
        sys.exit() 
    except socket.error: 
        print("\ Server not responding !!!!") 
        sys.exit() 

def main():
    # Banner
    ascii_banner = pyfiglet.figlet_format("Port Scanner");
    print(ascii_banner);

    # Define target
    if (len(sys.argv) == 2):
        # conver hostname to IPv4
        target = socket.gethostbyname(sys.argv[1])
        scan_target(target)
    else:
        print("Invalid Argument")
        print("Syntax: port_scanner.py <host_name>")

main()




