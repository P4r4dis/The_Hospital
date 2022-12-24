G++						=	g++

CORE_HOSPITAL_PATH		=	./core_hospital

SRC_HOSPITAL_PATH		=	./sources
TST_HOSPITAL_PATH		=	./tests
INC_HOSPITAL_PATH 		= 	./includes

SRC_PATIENT_PATH 		= 	../part1_patient/sources
INC_PATIENT_PATH 		= 	../part1_patient/includes

SRC_NURSE_PATH 			= 	../part2_nurse/sources
INC_NURSE_PATH 			= 	../part2_nurse/includes

SRC_DOCTOR_PATH 		= 	../part3_doctor/sources
INC_DOCTOR_PATH 		= 	../part3_doctor/includes

SRC_LIST_PATH 			= 	../part4_list/sources
INC_LIST_PATH 			= 	../part4_list/includes

INC_PATH				= 	$(INC_HOSPITAL_PATH)

NAME_HOSPITAL			=	my_hospital

TEST_NAME_HOSPITAL 		= 	test_$(NAME_HOSPITAL)

INCFLAGS				+=	-I $(INC_PATH)
CPPFLAGS				+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS					=	$(SRC_PATIENT_PATH)/my_patient_hospital.cpp \
							$(SRC_NURSE_PATH)/my_nurse_hospital.cpp \
							$(SRC_DOCTOR_PATH)/my_doctor_hospital.cpp \
							$(SRC_LIST_PATH)/my_list_hospital.cpp \
							$(SRC_HOSPITAL_PATH)/my_hospital.cpp \
							$(CORE_HOSPITAL_PATH)/main_hospital.cpp

SRC_TEST				=	$(TST_HOSPITAL_PATH)/$(NAME_HOSPITAL)_test.cpp

OBJS					=	$(SRCS:.cpp=.o)

CLEAN					=	clean
FCLEAN					=	fclean

all						:	$(NAME_HOSPITAL)

$(NAME_HOSPITAL)		:	$(OBJS)
							$(G++) $(OBJS) -o $(NAME_HOSPITAL) $(CPPFLAGS)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(TST_HOSPITAL_PATH)

fclean					:	clean
							$(RM) $(NAME_HOSPITAL) $(TEST_NAME_HOSPITAL)
							@$(MAKE) $(FCLEAN) -C $(TST_HOSPITAL_PATH)

re						: 	fclean all

tests_run				:	fclean
							@$(MAKE) -C $(TST_HOSPITAL_PATH)
							$(TST_HOSPITAL_PATH)/$(TEST_NAME_HOSPITAL)

.PHONY					: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME_DOCTOR) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct