NAME = test
VPATH =objs:./srcs:

SRCS = test.cpp 
HEADER = is_integral.hpp enable_if.hpp iterator_traits.hpp lexicographical_compare.hpp test_function.hpp equal.hpp pair.hpp

PATH_OBJS = ./.objs/
PATH_GCH = ./.gch/

OBJS = $(addprefix ${PATH_OBJS},${SRCS:.cpp=.o})
GCH = $(addprefix ${PATH_GCH},${HEADER:.hpp=.hpp.gch})
CXX= clang++
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(PATH_GCH)%.hpp.gch : %.hpp
	$(CXX) -c $(CFLAGS) $< -o $@

$(PATH_OBJS)%.o : %.cpp $(GCH)
	$(CXX) -I.gch -c $(CFLAGS) $< -o $@



all : 		${PATH_GCH} ${PATH_OBJS}  ${NAME} 

${NAME}:	${GCH} ${OBJS} 
			$(CXX) -o ${NAME} ${CFLAGS} ${OBJS} 

clean :		
			${RM} ${OBJS} ${GCH}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

${PATH_OBJS}:
	mkdir -p $@

${PATH_GCH}:
	mkdir -p $@


.PHONY : all clean fclean re