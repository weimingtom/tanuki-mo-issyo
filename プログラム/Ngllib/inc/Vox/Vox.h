#ifndef __VOX__
#define __VOX__

typedef enum{
	STATE_PAUSE = 0,
	STATE_PLAYING
} VOXSTATE;

typedef enum{
	CODE_SJIS = 0,
	CODE_UNICODE,
	CODE_UTF8
}CHARACTERCODE;

#pragma pack( push, 1 )
typedef struct{
	char **user_comments;
	int   *comment_lengths;
	int    comments;
	char  *vendor;
} VOXCOMMENT;
#pragma pack( pop )

// DLLコンパイル時にはコメントアウト
#ifndef VOXVC_EXPORTS

typedef int  __stdcall VoxLoad( char *pFileName );
typedef int __stdcall VoxPlay( int ID );
typedef int __stdcall VoxPause( int ID );
typedef int __stdcall VoxRelease( int ID );
typedef int __stdcall VoxSetLoop( int ID, int Count );
typedef int __stdcall VoxCheckDevice( int ID );
typedef int __stdcall VoxSetVolume( int ID, float Volume );
typedef float  __stdcall VoxGetVolume( int ID );
typedef int __stdcall VoxFade( int ID, float StartVolume, float EndVolume, int FadeTime );
typedef int __stdcall VoxDelete( int ID );
typedef int  __stdcall VoxGetTotalTime( int ID );
typedef int  __stdcall VoxGetCurrentTime( int ID );
typedef int __stdcall VoxSeek( int ID, int Time );
typedef int  __stdcall VoxGetStatus( int ID );
typedef VOXCOMMENT* __stdcall VoxGetComment( int ID );
typedef char* __stdcall VoxParseComment( int ID, char *pFieldName, CHARACTERCODE CharacterCode );

#endif

#endif // __VOX__
