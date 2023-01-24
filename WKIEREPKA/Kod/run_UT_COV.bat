gcc -fprofile-arcs -ftest-coverage -g UT_LinNm.c -o UT_LinNm.exe
UT_LinNm.exe
gcov UT_LinNm.c
gcovr --html-details LinNm_Coverage_Report.html
del *.gcov
del *.gcda
del *.gcno
del *.exe
cmd /k