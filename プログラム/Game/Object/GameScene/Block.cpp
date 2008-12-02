#include	"Object/GameScene/Block.h"
#include	"Define/TextureID.h"
#include	"Define/EffectID.h"

Block::Block(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, int blockCID, int blockMID) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
	x = 0.0f;
	y = 0.0f;
	size = 100.0f;
	blockID[0] = blockCID;
	blockID[1] = blockMID;
	InitializeMatrix();
	speed = 2;

	device.GetGraphicDevice().LoadTexture(TextureID::TEXTUREID_TEST,"block.dds",COLORKEYFLAG_NONE);
}

Block::~Block()
{

}

void Block::Initialize()
{

}

void Block::Terminate()
{
	m_isTerminated = true;
}

bool Block::IsTerminated()
{
	return m_isTerminated;
}

void Block::RenderObject()
{
	Matrix4 rotate;
	rotate.setTranslate(1.0f,0.5f,0.5f);
	SpriteDesc sd;
	sd.textureID = TextureID::TEXTUREID_TEST;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			sd.rect = Rect(x-(size*j),y+(size*i),x+(size*(j+1)),y+(size*(i+1)));
			if(blockMatrix[i][j] != 0 ){
				sd.rect = Rect(x+(size*j)-(size*1.5),y+(size*i)-(size*1.5),x+(size*(j+1)-(size*1.5)),y+(size*(i+1)-(size*1.5)));
				m_device.GetGraphicDevice().Render( sd );
			}
		}
	}
}

void Block::UpdateObject(float frameTimer)
{
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_LEFT) == true) 
	{
		x += 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_RIGHT) == true) 
	{
		x -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_UP) == true) 
	{
		y -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_DOWN) == true) 
	{
		y += 1.0f;
	}

	y = y+speed;
}

void Block::InitializeMatrix()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			blockMatrix[i][j] = 0;
		}
	}
	blockMatrix[1][1] = blockID[0];
	blockMatrix[2][1] = blockID[1];
}