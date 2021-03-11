ifconfig -a | grep -w ether | cut -c8- | tr -d ' '
