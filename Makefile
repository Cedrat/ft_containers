NAME = test
VPATH =objs:./srcs:

SRCS = test.cpp 

PATH_OBJS = ./.objs/
OBJS = $(addprefix ${PATH_OBJS},${SRCS:.cpp=.o})

CXX= clang++

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(PATH_OBJS)%.o : %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

all : 		${PATH_OBJS} ${NAME} 

${NAME}:	${OBJS} 
			$(CXX)  -o ${NAME} ${CFLAGS} ${OBJS} 

clean :		
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

${PATH_OBJS}:
	mkdir -p $@

.PHONY : all clean fclean re