hellomake: examples/serial_read_write.cpp examples/httplib.h libserilalptz.h
	g++ -I. -o hellomake examples/serial_read_write.cpp examples/httplib.h libserilalptz.h -lserial -lpthread -ljsoncpp