###############################
### DO NOT MODIFY THIS FILE ###
###############################

HASTE = /labcommon/comp2129/assignment1/bin/haste

.PHONY: all build clean update submission

all: build
	@$(HASTE) update

build: build.sh
	@./build.sh

clean:
	-rm -f *.o

update:
	@$(HASTE) update

submission:
	@$(HASTE) submit
