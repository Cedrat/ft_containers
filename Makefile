LIB = ft_containers.a

VPATH =objs:./srcs:

SRCS = 
HEADER = is_integral.hpp enable_if.hpp iterator_traits.hpp lexicographical_compare.hpp \
 		test_function.hpp equal.hpp pair.hpp reverse_iterator.hpp

PATH_OBJS = ./.objs/
PATH_GCH = ./.gch/

OBJS = $(addprefix ${PATH_OBJS},${SRCS:.cpp=.o})
GCH = $(addprefix ${PATH_GCH},${HEADER:.hpp=.hpp.gch})
CXX= clang++
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

$(PATH_GCH)%.hpp.gch : %.hpp
	$(CXX) -c $(CFLAGS) $< -o $@

$(PATH_OBJS)%.o : %.cpp $(GCH)
	$(CXX) -I.gch -c $(CFLAGS) $< -o $@



all : 		${PATH_GCH} ${PATH_OBJS}  ${LIB}

${LIB}:	${GCH} ${OBJS}
			ar rcs ${LIB} ${OBJS} ${GCH} 


clean :		
			${RM} ${OBJS} ${GCH} 

fclean :	clean
			${RM} ${NAME_FT} ${LIB}

re :		fclean all

${PATH_OBJS}:
	mkdir -p $@

${PATH_GCH}:
	mkdir -p $@


.PHONY : all clean fclean re