G++				=	g++
###############################################
###############################################
PART1_PATH 		= 	./part1_patients/
PART1_SRC_PATH	=	./part1_patients/sources
PART1_TST_PATH	=	./part1_patients/tests
PART1_INC_PATH	=	./part1_patients/includes

PART1_SRC		=	$(PART1_SRC_PATH)/my_hospital.cpp
PART1_SRC_TEST	=	$(PART1_TST_PATH)/$(NAME)_test.cpp
###############################################
CORE_PATH		=	./core
SRCS_PATH		=	$(PART1_SRC_PATH)
TST_PATH		=	$(PART1_TST_PATH)

NAME			=	my_hospital
TEST_NAME 		= 	test_$(NAME)

INCS_PATH 		= 	$(PART1_INC_PATH)
INCFLAGS		+=	-I $(INCS_PATH)

CPPFLAGS		+= 	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS 			= 	$(PART1_SRC) \
					$(CORE_PATH)/main.cpp

SRC_TEST 		= 	$(PART1_SRC_TEST)

OBJS			=	$(SRCS:.cpp=.o)
CLEAN			=	clean
FCLEAN			=	fclean

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS)
					@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)

fclean			:	clean
					$(RM) $(NAME) $(TEST_NAME)
					@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
					@$(MAKE) $(FCLEAN) -C $(PART1_PATH) 

re				: 	fclean all

part1 			: 	fclean
					@$(MAKE) -C $(PART1_PATH)
					$(PART1_PATH)/$(NAME)

tests_run_part1	:	fclean
					@$(MAKE) -C $(PART1_TST_PATH)
					$(PART1_TST_PATH)/$(TEST_NAME)

tests_run		:	fclean
					@$(MAKE) -C $(PART1_TST_PATH)
					$(PART1_TST_PATH)/$(TEST_NAME)

.PHONY			: 	all clean fclean re part1 tests_run_part1 tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct