# hgenerator
Generate a header with prototypes from current directory and sub-directories ignoring main et static functions  
1- make  
2- cp hgenerator where_you_want  
3- ./hgenerator your_header.h  
  
Notes : system calls not well protected but it works.  
Added :   
1- files name sorted by alphabetical order  
2- "execl rm header_name" before to create it  
3- ignore comments as prototypes
