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
	@echo "✅ Input (generated):" && ./print.$(SUFFIX) $(p)/bin/input.txt
	
	@echo "🔍 Running validator (generated)..."
	@$(p)/bin/validator < $(p)/bin/input.txt

	@echo "🚀 Running solution (generated)..."
	@$(p)/bin/sol < $(p)/bin/input.txt > $(p)/bin/output.txt
	@echo "✅ Output (generated):" && ./print.$(SUFFIX) $(p)/bin/output.txt

	@echo "🔧 Running all manual testcases (*.in)..."
	@sh -c 'if ls $(p)/tc/*.in 1> /dev/null 2>&1; then \
		for testcase in $(p)/tc/*.in; do \
			echo "=== Running testcase $$testcase ==="; \
			$(p)/bin/validator < $$testcase || echo "Validator failed on $$testcase"; \
			$(p)/bin/sol < $$testcase > $(p)/bin/output.txt; \
			echo "Output:"; \
			./print.$(SUFFIX) $(p)/bin/output.txt; \
			echo; \
		done; \
	else \
		echo "No manual testcases (*.in) found in $(p)/tc/"; \
	fi'
