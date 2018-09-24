.PHONY: clean

hello: hello_world.c
	cc -o hello hello_world.c

copy_to_output: copy_to_output.c
	cc -o copy_to_output copy_to_output.c

charecter_counting: charecter_counting.c
	cc -o charecter_counting charecter_counting.c

print: print.c
	cc -o print print.c

reverse_line: reverse_line.c
	cc -o reverse_line reverse_line.c

detab: detab.c
	cc -o detab detab.c	

entab: entab.c
	cc -o entab entab.c

line_folder: line_folder.c line_folder.h
	cc -o line_folder line_folder.c

remove_comments: remove_comments.c
	cc -o remove_comments remove_comments.c
clean:
	rm -f hello copy_to_output copy_to_output charecter_counting print reverse_line detab entab remove_comments line_folder
