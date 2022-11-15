G++					=	g++

CORE_DOCTOR_PATH	=	./core_doctor

SRC_DOCTOR_PATH		=	./sources
TST_DOCTOR_PATH		=	./tests
INC_DOCTOR_PATH 		= 	./includes

SRC_PATIENT_PATH 	= 	../part1_patient/sources
INC_PATIENT_PATH 	= 	../part1_patient/includes

SRC_NURSE_PATH 		= 	../part2_nurse/sources
INC_NURSE_PATH 		= 	../part2_nurse/includes

INC_PATH			= 	$(INC_DOCTOR_PATH)

NAME_DOCTOR			=	my_doctor_hospital

TEST_NAME_DOCTOR 	= 	test_$(NAME_DOCTOR)

INCFLAGS			+=	-I $(INC_PATH)
CPPFLAGS			+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS				=	$(SRC_DOCTOR_PATH)/my_doctor_hospital.cpp \
						$(SRC_PATIENT_PATH)/my_patient_hospital.cpp \
						$(SRC_NURSE_PATH)/my_nurse_hospital.cpp \
						$(CORE_DOCTOR_PATH)/main_doctor.cpp

SRC_TEST			=	$(TST_DOCTOR_PATH)/$(NAME_DOCTOR)_test.cpp

OBJS				=	$(SRCS:.cpp=.o)

CLEAN				=	clean
FCLEAN				=	fclean

all					:	$(NAME_DOCTOR)

$(NAME_DOCTOR)		:	$(OBJS)
						$(G++) $(OBJS) -o $(NAME_DOCTOR) $(CPPFLAGS)

RM					=	rm -rf

clean				:
						$(RM) $(OBJS)
						@$(MAKE) $(CLEAN) -C $(TST_DOCTOR_PATH)

fclean				:	clean
						$(RM) $(NAME_DOCTOR) $(TEST_NAME_DOCTOR)
						@$(MAKE) $(FCLEAN) -C $(TST_DOCTOR_PATH)

re					: 	fclean all

tests_run			:	fclean
						@$(MAKE) -C $(TST_DOCTOR_PATH)
						$(TST_DOCTOR_PATH)/$(TEST_NAME_DOCTOR)

.PHONY				: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME_DOCTOR) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct