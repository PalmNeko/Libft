
.PHONY: help
help: ## Show options
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
    awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'

.PHONY: test
test: ## Run tests
	make --directory test test

.PHONY: clean
clean: ## Run clean
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	find . -name "*.d" -delete
	find . -name "*.exe" -delete
	find . -name "*.gcov" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
