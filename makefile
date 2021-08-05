hellomake: examples/serial_read_write.cpp libserilalptz.h
	g++ -I. -o hellomake examples/serial_read_write.cpp libserilalptz.h -lserial