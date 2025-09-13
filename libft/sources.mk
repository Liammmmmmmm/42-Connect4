SRC_DIR = src

CONVERTER_DIR = converter
CONVERTER_FILES = $(addprefix $(CONVERTER_DIR)/, \
	ft_atoi.c \
	ft_itoa.c \
)

FREE_DIR = free
FREE_FILES = $(addprefix $(FREE_DIR)/, \
	free_split.c \
	free_n.c \
)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_FILES = $(addprefix $(FT_PRINTF_DIR)/, \
	ft_vfprintf.c \
	ft_printf.c \
	ft_devprintf.c \
	ft_dprintf.c \
	ft_perror.c \
	handle_flag.c \
	ft_vfprintf_utils.c \
	flags/flag_c.c \
	flags/flag_i.c \
	flags/flag_low_x.c \
	flags/flag_p.c \
	flags/flag_s.c \
	flags/flag_u.c \
	flags/flag_up_x.c \
)

GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_FILES = $(addprefix $(GET_NEXT_LINE_DIR)/, \
	get_next_line.c \
	get_next_line_utils.c \
)

IDENTIFER_DIR = identifier
IDENTIFER_FILES = $(addprefix $(IDENTIFER_DIR)/, \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c \
)

MATHS_DIR = maths
MATHS_FILES = $(addprefix $(MATHS_DIR)/, \
	arrmax.c \
	arrmin.c \
	max.c \
	min.c \
	maxs.c \
	mins.c \
)

LIST_DIR = list
LIST_FILES = $(addprefix $(LIST_DIR)/, \
	lstadd_back.c \
	lstadd_front.c \
	lstclear.c \
	lstdelone.c \
	lstiter.c \
	lstlast.c \
	lstmap.c \
	lstnew.c \
	lstpop.c \
	lstsize.c \
)

MEMORY_DIR = memory
MEMORY_FILES = $(addprefix $(MEMORY_DIR)/, \
	ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdup.c \
	ft_memmove.c \
	ft_memset.c \
)

STRING_DIR = string
STRING_FILES = $(addprefix $(STRING_DIR)/, \
	ft_split.c \
	ft_arrlen.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strstr.c \
	ft_strtok.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_toupper.c \
	ft_tolower.c \
	strmerge.c \
	stradd.c \
	starts_by.c \
	ends_by.c \
)

VECTOR_DIR = vector
VECTOR_FILES = $(addprefix $(VECTOR_DIR)/, \
	int/ivec_create.c \
	int/ivec_push.c \
	int/ivec_set.c \
	int/ivec_get.c \
	int/ivec_includes.c \
	int/ivec_index.c \
	int/ivec_pop.c \
	int/ivec_print.c \
	int/ivec_destroy.c\
)
#	char/cvec_create.c \
#	char/cvec_destroy.c \
#	char/cvec_get.c \
#	char/cvec_pop.c \
#	char/cvec_print.c \
#	char/cvec_push.c \

ENV_DIR = env
ENV_FILES = $(addprefix $(ENV_DIR)/, \
	env_handle.c \
	env_init.c \
	env_set.c \
	env_get.c \
	env_to_envp.c \
	env_unset.c \
	env_clear.c \
	wrapper/ft_initenv.c \
	wrapper/ft_setenv.c \
	wrapper/ft_getenv.c \
	wrapper/ft_getenvp.c \
	wrapper/ft_unsetenv.c \
	wrapper/ft_clearenv.c \
	env_utils/env_var_len.c \
	env_utils/is_var_name.c \
	env_utils/realloc_env.c \
)

BUFFER_DIR = buffer
BUFFER_FILES = $(addprefix $(BUFFER_DIR)/, \
	pbuffer/pbuff_flush.c \
	pbuffer/pbuff_init.c \
	pbuffer/pbuff_write.c \
)

FILES = $(addprefix $(SRC_DIR)/, \
	$(CONVERTER_FILES) \
	$(FREE_FILES) \
	$(FT_PRINTF_FILES) \
	$(GET_NEXT_LINE_FILES) \
	$(IDENTIFER_FILES) \
	$(LIST_FILES) \
	$(MATHS_FILES) \
	$(MEMORY_FILES) \
	$(STRING_FILES) \
	$(VECTOR_FILES) \
	$(ENV_FILES) \
	$(BUFFER_FILES) \
)
