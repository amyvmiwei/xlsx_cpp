#pragma once
/*
 this file is come from minizip/miniunz.c
*/

#include "unzip.h"

#define CASESENSITIVITY (0)
#define WRITEBUFFERSIZE (8192)
#define MAXFILENAME (256)

static int do_extract_currentfile(unzFile uf, const int* popt_extract_without_path,
							int* popt_overwrite,
							const char* password);

static int do_extract_onefile(unzFile uf, const char* filename, 
					int opt_extract_without_path, 
					int opt_overwrite,
					const char* password)
{
	int err = UNZ_OK;
	if (unzLocateFile(uf, filename, CASESENSITIVITY)!=UNZ_OK)
	{
		printf("file %s not found in the zipfile\n", filename);
		return 2;
	}

	if (do_extract_currentfile(uf, &opt_extract_without_path, &opt_overwrite,
									  password) == UNZ_OK)
		return 0;
	else
		return 1;
}


static int do_extract_currentfile(unzFile uf, const int* popt_extract_without_path, 
							int* popt_overwrite, const char* password)
{
	char filename_inzip[256];
	char* filename_withoutpath;
	char* p;

	int err = UNZ_OK;
	FILE* fout = NULL;
	void* buf;
	uInt size_buf;

	unz_file_info64 file_info;
	uLong ratio = 0;
	err = unzGetCurrentFileInfo64(uf, &file_info, filename_inzip, sizeof(filename_inzip),NULL,0,NULL,0);

	if (err != UNZ_OK)
	{
		printf("error %d with zipfile in unzGetCurrentFileInfo64\n", err);
		return err;
	}

	size_buf = WRITEBUFFERSIZE;
	buf = (void*)malloc(size_buf);
	if (buf == NULL)
	{
		printf("error allocating memory\n");
		return UNZ_INTERNALERROR;
	}

	p = filename_withoutpath = filename_inzip;
	while ((*p) != '\0')
	{
		if (((*p)=='/') || (*p)=='\\')
			filename_withoutpath = p+1;
		p++;
	}

	if ((*filename_withoutpath)=='\0')
	{
		//this is maybe a directory;
// 		if ((*popt_extract_without_path)==0)
// 		{
// 			printf("creating directory : %s \n", filename_inzip);
// 			mymkdir(filename_inzip);
// 		}
	}
	else
	{
		const char* write_filename;
		int skip = 0;

		if ((*popt_extract_without_path)==0)
			write_filename = filename_inzip;
		else
			write_filename = filename_withoutpath;

		err = unzOpenCurrentFilePassword(uf, password);
		if (err != UNZ_OK)
		{
			printf("error %d with zipfile in unzOpenCurrentFilePassword\n", err);
		}

// 		if ((skip==0) && (err==UNZ_OK))
//         {
//             fout=fopen64(write_filename,"wb");
// 
//             /* some zipfile don't contain directory alone before file */
//             if ((fout==NULL) && ((*popt_extract_without_path)==0) &&
//                                 (filename_withoutpath!=(char*)filename_inzip))
//             {
//                 char c=*(filename_withoutpath-1);
//                 *(filename_withoutpath-1)='\0';
//                 makedir(write_filename);
//                 *(filename_withoutpath-1)=c;
//                 fout=fopen64(write_filename,"wb");
//             }
// 
//             if (fout==NULL)
//             {
//                 printf("error opening %s\n",write_filename);
//             }
//         }

		if (err == UNZ_OK)
		{
			printf("extracting: %s\n", write_filename);
			do 
			{
				err = unzReadCurrentFile(uf, buf, size_buf);
				if (err < 0)
				{
					printf("error %d with zipfile in unzReadCurrentFile\n", err);
					break;
				}
				if (err > 0)
				{
					//.
				}
			} while (err > 0);

			err = unzCloseCurrentFile(uf);
			
		}
	}
	free(buf);
	return err;
}
