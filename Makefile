CD = client
SD = server
all: install
install: 
	@make copy -C $(CD)
	@make copy -C $(SD)
clean:
	@make clean -C $(CD)
	@make clean -C $(SD)
uninstall: clean
	@make uninstall -C $(CD)
	@rm -f uchat
	@make uninstall -C $(SD)
	@rm -f uchat_server
reinstall: uninstall all
