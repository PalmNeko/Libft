
PRODUCTS = libft.h libft.a get_next_line.h ft_printf.h

all: build $(PRODUCTS)

%.h: submit/%.h
	cp $< .
%.a: submit/%.a
	cp $< .

submit/%.a: build

.PHONY: build
build:
	make -C submit

.PHONY: help
help: ## Show options
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
    awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'

.PHONY: test
test: ## Run tests
	make --directory tests test

.PHONY: check-tests
check-tests: ## Check have testfiles
	@bash scripts/check-have-testfiles.sh

.PHONY: clean
clean: ## Run clean
	find . -name "*.o" -delete
	find . -name "*.d" -delete
	find . -name "*.exe" -delete
	find . -name "*.gcov" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete

fclean: clean
	rm -rf $(PRODUCTS)
