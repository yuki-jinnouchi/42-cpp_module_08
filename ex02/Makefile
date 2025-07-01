# Output File
OUTPUT_DIR =	.
NAME = 				$(OUTPUT_DIR)/ex02

# Directories
INCLUDES_DIR =	.
SOURCES_DIR =		.
OBJECTS_DIR =		objs

# Files
SOURCES =		main.cpp
INCLUDES =	MutantStack.hpp MutantStack.tpp
OBJECTS =		$(SOURCES:%.cpp=$(OBJECTS_DIR)/%.o)

# Compiler & Flags
CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98
CPPFLAGS =		-I $(INCLUDES_DIR)

#-----------------------------------------------
# Colors
RESET = \033[0m
BOLD = \033[1m
# Regular Colors
GREEN = \033[32m
CYAN = \033[36m
GRAY = \033[90m
BLUE = \033[34m
# Bold Colors
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
B_CYAN = \033[1;36m

#-----------------------------------------------
# Rules
all:	$(NAME)

# Link Targets
$(NAME): $(OBJECTS)
	@printf "\r$(GREEN)[%2d/%2d]$(RESET) All files compiled! Linking $(CYAN)$(NAME)$(RESET)\033[K\n" \
		"$$(find $(OBJECTS_DIR) -name '*.o' | wc -l)" "$$(echo $(SOURCES) | wc -w)"
	@$(CXX) $(CPPFLAGS) $^ -o $@
	@echo "$(B_GREEN)SUCCESS:$(RESET) $(NAME) linked successfully"
	@chmod 755 $(NAME)
	@echo "$(B_CYAN)READY:$(RESET) $(NAME) is ready to run"

# Compile Targets
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp | $(OBJECTS_DIR)
	@printf "\r$(GREEN)[%2d/%2d]$(RESET) Compiling $(CYAN)%s$(RESET)\033[K" \
		"$$(find $(OBJECTS_DIR) -type f | wc -l)" "$$(echo $(SOURCES) | wc -w)" "$<"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

# Clean Targets
clean:
	@rm -rf $(OBJECTS)
	@rm -rfd $(OBJECTS_DIR)
	@echo "$(GRAY)CLEAN: $(NAME) object files cleaned$(RESET)"

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(GRAY)FCLEAN: $(NAME) executable files cleaned$(RESET)"

re:		fclean all

# Phony
.PHONY = all clean fclean re

#-----------------------------------------------
# Test Targets
test: $(NAME)
	@echo "$(BLUE)Running Exercise 00 tests...$(RESET)"
	@./$(NAME)

# Test Targets
test: $(NAME)
	@echo "$(BLUE)Running Exercise 02 tests...$(RESET)"
	@./$(NAME)

test_comparison: $(NAME) $(NAME_LIST)
	@echo "$(B_YELLOW)Testing MutantStack vs std::list comparison...$(RESET)"
	@echo "$(CYAN)Running MutantStack...$(RESET)"
	@./$(NAME) > mutant_output.txt
	@echo "$(CYAN)Running std::list equivalent...$(RESET)"
	@./$(NAME_LIST) > list_output.txt
	@echo "$(CYAN)Comparing outputs...$(RESET)"
	@if diff mutant_output.txt list_output.txt > /dev/null; then \
		echo "$(B_GREEN)✅ Outputs match! MutantStack behaves like std::list$(RESET)"; \
	else \
		echo "$(B_RED)❌ Outputs differ! Check implementation$(RESET)"; \
		diff mutant_output.txt list_output.txt; \
	fi
	@rm -f mutant_output.txt list_output.txt

.PHONY = test test_comparison

#-----------------------------------------------
# Debug Information
debug:
	@echo "$(B_BLUE)Debug Information:$(RESET)"
	@echo "$(CYAN)SOURCES:$(RESET) $(SOURCES)"
	@echo "$(CYAN)INCLUDES:$(RESET) $(INCLUDES)"
	@echo "$(CYAN)OBJECTS:$(RESET) $(OBJECTS)"
	@echo "$(CYAN)OBJECTS_DIR:$(RESET) $(OBJECTS_DIR)"
	@echo "$(CYAN)CXX:$(RESET) $(CXX)"
	@echo "$(CYAN)CXXFLAGS:$(RESET) $(CXXFLAGS)"
	@echo "$(CYAN)CPPFLAGS:$(RESET) $(CPPFLAGS)"
	@echo "$(CYAN)NAME:$(RESET) $(NAME)"

.PHONY = debug
