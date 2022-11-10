G++				=	g++

SRC_PATH		=	../sources/
INC_PATH		=	../includes/

TESTS_SRC_PATH	=	./tests_sources/
TESTS_INC_PATH	=	./tests_includes/

NAME			=	test_my_nurse_hospital

INCFLAGS		+=	-I$(INC_PATH) -I$(INC_TEST_PATH)
CRITFLAGS		+=	--coverage -lcriterion --verbose
CPPFLAGS		+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS)


SRCS			=	test_my_nurse_hospital.cpp \
					$(SRC_PATH)/my_nurse_hospital.cpp \
					$(TESTS_SRC_PATH)/test_sources.cpp


OBJS			=	$(SRCS:.cpp=.o)
OBJS_GCDA		=	$(SRCS:.cpp=.gcda)
OBJS_GCNO		=	$(SRCS:.cpp=.gcno)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
					$(RM) $(TESTS_SRC_PATH)$(OBJS) $(TESTS_SRC_PATH)$(OBJS_GCDA) $(TESTS_SRC_PATH)$(OBJS_GCNO)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re