# Usage:
# make init                         | Add testlib.h to GNU compiler include path
# make new p=problem_name d=level  | Create a new problem with difficulty (e, em, m, mh, h)
# make test p=problem_name ARGS=a  | Run test for the problem, passing ARGS to the generator

ifeq ($(OS),Windows_NT)
    SUFFIX = bat
    RUN_SCRIPT = call new.$(SUFFIX) $(p)
else
    SUFFIX = sh
    RUN_SCRIPT = ./new.$(SUFFIX) $(p) $(d) $(ignore)
endif

.PHONY: init new test

init:
ifeq ($(OS),Windows_NT)
	cp testlib.h "C:\MinGW\include\"
else
	sudo cp testlib.h /usr/local/include/
endif

new:
	@$(RUN_SCRIPT)

test:
	@./build.sh $(p)
	@echo "🔧 Running generator with ARGS=$(ARGS)..."
	@$(p)/bin/gen $(ARGS) > $(p)/bin/input.txt
	@echo "✅ Input:" && ./print.$(SUFFIX) $(p)/bin/input.txt
	@echo "🔍 Running validator..." && $(p)/bin/validator < $(p)/bin/input.txt
	@echo "🚀 Running solution..." && $(p)/bin/sol < $(p)/bin/input.txt > $(p)/bin/output.txt
	@echo "✅ Output:" && ./print.$(SUFFIX) $(p)/bin/output.txt
