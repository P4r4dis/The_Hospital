G++					=	g++

CORE_LIST_PATH	=	./core_list

SRC_LIST_PATH		=	./sources
TST_LIST_PATH		=	./tests
INC_LIST_PATH 		= 	./includes

SRC_PATIENT_PATH 	= 	../part1_patient/sources
INC_PATIENT_PATH 	= 	../part1_patient/includes

SRC_NURSE_PATH 		= 	../part2_nurse/sources
INC_NURSE_PATH 		= 	../part2_nurse/includes

SRC_DOCTOR_PATH 		= 	../part3_doctor/sources
INC_DOCTOR_PATH 		= 	../part3_doctor/includes

INC_PATH			= 	$(INC_LIST_PATH)

NAME_LIST			=	my_list_hospital

TEST_NAME_LIST 		= 	test_$(NAME_LIST)

INCFLAGS			+=	-I $(INC_PATH)
CPPFLAGS			+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS				=	$(SRC_LIST_PATH)/my_list_hospital.cpp \
						$(SRC_PATIENT_PATH)/my_patient_hospital.cpp \
						$(SRC_NURSE_PATH)/my_nurse_hospital.cpp \
						$(SRC_DOCTOR_PATH)/my_doctor_hospital.cpp \
						$(CORE_LIST_PATH)/main_list.cpp

SRC_TEST			=	$(TST_LIST_PATH)/$(NAME_LIST)_test.cpp

OBJS				=	$(SRCS:.cpp=.o)

CLEAN				=	clean
FCLEAN				=	fclean

all					:	$(NAME_LIST)

$(NAME_LIST)		:	$(OBJS)
						$(G++) $(OBJS) -o $(NAME_LIST) $(CPPFLAGS)

RM					=	rm -rf

clean				:
						$(RM) $(OBJS)
						@$(MAKE) $(CLEAN) -C $(TST_LIST_PATH)

fclean				:	clean
						$(RM) $(NAME_LIST) $(TEST_NAME_LIST)
						@$(MAKE) $(FCLEAN) -C $(TST_LIST_PATH)

re					: 	fclean all

tests_run			:	fclean
						@$(MAKE) -C $(TST_LIST_PATH)
						$(TST_LIST_PATH)/$(TEST_NAME_LIST)

.PHONY				: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME_DOCTOR) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct