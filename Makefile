


all:
	mkdir -p bin
	cc src/verify-remote_serv.c -o bin/verify-remote_serv `pkg-config --cflags --libs libcurl`

install:
	mkdir -p /usr/local/sbin
	cp bin/verify-remote_serv /usr/local/sbin
	cp systemd/verify-remote.service /etc/systemd/system/
	chown 740 /usr/local/sbin/verify-remote_serv
	@printf "Done.\n"
	@printf "You may want to enable and start the service: \"systemctl enable verify-remote ; systemctl start verify-remote\"\n"  
	@printf "The file will be called /r_verified\n"

uninstall:
	rm /usr/local/sbin/verify-remote_serv
	rm /etc/systemd/system/verify-remote.service
	@printf "Done.\n"

clean:
	rm bin/verify-remote_serv
	rmdir bin
