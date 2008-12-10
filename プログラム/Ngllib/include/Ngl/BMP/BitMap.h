/*******************************************************************************/
/**
 * @file BitMap.h.
 * 
 * @brief �r�b�g�}�b�v�\���̃w�b�_�t�@�C��.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_BITMAP_H_
#define _NGL_BMP_BITMAP_H_


namespace Ngl{


namespace BMP{


/** ��������8bit�^ */
typedef unsigned char BYTE;

/** �����Ȃ�16bit�^ */
typedef unsigned short WORD;

/** ��������32bit�^ */
typedef unsigned long DWORD;

/** �����t32bit�^ */
typedef long LONG;


/**
 * @struct BitMapFileHeader.
 * @brief BMP �r�b�g�}�b�v�t�@�C���w�b�_�\����.
 */
struct BitMapFileHeader
{
	 WORD    bfType;		/**< �t�@�C���^�C�v							*/
	 DWORD   bfSize;		/**< �r�b�g�}�b�v�t�@�C���T�C�Y				*/
	 WORD    bfReserved1;	/**< ���ݎg���Ă��Ȃ�						*/
	 WORD    bfReserved2;	/**< ���ݎg���Ă��Ȃ�						*/
	 DWORD   bfOffBits;		/**< ���̍\���̂���摜�r�b�g�܂ł̃o�C�g��	*/
};


/**
 * @struct BitMapInfoHeader.
 * @brief BMP �r�b�g�}�b�v���w�b�_�\����.
 */
struct BitMapInfoHeader
{
	DWORD  biSize;			/**< �\���̂̃o�C�g�� ( sizeof(BitMapInfoHeader) )	*/
	LONG   biWidth;			/**< �r�b�g�}�b�v�̕�( �s�N�Z���P��					*/
	LONG   biHeight;		/**< �r�b�g�}�b�v�̍���( �s�N�Z���P��				*/
	WORD   biPlanes;		/**< �^�[�Q�b�g�f�o�C�X�̂��߂̃v���[���� ( �K��1	*/
	WORD   biBitCount;		/**< 1�s�N�Z��������̃r�b�g��( 0,1,4,8,16,24,32 )	*/
	DWORD  biCompression;	/**< ���k�t�H�[�}�b�g�t���O							*/
	DWORD  biSizeImage;		/**< �摜�̃T�C�Y									*/
	LONG   biXPelsPerMeter;	/**< �^�[�Q�b�g�f�o�C�X�̐��������̉𑜓x			*/
	LONG   biYPelsPerMeter;	/**< �^�[�Q�b�g�f�o�C�X�̐��������̉𑜓x			*/
	DWORD  biClrUsed;		/**< �J���[�e�[�u���̃f�[�^��						*/
	DWORD  biClrImportant;	/**< �\������̂ɕK�v�ȃJ���[�e�[�u���f�[�^��		*/
};


/**
 * @struct RGBQuad.
 * @brief BMP RGB�f�[�^�\����.
 */
struct RGBQuad
{
	BYTE    rgbBlue;		/**< ����	*/
	BYTE    rgbGreen;		/**< �ΐ���	*/
	BYTE    rgbRed;			/**< �Ԑ���	*/
	BYTE    rgbReserved;	/**< �\��	*/
};


/**
 * @enum BitCount.
 * @brief BMP �r�b�g�J�E���g�񋓌^.
 */
enum BitCount
{
	BITCOUNT_2	= 2,	/**< 2�F�r�b�g�}�b�v				*/
	BITCOUNT_4	= 4,	/**< 4�F�r�b�g�}�b�v				*/
	BITCOUNT_8	= 8,	/**< 256�F�r�b�g�}�b�v				*/
	BITCOUNT_24	= 24,	/**< 24�r�b�g�t���J���[�r�b�g�}�b�v	*/
	BITCOUNT_32	= 32	/**< 32�r�b�g�A���t�@�t�r�b�g�}�b�v	*/
};


/** �r�b�g�}�b�v���ʃt���O */
static const unsigned short BITMAPFLAG = 0x4D42;


/**
 * @struct BitMap.
 * @brief BMP �r�b�g�}�b�v�f�[�^�\����.
 */
struct BitMap
{
	/** �t�@�C���w�b�_ */
	BitMapFileHeader	fileHeader;

	/** �t�@�C����� */
	BitMapInfoHeader	infoHeader;

	/** RGB�p���b�g�f�[�^�z�� */
	RGBQuad				rgbQuad[ 256 ];


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	BitMap();

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/