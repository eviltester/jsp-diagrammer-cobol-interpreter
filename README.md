jsp-diagrammer-cobol-interpreter
================================

A JSP diagrammer and Cobol interpreter for the Atari ST

This was my University Honours project over 20 years ago. 

It was a crude JSP diagrammer with a built in COBOL interpreter - because they were future in the late 80s and early 90s.

This is the end result code, I've lost the early code. Because some of the diagrammer was actually bootstrapped from a set of JSP diagrams, which I ran through a COBOL-to-C translator (because the JSP diagrammers only output COBOL, and I was writing in C).

I've lost the latex files for the project report, otherwise I would upload those as well.

Public Domain in the hope it provides value to someone.

I have uploaded the scanned versions of the thesis, the follow on paper and the interim report.

I split the thesis in to sections:
* 000-105-Thesis-Main.pdf is the most interesting part, with the actual description of the project and aims
* 106-180-Appendix-E-Cobol_to_C-and_Generated_Code.pdf is a curio. It shows all the JSP diagrams for a Cobol to C translator with the generated source code
* 181-349-Appendix-F-Cobol_Interpreter_JSP_and_generated_code.pdf is another curio. It shows all the JSP diagrams for the Cobol interpreter, with the generated C code.
* 350-506-Appendix-G-C-Code.pdf show the C code I wrote. Interestingly I used some formal methods for this and 'proved' them correct to my satisfaction and the University. And I let bugs slip into the implementation.
