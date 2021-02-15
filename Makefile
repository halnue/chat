CD = uclient
SD = userver
all: install
install: 
	@make copy -C $(CD)
	@make copy -C $(SD)
clean:
	@make clean -C $(CD)
	@make clean -C $(SD)
uninstall: clean
	@make uninstall -C $(CD)
	@rm -f client
	@make uninstall -C $(SD)
	@rm -f server
reinstall: uninstall all
