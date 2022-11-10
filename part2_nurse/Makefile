G++					=	g++
#CORE_PATH	=	./core

CORE_NURSE_PATH		=	./core_nurse

SRC_NURSE_PATH		=	./sources
TST_NURSE_PATH		=	./tests
INC_NURSE_PATH 		= 	./includes

SRC_PATIENT_PATH 	= 	../part1_patient/sources
INC_PATIENT_PATH 	= 	../part1_patient/includes

INC_PATH			= 	$(INC_NURSE_PATH)

NAME_NURSE			=	my_nurse_hospital
TEST_NAME_NURSE 	= 	test_$(NAME_NURSE)

INCFLAGS			+=	-I $(INC_PATH)
CPPFLAGS			+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS		=	$(SRC_NURSE_PATH)/my_nurse_hospital.cpp \
				$(SRC_PATIENT_PATH)/my_patient_hospital.cpp \
				$(CORE_NURSE_PATH)/main_nurse.cpp

SRC_TEST	=	$(TST_NURSE_PATH)/$(NAME_NURSE)_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean

all			:	$(NAME_NURSE)

$(NAME_NURSE)		:	$(OBJS)
						$(G++) $(OBJS) -o $(NAME_NURSE) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_NURSE_PATH)

fclean		:	clean
				$(RM) $(NAME_NURSE) $(TEST_NAME_NURSE)
				@$(MAKE) $(FCLEAN) -C $(TST_NURSE_PATH)

re			: 	fclean all

tests_run	:	fclean
				@$(MAKE) -C $(TST_NURSE_PATH)
				$(TST_NURSE_PATH)/$(TEST_NAME_NURSE)

.PHONY		: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME_NURSE) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct