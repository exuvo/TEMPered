
all: ./build/Makefile
	@ $(MAKE) -C build
	@ cp build/utils/tempered .
	@echo
	@echo "tempered built and copied to current directory"
	@echo

./build/Makefile:
	mkdir -p build
	cd build && cmake .. || true

clean: distclean

distclean:
	@- rm -rf ./build
	@- rm -rf ./tempered

.PHONY: help cmake distclean
