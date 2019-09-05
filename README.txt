THIS IS NOT FINISHED YET!
Thanks to Hoodium for lifting anti-debugger/x86Emulation

so Demaster destroyed everything and changed everything- this includes zzz files and new comp method for FS files. This software is hack implementation of rebuilt decompression function from disassembly for unpacking 4ZL_ FS files (comp=2)

Usage:
It's more like test software right now. Change line 261 and line 262 it's about std::string whichFile and std::ofstream output, also the fdFi, fdFl and fdFs unpacked from zzz
Do not use Deling yet- it doesn't support comp=2 and unpacks wrong data

Right now the disassembly function is not perfect- there are some wrong data about pseudo-code. 
Usually deriveration between BYTE* and WORD* and DWORD* like:

psuedocode:
v13 + 1

assembler:
ADD [reg], 2

why?
because v13 is short, so short+1 is actually byte+2- so there are that kind of errors in there.
There are more errors like this- worth looking at casting