from bluetooth import *
print ("performing inquiry...")

nearby_devices = discover_devices(lookup_names = True)

print ("found %d devices") % len(nearby_devices)
for addr,name in nearby_devices:
     print ("%20s - %s") % (name,addr)
