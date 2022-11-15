G++					=	g++
###############################################
###############################################
PART1_PATH 			= 	./part1_patient
PART1_SRC_PATH		=	./part1_patient/sources
PART1_TST_PATH		=	./part1_patient/tests
PART1_INC_PATH		=	./part1_patient/includes
NAME_PATIENT		=	my_patient_hospital

PART1_SRC			=	$(PART1_SRC_PATH)/my_patient_hospital.cpp
PART1_SRC_TEST		=	$(PART1_TST_PATH)/$(NAME_PATIENT)_test.cpp
TEST_NAME_PATIENT 	= 	test_$(NAME_PATIENT)

###############################################
PART2_PATH 			= 	./part2_nurse
PART2_SRC_PATH		=	./part2_nurse/sources
PART2_TST_PATH		=	./part2_nurse/tests
PART2_INC_PATH		=	./part2_nurse/includes

PART2_SRC			=	$(PART2_SRC_PATH)/my_nurse_hospital.cpp
PART2_SRC_TEST		=	$(PART2_TST_PATH)/$(NAME)_test.cpp
NAME_NURSE			=	my_nurse_hospital
TEST_NAME_NURSE 	= 	test_$(NAME_NURSE)

###############################################
PART3_PATH 			= 	./part3_doctor
PART3_SRC_PATH		=	./part3_doctor/sources
PART3_TST_PATH		=	./part3_doctor/tests
PART3_INC_PATH		=	./part3_doctor/includes

PART3_SRC			=	$(PART3_SRC_PATH)/my_doctor_hospital.cpp
PART3_SRC_TEST		=	$(PART3_TST_PATH)/$(NAME)_test.cpp
NAME_DOCTOR			=	my_doctor_hospital
TEST_NAME_DOCTOR 	= 	test_$(NAME_DOCTOR)

###############################################
CORE_PATH			=	./core
SRCS_PATH			=	$(PART1_SRC_PATH) \
						$(PART2_SRC_PATH) \
						$(PART3_SRC_PATH) 


TST_PATH			=	$(PART1_TST_PATH) \
						$(PART2_TST_PATH) \
						$(PART3_TST_PATH)

NAME				=	my_hospital
TEST_NAME 			= 	test_$(NAME)

#INC_PATH 			= 	$(PART1_INC_PATH)
#$(PART2_INC_PATH)
INCFLAGS			+=	-I $(PART1_INC_PATH) -I $(PART2_INC_PATH) -I $(PART3_INC_PATH)
#$(INC_PATH)

CPPFLAGS			+= 	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS 				= 	$(PART1_SRC) \
						$(PART2_SRC) \
						$(PART3_SRC) \
						$(CORE_PATH)/main.cpp
#$(PART2_SRC)

SRC_TEST 			= 	$(PART1_SRC_TEST) \
						$(PART2_SRC_TEST) \
						$(PART3_SRC_TEST) 

OBJS				=	$(SRCS:.cpp=.o)
CLEAN				=	clean
FCLEAN				=	fclean

all					:	$(NAME)

$(NAME)				:	$(OBJS)
						$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM					=	rm -rf

clean				:
						$(RM) $(OBJS)
						@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
						@$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)
						@$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)

fclean				:	clean
						$(RM) $(NAME) $(TEST_NAME)
						@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
						@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
						@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
						@$(MAKE) $(FCLEAN) -C $(PART2_PATH)
						@$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
						@$(MAKE) $(FCLEAN) -C $(PART3_PATH)

re					: 	fclean all

part1 				: 	fclean
						@$(MAKE) -C $(PART1_PATH)
						$(PART1_PATH)/$(NAME_PATIENT)

part2 				: 	fclean
						@$(MAKE) -C $(PART2_PATH)
						$(PART2_PATH)/$(NAME_NURSE)

part3 				: 	fclean
						@$(MAKE) -C $(PART3_PATH)
						$(PART3_PATH)/$(NAME_DOCTOR)

tests_run_part1		:	fclean
						@$(MAKE) -C $(PART1_TST_PATH)
						$(PART1_TST_PATH)/$(TEST_NAME_PATIENT)

tests_run_part2		:	fclean
						@$(MAKE) -C $(PART2_TST_PATH)
						$(PART2_TST_PATH)/$(TEST_NAME_NURSE)

tests_run_part3		:	fclean
						@$(MAKE) -C $(PART3_TST_PATH)
						$(PART3_TST_PATH)/$(TEST_NAME_DOCTOR)

tests_run			:	fclean
						@$(MAKE) tests_run_part1
						@$(MAKE) tests_run_part2
						@$(MAKE) tests_run_part3	


#						@$(MAKE) -C $(PART1_TST_PATH)
#						$(PART1_TST_PATH)/$(TEST_NAME_PATIENT)
#						@$(MAKE) -C $(PART2_TST_PATH)
#						$(PART2_TST_PATH)/$(TEST_NAME_NURSE)

.PHONY				: 	all clean fclean re part1 tests_run_part1 part2 tests_run_part2 part3 tests_run_part3 tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct