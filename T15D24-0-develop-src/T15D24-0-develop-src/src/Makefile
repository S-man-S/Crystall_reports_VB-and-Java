GCC = gcc -Wall -Wextra -Werror

all:
	$(GCC) -o Quest modules_db.c shared.c master_modules.c master_levels.c master_status_events.c

clean:
	rm -rf Quest

rebuild: clean all