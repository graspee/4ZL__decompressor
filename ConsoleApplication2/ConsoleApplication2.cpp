// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <xmmintrin.h>
#include <string>
#include <fstream>

#define BYTE unsigned char;

int probably4LZDecompress(unsigned int maybeOutBuffer, unsigned char* compressedBuffer, int firstDwordMinusOne, int secondDword)
{

	unsigned char* v4; // eax@1
	unsigned int v5; // edi@1
	int v6; // edx@1
	int result; // eax@4
	unsigned int v8; // ebx@6
	size_t v9; // ebx@6
	int v10; // esi@7
	unsigned int v11; // esi@10
	unsigned int v12; // edx@10
	unsigned short* v13; // esi@11
	int v14; // eax@12
	unsigned int* v15; // ebx@12
	unsigned int v16; // ecx@14
	int v17; // esi@14
	int v18; // edi@15
	int v19; // ecx@16
	unsigned int v20; // edi@20
	unsigned int v21; // ebx@20
	char* v22; // esi@21
	char* v23; // esi@21
	int v24; // ecx@22
	unsigned char* v25; // edx@23
	unsigned char* v26; // edi@26
	int v27; // ebx@26
	unsigned int v28; // edi@29
	int v29; // ecx@29
	unsigned int v30; // ebx@32
	char v31; // cl@33
	unsigned int v32; // edi@36
	int* v33; // ebx@36
	int v34; // ecx@37
	unsigned char* v35; // [sp+0h] [bp-60h]@1
	unsigned int v36; // [sp+4h] [bp-5Ch]@1
	int v37; // [sp+8h] [bp-58h]@1
	int v38; // [sp+Ch] [bp-54h]@1
	unsigned int v39; // [sp+10h] [bp-50h]@20
	unsigned int v40; // [sp+14h] [bp-4Ch]@1
	unsigned int v41; // [sp+14h] [bp-4Ch]@14
	char v42; // [sp+18h] [bp-48h]@6
	unsigned int v43; // [sp+18h] [bp-48h]@24
	__m128 v44; // [sp+1Ch] [bp-44h]@1
	__m128 v45; // [sp+2Ch] [bp-34h]@1
	int v46; // [sp+3Ch] [bp-24h]@1
	int v47; // [sp+40h] [bp-20h]@1
	int v48; // [sp+44h] [bp-1Ch]@1
	int v49; // [sp+48h] [bp-18h]@1
	int v50; // [sp+4Ch] [bp-14h]@1
	int v51; // [sp+50h] [bp-10h]@1
	int v52; // [sp+54h] [bp-Ch]@1
	int v53; // [sp+58h] [bp-8h]@1

	v4 = compressedBuffer;
	v35 = compressedBuffer;
	v5 = maybeOutBuffer;
	v36 = maybeOutBuffer;
	v6 = (int)& compressedBuffer[firstDwordMinusOne];// first byte of compressed data
	v40 = v36;
	v38 = (int)& compressedBuffer[firstDwordMinusOne];
	v37 = secondDword + v36;
	v46 = 0;
	v47 = 1;
	v48 = 2;
	v49 = 1;
	v50 = 4;
	v51 = 4;
	v52 = 4;
	v53 = 4;

	__m128 xmmword_116C4370;
	__m128 xmmword_116C2380;
	xmmword_116C4370.m128_u64[0] = 0xFFFFFFFF00000000;
	xmmword_116C4370.m128_u64[1] = 0x0000000000000000;

	xmmword_116C2380.m128_u64[0] = 0x0000000300000002;
	xmmword_116C2380.m128_u64[1] = 0x0000000100000000;

	/*_mm_storeu_ps
	_mm_storeu_si128((__m128i*) & v44, _mm_load_si128((const __m128i*) & xmmword_116C4370));
	_mm_storeu_si128((__m128i*) & v45, _mm_load_si128((const __m128i*) & xmmword_116C2380));*/

	//looks like _mm_storeu_si128 stores to &v44, and _mm_load_si128 loads _m128, so that's just v44=xmmword...
	v44 = xmmword_116C4370;
	v45 = xmmword_116C2380;


	if (secondDword)
	{
		while (1)
		{
			v8 = *v4++;
			v42 = v8;
			v9 = v8 >> 4;
			if (v9 == 15)
			{
				do
				{
					v10 = *v4++;
					v9 += v10;
				} while ((unsigned int)v4 < v6 - 15 && v10 == 255);
				v5 = v40;
				if (v9 + v40 < v40 || &v4[v9] < v4)
					return v35 - v4 - 1;
			}
			v11 = secondDword + v36;
			v12 = v9 + v5;
			if (v9 + v5 > v37 - 12)
				goto LABEL_41;
			v13 = (unsigned short*)& v4[v9];
			if ((unsigned int)& v4[v9] > v38 - 8)
			{
				v11 = secondDword + v36;
			LABEL_41:
				if (&v4[v9] == (unsigned char*)v38 && v12 <= v11)
				{
					memcpy((void*)v5, v4, v9);
					return v5 + v9 - v36;
				}
				return v35 - v4 - 1;
			}
			v14 = (int)& v4[-v5];
			v15 = (unsigned int*)(v9 + v5);
			do
			{
				*(unsigned int*)v5 = *(unsigned int*)(v14 + v5);
				*(unsigned int*)(v5 + 4) = *(unsigned int*)(v14 + v5 + 4);
				v5 += 8;
			} while (v5 < v12);
			v16 = *v13;
			v4 = (unsigned char*)v13 + 2;
			v17 = v12 - v16;
			v41 = v16;
			if (v12 - v16 < v36)
				return v35 - v4 - 1;
			v18 = v42 & 0xF;
			*v15 = v16;
			if (v18 == 15)
			{
				while (1)
				{
					v19 = *v4++;
					if ((unsigned int)v4 > v38 - 5)
						return v35 - v4 - 1;
					v18 += v19;
					if (v19 != 255)
					{
						if ((unsigned int*)((char*)v15 + v18) < v15)
							return v35 - v4 - 1;
						v16 = v41;
						break;
					}
				}
			}
			v20 = v18 + 4;
			v21 = (unsigned int)v15 + v20;
			v39 = v21;
			if (v16 >= 8)
			{
				*(unsigned int*)v12 = *(unsigned int*)v17;
				v24 = *(unsigned int*)(v17 + 4);
				v23 = (char*)(v17 + 8);
				*(unsigned int*)(v12 + 4) = v24;
			}
			else
			{
				*(unsigned char*)v12 = *(unsigned char*)v17;
				*(unsigned char*)(v12 + 1) = *(unsigned char*)(v17 + 1);
				*(unsigned char*)(v12 + 2) = *(unsigned char*)(v17 + 2);
				*(unsigned char*)(v12 + 3) = *(unsigned char*)(v17 + 3);
				v22 = (char*)(*(&v46 + v41) + v17);
				*(unsigned int*)(v12 + 4) = *(unsigned int*)v22;
				v23 = &v22[-*((unsigned int*)& v44 + v41)];
			}
			v25 = (unsigned char*)(v12 + 8);
			if (v21 <= v37 - 12)
				break;
			v43 = v37 - 7;
			if (v21 > v37 - 5)
				return v35 - v4 - 1;
			if ((unsigned int)v25 < v37 - 7)
			{
				v26 = v25;
				v27 = (unsigned char)v23 - (unsigned char)v25;
				do
				{
					*(unsigned int*)v26 = *(unsigned int*)& v26[v27];
					*((unsigned int*)v26 + 1) = *(unsigned int*)& v26[v27 + 4];
					v26 += 8;
				} while ((unsigned int)v26 < v43);
				v21 = v39;
				v23 += v43 - (unsigned int)v25;
				v25 = (unsigned char*)(v37 - 7);
			}
			v28 = 0;
			v29 = v21 - (unsigned int)v25;
			if ((unsigned int)v25 > v21)
				v29 = 0;
			if (v29)
			{
				v30 = v29;
				do
				{
					v31 = *v23++;
					++v28;
					*v25++ = v31;
				} while (v28 < v30);
				v5 = v39;
				v6 = v38;
				v40 = v39;
			}
			else
			{
			LABEL_39:
				v6 = v38;
				v5 = v21;
				v40 = v21;
			}
		}
		*(unsigned int*)v25 = *(unsigned int*)v23;
		*((unsigned int*)v25 + 1) = *((unsigned int*)v23 + 1);
		if (v20 > 0x10)
		{
			v32 = (unsigned int)(v25 + 8);
			v33 = (int*)(v23 + 8);
			do
			{
				v34 = *v33;
				v33 += 2;
				*(unsigned int*)v32 = v34;
				*(unsigned int*)(v32 + 4) = *(v33 - 1);
				v32 += 8;
			} while (v32 < v39);
			v21 = v39;
		}
		goto LABEL_39;
	}
	if (firstDwordMinusOne != 1 || *compressedBuffer)
		result = -1;
	else
		result = 0;
	return result;
}

int main()
{
	std::ifstream fdFi("D:\\ff8_R\\zzz\\outzzz\\data\\field.fi");
	std::ifstream fdFl("D:\\ff8_R\\zzz\\outzzz\\data\\field.fl");
	std::ifstream fdFs("D:\\ff8_R\\zzz\\outzzz\\data\\field.fs");
	std::string whichFile = "mapdata.fl"; //CHANGE ME
	std::ofstream output("D:\\ff8_R\\zzz\\outzzz\\data\\field\\mapdata.fl"); //CHANGE ME

	std::string str;
	int fileIndex = 0;
	while (std::getline(fdFl, str))
	{
		std::size_t found = str.find(whichFile);
		if (found != std::string::npos)
			break;
		fileIndex++;
	}

	fdFl.close();

	fdFi.seekg((long long)12 * fileIndex, fdFi._Seekbeg);
	int uncompressedSize, absolutePosition, compressionMethod;
	fdFi.read((char*)& uncompressedSize, sizeof(uncompressedSize));
	fdFi.read((char*)& absolutePosition, sizeof(absolutePosition));
	fdFi.read((char*)& compressionMethod, sizeof(compressionMethod));
	fdFi.close();

	fdFs.seekg(absolutePosition, fdFs._Seekbeg);
	int fileSizeAbs;
	fdFs.read((char*)& fileSizeAbs, 4);
	fileSizeAbs += 4; 
	fdFs.seekg(-4, 1);

	unsigned char* buffer = (unsigned char*)calloc(fileSizeAbs, 1);
	fdFs.read((char*)buffer, fileSizeAbs);

	unsigned int firstDword = (*buffer) - 8;
	unsigned int secondDword = *(buffer + 8);
	unsigned char * buffer_ = (unsigned char*)(buffer + 12);
	unsigned int* outBuffer = (unsigned int*)calloc(firstDword, 1);
	unsigned int firstParm = (unsigned int)outBuffer;
	int testing = probably4LZDecompress((unsigned int)firstParm, buffer_, firstDword, secondDword);
	if (testing < 0)
	{
		std::cout << "SOME ERROR IDK YET";
		std::getchar();
		return -1;
	}
	else
	{
		output.write((const char*)outBuffer, firstDword-1);
		output.close();
	}
}

