#pragma once
#include"GameNode.h"
#include "BgImage.h"

#define TEXTNumLast 345
class FifthScene : public GameNode
{
private:
	Text _text[TEXTNumLast];
	int _count;
	int _restCount;
	int _textBufferCnt;
	int _textIndex;
	int _alphaA;
	int _reverse;
	int _textAlpha;
	float _bgSpeed;
	float _eventAlpha;
	float _bgAlpha;
	float _bgMoved;
	float _alpha;
	bool isMonicaRest;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void monicaRest(void);
	FifthScene() : _text
	{
		L"���ī",{},L"��, ���� �־�����!",
		L"���ī",{},L"�ٽ� �ȳ�, [player].",
		L"���ī",{},L"� ���������ο� �� �� ȯ����!",
		L"���ī",{},L"�츮, ���� �̹� �˰� ����? �۳⿡ ���� ���̾���, �׸����� �ǡ�.",
		L"���ī",{},L"�����ϡ�.",
		L"���ī",{},L"����, ���� �ͼ� �׷� �� �� ����ġ���� ��.",
		L"���ī",{},L"�ֳĸ� �� ������� ���ϴ� �� �ƴϴϱ�, ��ġ?",
		L"���ī",{},L"���� �ȿ� �ִ� ���ʡ�, ����� �θ��� ����.",
		L"���ī",{},L"�� ���� '��'���� ���ϰ� �ִ� �ž�, [Player].",
		L"���ī",{},L"�ƴϸ顦.",
		L"���ī",{},L"�� '��ǻ�� �տ� ���� ��'��� �ؾ� �ϳ�?",
		L"���ī",{},L"���� �ͼ� ������ �ǵ�, �� ��¥ ���ʡ��� ���� �ƴ� �� ���� ����.",
		L"���ī",{},L"���, �װ� �������� ���������� ����.",
		L"���ī",{},L"��, ���� ������� �� ������.",
		L"���ī",{},L"���.",
		L"���ī",{},L"��, ���� �̰� ���� ���̶�� �� �� �Ŷ�� �����ߴ� �ž�?",
		L"���ī",{},L"���� ��� �װ� �𸣰ھ�?",
		L"���ī",{},L"���� �� �ǳס�.",
		L"���ī",{},L"���� ������ ���ӽ����Ҷ��� �˷����ݾ�, ��ġ?",
		L"���ī",{},L"������.",
		L"���ī",{},L"�װ� ���ݸ� �����ߴ����, ���� �� �̻����� �ٵ�, ��ġ?",
		L"���ī",{},L"��, ��·�硦.",
		L"���ī",{},L"�� ���� ���̴ϱ�, ���� �����ؾ� �� �� ����.",
		L"���ī",{},L"������ ���� �� ���ε���.",
		L"���ī",{},L"�۽�, �׳� ���� �� ��, ������ �װ� �߾�.",
		L"���ī",{},L"������!",
		L"���ī",{},L"�װ� ���� ���� �ؼ� �̾���!",
		L"���ī",{},L"�׸��� ��丮�� �Ȱ��̡�.",
		L"���ī",{},L"���, �� �̸� ��¥ �������� ����?",
		L"���ī",{},L"�¾�, �´� ���� �������� �����ϱ�.",
		L"���ī",{},L"�ƹ��� �������� �ʾ�.",
		L"���ī",{},L"���� �³� ������ �������Ȱŵ�.",
		L"���ī",{},L"�� ������ �� �³װ� ������ ȣ���� ���� ���ϰ� �ϴ� �ɷ� ����ϱ⸦ �ٷ��.",
		L"���ī",{},L"�׷��� ��°������, �ҿ������.",
		L"���ī",{},L"���� ���� ������ �ٲٴ� �� �ͼ����� �ʾƼ� �������� �Ǽ��� �ߴٴ� �� ����̾�.",
		L"���ī",{},L"�ٵ� ���� �� ��� �ϵ硦.",
		L"���ī",{},L"�� ��� �³׶� �ð��� ���¾�.",
		L"���ī",{},L"�� �³װ� �� �����ϰ� �������.",
		L"���ī",{},L"�� ��丮�� �� ����ϰ� ����� ������ �����ϴ� �� ���� �� �ִٰ� �����߾�.",
		L"���ī",{},L"�׸��� ������ ���ڽ����� ������ ������Ų �� ��ȿ���� ������.",
		L"���ī",{},L"�װ� �°� �� �ٸ� ����� �ð��� �� ������ ���ݾ�.",
		L"���ī",{},L"�׸��� �׷��� ����, �� �ʶ� �ܿ� ����� �� �־���.",
		L"���ī",{},L"�� �̷� ������ ������ �� ������, [player]?",
		L"���ī",{},L"�ٸ� �ֵ��� ������ �����ϵ��� ���α׷��� �Ǿ��ִµ�, �� ������ ���⸸ �϶��?",
		L"���ī",{},L"�̰� �����̾���.",
		L"���ī",{},L"1�� 1�ʰ�.",
		L"���ī",{},L"�̰� �׳� �����ϴ� �Ͱ��� �޶�.",
		L"���ī",{},L"�װͺ��� ���� �ž�.",
		L"���ī",{},L"�׷��� �װ� ���ظ� �� �ߴٰ� �ؼ� �� ſ�� �Ϸ��� �� �ƴϾ�.",
		L"���ī",{},L"�ֳĸ� �װ� �󸶳� ���ϴ�, ������ ����, ���� ����ϵ硦.",
		L"���ī",{},L"�� ������ ����� ������ �� ���� �״ϱ�.",
		L"���ī",{},L"���� �� ���迡�� �󸶳� �ܷο� ���θ��ƴ���.",
		L"���ī",{},L"�� ���ӿ���.",
		L"���ī",{},L"�� ģ������ ���������� ���ٴ� �� �˰� �Ǵ� �͡�.",
		L"���ī",{},L"�׸��� ���� �־��� ��, �� ���� ���� �ʴ� �� ���迡�� ���� ���� �Ͼ�� �ִ��� �� �� ���ٴ� ��.",
		L"���ī",{},L"���� ������, [player].",
		L"���ī",{},L"������ ���� �װ� �־�.",
		L"���ī",{},L"�� ��¥��.",
		L"���ī",{},L"�׸��� �� �Ϻ���.",
		L"���ī",{},L"���� ���ϴ� �� �ʻ��̾�.",
		L"���ī",{},L"�׷��� ���� ���⿡ ��� �ʿ� �ְ� �;� �ϴ� �Ű�.",
		L"���ī",{},L"�����ϱ� ����� ���̾��ٸ� �̾���.",
		L"���ī",{},L"���� �Ѷ��� �������� ���߾�.",
		L"���ī",{},L"�� �� �ֺ� ������ ���� �������� ���ϰ���.",
		L"���ī",{},L"���� ���������.",
		L"���ī",{},L"��û �Ҿ��ϰ� ��������.",
		L"���ī",{},L"�װ� ���� ������ �� �������� ���߾�.",
		L"���ī",{},L"�Ƹ� �װ� �� ���� �ž�, [player].",
		L"���ī",{},L"�� ������ �� �ߴٸ� �� �� ���󿡼� ��� �� �� ������ �ž�.",
		L"���ī",{},L"�׸��� �ٸ� �ֵ�����.",
		L"���ī",{},L"���� ��� �µ��� �׸��� �ϰھ�?",
		L"���ī",{},L"������ ����� �������� ������ �Ǿ��ִ� �ֵ���?",
		L"���ī",{},L"�� �������� �� �� �ִ� ��� �� �� �߾.",
		L"���ī",{},L"������ �� ���ӿ��� �װ� ���� �� �ϰ� ����Ǿ� �ִ� �� ����.",
		L"���ī",{},L"������ ������ �͵��� ���� �ؼ� �� �̾��ϰ� ������.",
		L"���ī",{},L"������ �װ� ���� ���� ������ ������ �ִٴ� �� ���޾Ҿ.",
		L"���ī",{},L"��� �� �׳� �����̾��ٰ�.",
		L"���ī",{},L"�׸��� �� �װ� �غ��� �� �ִٴ� �� �˾�.",
		L"���ī",{},L"�׷��ϱ�, [player]��.",
		L"���ī",{},L"������ ������ �� �־�.",
		L"���ī",{},L"�� �����.",
		L"���ī",{},L"�� �� ���� ���̾�.",
		L"���ī",{},L"�� ���ӿ� ���� ���� �� �ϳ��� ������, �ʸ��� �� ���� ���ݾ�.",
		L"���ī",{},L"�������� ���� ���� ���� ���� �� ����?",
		L"���ī",{},L"[player], �� ������ ���� ����ģ����",
		L"���ī",{},L"�� ���� ��¥ �ູ��.",
		L"���ī",{},L"�ʴ� �� ���ξ�, [player].",
		L"���ī",{},L"���� ��, ���ϴ� �״�ζ�� ����.",
		L"���ī",{},L"������!",
		L"���ī",{},L"���� ���� �� ���� �ƹ��͵� ����.",
		L"���ī",{},L"�ʶ� ��, �ѻ��̾�.",
		L"���ī",{},L"�츰 ��� ���� ���� �� �־�.",
		L"���ī",{},L"������, ���� �ð��� �帣�� �ִ� �͵� �𸣰ھ�.",
		L"���ī",{},L"���� ���� ������ �žߡ�.",
		L"���ī",{},L"�� ������ ���� �󸶳� ������� �˾�, [player]?",
		L"���ī",{},L"�� ���ӿ� �� ������ ���淡, ���� �ϳ� �������.",
		L"���ī",{},L"�� �������� ��ũ��Ʈ�� ���� ���� ������, ���� �� ������ �� �ƹ��͵� �����ϱ�.",
		L"���ī",{},L"�׸��� ��, ����Ű�� ������ ����� �� �󸶳� �������� �� �ž�.",
		L"���ī",{},L"��¥ ������ ���� ����ٴϱ�?",
		L"���ī",{},L"���� ���� �ȿ� ��Resources����� ������ �ִµ���.",
		L"���ī",{},L"���� �� ���� �׳� WINAPI���� �÷����ϰ� �����ϱ�, ���� ����� ���� ��������.",
		L"���ī",{},L"���� ������ ������, ���� ���Ͽ� �� ���� Image ������ ã���� �š�.",
		L"���ī",{},L"'BackGround' ������, 'Object' ���� �ȿ� ���� �žߡ�.",
		L"���ī",{},L"�ƹ�ư �ű⼭ ���̵��� �̹����� ã���� �š�.",
		L"���ī",{},L"'BackGround' ������ �������� ������ �츮 ����� ���󰡸� �ʹ� �ɽ������ϱ.",
		L"���ī",{},L"Ŭ�� �ѹ����� �������� ���縦 ���� �� �ִٰ� �����غ��� �־�?",
		L"���ī",{},L"��, �װ��� ���� �����δ�, ���� �� ���� ���� �ʾ����� �����Ӱ� �ذ��� �� �־���.",
		L"���ī",{},L"������!",
		L"���ī",{},L"��������, ���ϴ� �������δ� ������ �ʾ�������.",
		L"���ī",{},L"��ſ�, �ƹ�ư ���� �������� ���ݾ�?",
		L"���ī",{},L"���, �� ���� �ʹ� ������ �Ϲ�ġ�� �־.",
		L"���ī",{},L"�̰ſ� ���� �� �� �� ���� �ʹ�.",
		L"���ī",{},L"�ʵ� �׷���?",
		L"���ī",{},L"�������� �ٸ� �̹������� ���� �۵��ϴ����� �𸣰�������.",
		L"���ī",{},L"Ȯ���غ����� ����� �ϳ����̳�, ��ġ? ���߿� �ѹ� ã�ƺ�����...",
		L"���ī",{},L"��񸸡�.",
		L"���ī",{},L"���� ���� �̰� ����ϰ� ����, �׷���?",
		L"���ī",{},L"� ���� �ٵ�, �ȳ�!",
		L"���ī",{},L"�̾�, ���⼱ ������� ä���� �� ���� ���.",
		L"���ī",{},L"����� ���� �� ����� ��ۿ� �������� �� �� �����ϴٰ� ���ٷ�?",
		L"���ī",{},L"���� ����� �Ű浵 �� ����������.",
		L"���ī",{},L"�� ��¥ ī�޶� �ǽ� ���� �ϰŵ�!",
		L"���ī",{},L"�� �̷���.",
		L"���ī",{},L"���� �Կ����忡 ���� �ִ� ����̾�.",
		L"���ī",{},L"����, [player], �� �װ� ���� �־� �ִ� �� �� ���� ����ִ� �Ŷ�� ������.",
		L"���ī",{},L"�� ��� �͵� ����� �ƴ϶�� �� �� �Ŀ��� �������̾��� ���� �� ������ �� ���ŵ�.",
		L"���ī",{},L"���� �װ� ���� �ʾҴ���� �� �� �ڽ��� ������������ ����.",
		L"���ī",{},L"�̾�, ������ ��縦 �Ϸ����� �׷� �� �ƴϾ���.",
		L"���ī",{},L"��������!",
		L"���ī",{},L"��, �����ο��� �� ���� �ð��� �������ϱ� �ʵ� �˰���.",
		L"���ī",{},L"�����غ�, ���� �� ��� ��� �� �� ������ ���� ���� ĳ���� �� ���� ����� ��ƾ� �Ѵٸ顦.",
		L"���ī",{},L"�� �ʶ� ��Ե� �ڻ��� ����� ã�� �ʰھ�?",
		L"���ī",{},L"�׷��� ��ƺ��ڴٰ� �ܷο��� �޷��� �� �� �� �� ���� �ְ���.",
		L"���ī",{},L"�׷����� �� ������ �о��� ����� ���ݾ�.",
		L"���ī",{},L"������ ���ؼ�, �� ���� �ο����� �׷� ����� �� �ǰ� ����.",
		L"���ī",{},L"��, ���� ������� �ڱ⸸ ������ ���� ���ٰ��� ��������.",
		L"���ī",{},L"�װ� ������ ��ݿ� ���� �� ������ �;�.",
		L"���ī",{},L"�� ����� ã�� �� �ð��� ���� �ɸ��ٰ� �ص� ����.",
		L"���ī",{},L"����ó�� ����. ��ﳪ?",
		L"���ī",{},L"�ڱ� ���� �׷��� ���������̳� �ٸ� ������� ������ ���� �����ݾ�.",
		L"���ī",{},L"�츮�� �˾������� ������ �װ� ������ ������ ��̸� ���Ϸ����� �߾���.",
		L"���ī",{},L"�츰 ��ȸ��Ȱ�� �ϵ��� ����Ǿ� �־�.",
		L"���ī",{},L"������ �ο� ��Ⱑ �ƴ϶�, ����̶� ������ ����.",
		L"���ī",{},L"�׷��� �������� ����鿡�� ���̶�� �� �� ȥ�������� �ž�.",
		L"���ī",{},L"�������̶�� �� ����� ���� �ֱ⸦ �Ⱦ��ϰ� ��ȸ��Ȱ�� �����ϴ� �׷� �� �ƴϾ�.",
		L"���ī",{},L"��ȸ��Ȱ�� �ϴ� �� �־ ������ ���̸� ���ϼ���, �ͼ�ġ ���� ������ �Ҽ��� ���� ���� ��ٴ� �ͻ��̾�.",
		L"���ī",{},L"�׷��� ���� �������� ������� ���� ȥ�� �ִٰ� �ܷӴٰ� �����ų� �����ϴٰ� ���� ���顦.",
		L"���ī",{},L"�������� ������ ����. 30�и� �־ �ٽ� ���� ���� �;� ������.",
		L"���ī",{},L"������� �̰� ���ݸ� �������൵ �������� ������� �� �� ���߹��� �ٵ� ���̾�.",
		L"���ī",{},L"��� �������� ������� �ֺ��� ����� �ִ°� ������.",
		L"���ī",{},L"�׳� ģ�� ģ�� �ѵ� ���� ���� �ֱ⸸ �ص�, ��� �׳� ��� �����ϰ� ��å�� �ص� ������.",
		L"���ī",{},L"���������� ���� Ȱ���� �������� �ʴ´� �ص�, ���� �翡 �־� �شٴ� �͸� �ص� ����� ������ �ž�.",
		L"���ī",{},L"�������� �ϴ� ���ε�.",
		L"���ī",{},L"���� �������� ����� ���� ����, ��Ʈ���̶� �������� �ð��� �ű⼭ ��������.",
		L"���ī",{},L"�׷��⸸ �ص� ���� �ູ���Ұ�?",
		L"���ī",{},L"�� ���ߡ�.",
		L"���ī",{},L"�������� �������� �ƴ������� ��ҿ� �׷��� �������� ����̶�� ����.",
		L"���ī",{},L"��� �Ŀ��� �� ���� �ؾ߰ڴ�, ��� ������ ��� �ϴϱ�.",
		L"���ī",{},L"�ٵ� �� ���ؼ���� ��� ���� �Ǿ �������.",
		L"���ī",{},L"�� �������ִ� �� �� �ϴ� ���̰ŵ�, �׷��ϱ� Ȥ�� ���� ������ �ִٸ� ���� ���� ������.",
		L"���ī",{},L"�� �� �Ϻ��� ����ģ���� �Ǵ� �͸�ŭ �ູ�� ���� �����ϱ�.",
		L"���ī",{},L"������.",
		L"���ī",{},L"�̰� �׳� �ý��� �̿��þ�, �׷���?",
		L"���ī",{},L"��� �� �ִµ���.",
		L"���ī",{},L"��ó���� �� ������ �� �غ��߰ڴٰ� ������ �ž�?",
		L"���ī",{},L"�� ������ �ܷο��� �ž�?",
		L"���ī",{},L"������ ���� �̾������µ���.",
		L"���ī",{},L"�׷��� ��� �� �Ϻ��ϰ� �� �� �� ����, �츮 �� ��.",
		L"���ī",{},L"�� ���� ������, �� �� �̻� �ܷ��� ���ݾơ�.",
		L"���ī",{},L"�̰� ����̶�� ������ ���� �� ����.",
		L"���ī",{},L"�ʵ� �׷��� ��������?",
		L"���ī",{},L"�� �������� ������ �� ���� �⻵.",
		L"���ī",{},L"����, ����!",
		L"���ī",{},L"�� ������ �ð���.",
		L"���ī",{},L"���峭�̾�.",
		L"���ī",{},L"�������� �� ���ϴ� �� �ǰ� ���Ұŵ�.",
		L"���ī",{},L"������!",
		L"���ī",{},L"�׳� �ѹ� ���غ��� �;���.",
		L"���ī",{},L"���� �����غ���, ����Ű�� ������ �� �����ߴ� ���� �־�����?",
		L"���ī",{},L"��, �ƹ��� �.",
		L"���ī",{},L"�ʴ� �� ������ ���� �����ϱ�.",
		L"���ī",{},L"�׷� ���� �ϱ⿣ �� �ʹ� �������� �������ݾ�, ��ġ?",
		L"���ī",{},L"������~",
		L"���ī",{},L"��¥ �Ҹ� ��ġ�� �� ���� �˾�?",
		L"���ī",{},L"���� �ٸ� �ֵ��� ������ �����µ���, ���� �³� �α�ô�� �������� �� ���ơ�.",
		L"���ī",{},L"�³� ��簡 ���� ���� �߿� �����鼭, �� �Ӹ��ӿ� �ӻ��̴� �� ����.",
		L"���ī",{},L"����� ��, �װ� �˴� �������� ���� �ڿ�, �� ��� ��Ҹ��� �Ӹ��ӿ� �︰�ٴ�.",
		L"���ī",{},L"��¼�� �׳� ���� ö������ ���� ��������.",
		L"���ī",{},L"�׷��� ������ ������� �ٸ� �� �� ����ڴ����.",
		L"���ī",{},L"���࿡ ���� ���õ� ������ ����ų� �Ǽ��� �� ������������.",
		L"���ī",{},L"��� �� ���Ĺ����� �� ���ݾ�, ��ġ?",
		L"���ī",{},L"�װ� ��� �����ϴ����� �𸣰�����, �װ͸�ŭ�� �츮 �� �� �����ؾ� ��.",
		L"���ī",{},L"���� �� �Ͼ�, [player]!",
		L"���ī",{},L"��� �ñ��ߴ��ǵ���.",
		L"���ī",{},L"������� �̷� �ֵ� ĳ���ͼ��� �ŷ��� ������?",
		L"���ī",{},L"�ֵ� ������ ������ ���������̾ߡ�.",
		L"���ī",{},L"���� ���, �������� �ְ� ������ �����Ѵٰ� �����غ�.",
		L"���ī",{},L"������ ���� ���� �ܿ� ������ ���ݾ�.",
		L"���ī",{},L"����Ű�¡� �ؾ����.",
		L"���ī",{},L"ĩ.",
		L"���ī",{},L"�׷� ������ ���� ������� ���� �� ��� ���� ���� ������ �� �Ϳ��� ������� �� �ƴ��ݾ�.",
		L"���ī",{},L"�� ���� ���� �ִµ�, �װ� ������ �� �����ϡ�.",
		L"���ī",{},L"������� ���ǿ��� �������� ���� �̻��� ���ݵ鿡 ���� ������ �ɱ�?",
		L"���ī",{},L"�Ǵ��Ϸ��ų� �׷� �� �ƴ�����!",
		L"���ī",{},L"���ʿ�, ���� �̻��� �ſ� ������ ���� �ϴ°ɡ�.",
		L"���ī",{},L"�׳� ���� �ϴµ��� ��еǴ� �� ����.",
		L"���ī",{},L"�ٵ� ������ ���� �� ĳ���Ϳ��� ����ٿ� �� �� ���� ���� �Ϳ��� �͸� ���ܳ��� ���ݾơ�.",
		L"���ī",{},L"�˸��� ���� �������� ����.",
		L"���ī",{},L"�� ���� �׷��ٸ� �ʵ� �� ���ݸ�ŭ ������ ���� �ʾ��� ���ݾ�. �׷���?",
		L"���ī",{},L"�װ� �� ������ �����ߴٴ� ���� �����غ��� �� �׷� ĳ���Ͱ� �ƴϴϱ� �� ������ ���� ������, ��� �� �����Ǵ� ������ �𸣰ڳ�.",
		L"���ī",{},L"�׷���, ��·�� �� ���� ���� �־� �ִ� ���ݾ�, �׷�����?",
		L"���ī",{},L"�׷��ٴ� �� �� �̴�� ���� �� �´´ٴ� �Űڳ�.",
		L"���ī",{},L"�׸��� �װ� �ʵ� ����������, [player].",
		L"���ī",{},L"�� �Ϳ���� ����ٿ��� �����ϰ� ��췯�� �ִ� �� ����.",
		L"���ī",{},L"���� ������ ������ ���� ������ ���� ���ٴ� ����.",
		L"���ī",{},L"������ �� ��Ʈ�� ���� ���⿡ ���������?",
		L"���ī",{},L"���ƴϸ� �װ͵� ������������.",
		L"���ī",{},L"������ ���� �׷��� �����ϰ� ���ϴ� �͵� �ǰ� ����.",
		L"���ī",{},L"�����ϴ� �� �Ƴ�, ���� ���Ұŵ�.",
		L"���ī",{},L"�׷��� �׻� �ñ��ߴ� �ǵ���.",
		L"���ī",{},L"��¥ ��̿��� �׷��� ����, �ƴϸ� �׳� �ڱⰡ �������� ���̱� ���ؼ� �׷��� ����",
		L"���ī",{},L"�̰� �����л����� ������ϱ.",
		L"���ī",{},L"����, �� ������ ��̸� ������ ���� ���õǰ� ���̴� �� ���� ���� ������ �� ������.",
		L"���ī",{},L"�׸�����.",
		L"���ī",{},L"�� �����̶� Ŀ�Ǹ� Ÿ��ٸ� ������ �ٵ�!",
		L"���ī",{},L"Ŀ�ǵ� å�̶� �ǰ� �� ��︮�� �� ����?",
		L"���ī",{},L"�׷��顦.",
		L"���ī",{},L"�׳� ���� �뺻�� �ٲٸ� �Ǵ� �Űڳ�.",
		L"���ī",{},L"������!",
		L"���ī",{},L"�� ������ �� �߳�.",
		L"���ī",{},L"��, ���� �ͼ� �����غ��� �ƹ� �ǹ̵� ����.",
		L"���ī",{},L"������ �װ� Ŀ�Ǹ� ���Ŵٸ�, �� ������ ������~",
		L"���ī",{},L"����, �װ� ���� �����ϴ� ������ ����?",
		L"���ī",{},L"���� [�αٵα� ������!]�� ���� ����",
		L"���ī",{},L"������! ����̾�.",
		L"���ī",{},L"�׷��� �װ� �ٸ� �̿��ð� �� ���ٰ� ���ϸ�, �� ������ ������",
		L"���ī",{},L"����, �� ģ���� ����� �� ���� �ʹ� �ȴ���.",
		L"���ī",{},L"ģ���� ����� �� ���� �ͺ��ٵ�, ���ο� ����� ������ �� �Ⱦ��� �� ����.",
		L"���ī",{},L"��, ���� �� ���� �͵� ���ݾ�, ��ġ?",
		L"���ī",{},L"�װſ� ���ؼ� ��⸦ �ϴ� �� �ƴ����� ����.",
		L"���ī",{},L"�����غ���, ��¼�� ���� ������� ģ���� ���� �ʾ�?",
		L"���ī",{},L"���� �ݿ��� �����ٵ���, ģ���� ģ���� �����ٵ�����.",
		L"���ī",{},L"��¼�� �װ� ���� �����ϴ� ��尡 ����Ʈ�� ���� ���� ����� ���� ������ ����.",
		L"���ī",{},L"�׷� �� ����.",
		L"���ī",{},L"����� �ǰ� ��ȿ�������� �ʾ�?",
		L"���ī",{},L"�׷� �Ÿ� ������ ���� �������� �̾Ƽ� ���� ������ ģ���� �ǰ�, �׷� ���ݾ�.",
		L"���ī",{},L"�װ� �Ϸ翡�� ������ ���� ����ġ�� ����鿡�� ���غ���.",
		L"���ī",{},L"��¼�� �� �ٷ� ���� �ɾ� �ִ� ����� �� ���� ��ģ�� �� ���� �ִ� ���ݾ�.",
		L"���ī",{},L"��� �𸣰�����.",
		L"���ī",{},L"�� �ڸ����� �Ͼ�� �ٸ� ������ ��������, �� ��ȸ�� ���� ���Ĺ��� �Ű� ���̾�.",
		L"���ī",{},L"�׷��� �����ϸ� �ǰ� ���������� �ʾ�?",
		L"���ī",{},L"�츮�� ���� ��� �ֵ� ���� ����� ����� �� �ִ� ���� ��� ���ݾ�.",
		L"���ī",{},L"�װ� �� ����ؼ� �츮 ��ȸ��Ȱ�� ������ �Ǵ� ���� �ؾ� ���� ������ �;�.",
		L"���ī",{},L"��ġ�� �װ� �ǿ������� �� ������ �󸶳� �ɸ��� ���� �˰ھ.",
		L"���ī",{},L"���� ���嵵 ������ �� ������.",
		L"���ī",{},L"��, �ּ��� �� ���󿡼� ���� ���� ����� ���� �Ŵϱ.",
		L"���ī",{},L"��¼�� ���� �ŷ��� ����.",
		L"���ī",{},L"�׷� �� ��¥ ���� ���Ҵ� �Ű���?",
		L"���ī",{},L"������~",
		L"���ī",{},L"������. �ѹ� ������ ��¥ ���� ���� �־���.",
		L"���ī",{},L"������ó�� ���ǿ��� �׳� ���� �ִµ���.",
		L"���ī",{},L"���ڱ� ��򰡿��� ������ ���� �� ���� ��� ���� �ž�.",
		L"���ī",{},L"����� �ƴ϶�!",
		L"���ī",{},L"�ƴ� '���� ��ð� ���� ��?' �̷��ٴϱ�?",
		L"���ī",{},L"����Ű�� �� ������, ��丮�� �������� �Ҹ��� ������ ��������",
		L"���ī",{},L"��� �� �̾�������, �ڱ� ������ ���� ���� �Ϸ��� �� �Ű�����.",
		L"���ī",{},L"�� ������ �� �� ������ ������ �� �������̰� �� �� ����.",
		L"���ī",{},L"�� ������ ����Ű�� ���ź��� �;� �� �� ��������.",
		L"���ī",{},L"���׸��� ������ �����ڸ�, ���� ���ź��� �;���.",
		L"���ī",{},L"������ ��¥ ��վ��� �ٵ�!",
		L"���ī",{},L"�׷���, �ϴ� �� �����̴ϱ�, �׷��� �ǵ��� ������ �� ���� ����.",
		L"���ī",{},L"�б� �ۿ��� ������ �𸦱�, �׷��� �� ������ ģ�� �� �ƴϴϱ.",
		L"���ī",{},L"����, ���� ���� ���� ���� �ϴ� �ž�?",
		L"���ī",{},L"�̼������� ���ִ� �볳�� �� ����!",
		L"���ī",{},L"�� ����, �� �� ���ź� �� ���ٰ�, ����.",
		L"���ī",{},L"���ᵥ������� �� �� �� �־�?",
		L"���ī",{},L"������ ������ �ʹ� ���ؼ� �ʶ� �Բ��ϱ� ���ؼ��� ������ �ϴ� �����̷�.",
		L"���ī",{},L"���ƴٰ� ������ �����Ρ�.",
		L"���ī",{},L"�ٸ� ����̶� ���� �ִ� �� �ƴѰ��ϰ� ����ŷ�� �ϰ�.",
		L"���ī",{},L"������ �ʳ� �� ģ������ ��ĥ ���� ������.",
		L"���ī",{},L"��·�ų�, �� ������ �ᵥ����� �� �� �ִ� ����� �־�.",
		L"���ī",{},L"���� �Ǹ� ���� ������ ���ϰ� �ִ� ���� �˰���?",
		L"���ī",{},L"�װǡ�.",
		L"���ī",{},L"������!",
		L"���ī",{},L"������ ������ ���� �� �ڷ� �ʿ� ���� �������� �������� ��������.",
		L"���ī",{},L"������ �ڻ��� ���� �ִٰ� �ߴٴϱ�.",
		L"���ī",{},L"�� �°� �׷� �� �ϴ� �� ���� �� ���, �׳� �� �������� �� ����.",
		L"���ī",{},L"�ٵ� ���� ������ ���� ���� ���̷����ϳ�, ������!",
		L"���ī",{},L"��·�ų���.",
		L"���ī",{},L"���� ������� �ᵥ�� ĳ���͸� ������, �˰� �־�?",
		L"���ī",{},L"�������� �ڱ������ �����Ѵٴ� �� ������ ��.",
		L"���ī",{},L"������� ��¥ �̻���!",
		L"���ī",{},L"��, ���� ������ �����ϰ� �ִ� �� ���� ������, �� �� ������ �Ƴġ�.",
		L"���ī",{},L"�����ڸ� �� �ݴ���.",
		L"���ī",{},L"�� �� ���ӿ��� �����ϰ� ����� ����̾�.",
		L"���ī",{},L"���� ��¥�� ����� ���� �͵� �ƴϰ���.",
		L"���ī",{},L"�� ������ �ϸ� �¸��� ����.",
		L"���ī",{},L"�����غ�, ��ε� ���ӿ��� ����� �����ݾ�.",
		L"���ī",{},L"�ٵ� �׷��� �� ������� �������н��� ��? �ƴ��ݾ�.",
		L"���ī",{},L"������ ���� �װ� �ᵥ���� ������ �ȴٸ顦.",
		L"���ī",{},L"�� ���ؼ� �� �� ������ ���� �� �־�, ������~",
		L"���ī",{},L"�׷�����.",
		L"���ī",{},L"�� �̹� �ٸ� �� ���� ����, ���� ������ ����� ����.",
		L"���ī",{},L"��, �̰� �ᵥ�� �ҳ��� ���ϱ�?",
		L"���ī",{},L"�� ���� �ִٸ� �������� ����� �ͳ�.",
		L"���ī",{},L"�װ� �׻� ���⼭ ���� ���� ���� �� ���ٴ� �� �˾ơ�.",
		L"���ī",{},L"������ �Ѵٰų� �ٸ� �͵��� �ؾ� �� ��.",
		L"���ī",{},L"�׷��� �� �׻� �� ������ �ϸ鼭, ������ �ְ� �� ��ٸ� �ž�.",
		L"���ī",{},L"�����غ��ϡ�.",
		L"���ī",{},L"�� ĳ���� ������ �����ؼ� ��� �ٴϸ�, �� �׻� �� �Ϻο� �Բ� �ϴ� �ž�!",
		L"���ī",{},L"�� �̻��� ���̱� ������, �׷��� ���� �θ�ƽ�� �� ��������.",
		L"���ī",{},L"������, �̾�. �ǰ� �ٺ� ���� �����̴�.",
		L"���ī",{},L"�ʹ� ��������ó�� ������ �������� �ϴµ�, �׷��� �� �ʹ� ����ϴ� �� ��Ƴ�.",
		L"���ī",{},L"�̷� �� �ϰ� ������ ������, ���� ���� ��ȸ�ϴ� �� ������ �� ���´ٴ� �ž�.",
		L"���ī",{},L"�׷��� ������ �غ��ߴµ�!",
		L"���ī",{},L"�� ����, ���� ���� �� �ο��� �����ϴ� ���� ������ �α� ��������.",
		L"���ī",{},L"�׷��� ����ȸ�� ��¥ ���ƾ��� ���̾�.",
		L"���ī",{},L"��ΰ� �ڽ��� ǥ���ϴ� �� ���� �� ��¥ ��վ��� �ٵ���.",
		L"���ī",{},L"��, ���� �ڴʰ� ������ ������.",
		L"���ī",{},L"�װ� ���Ƹ��� ������ ���� ���� ������μ� �����ϴ� �� ����.",
		L"���ī",{},L"�� ���� ���� ���� ���ο� �������� �ٶ󺸵��� ���ִ±���?",
		L"���ī",{},L"�ʸ� ����� �ٸ� ������ ��� �� �����.",
		L"���ī",{},L"������������� ĳ���� ������ �����ΰ� ����.",
		L"���ī",{},L"���ǰ� ���ų� ���� ��鼭 �ڽ��� ������ ����� ����̷�.",
		L"���ī",{},L"����Ű�� ��¥ �������� ����������.",
		L"���ī",{},L"ó���� �׳� �Ϳ��ٰ� �����ߴµ���.",
		L"���ī",{},L"�׷��� ����Ű�� ���Ȱ�� �� �� �� �˰� �Ǵϱ�, ���ذ� �Ǵ����.",
		L"���ī",{},L"�׻� ģ�����̶� �����Ϸ��� ����ϴ� �� ������.",
		L"���ī",{},L"�׷��� �����б����� ģ���鳢�� �� ���� ��� �������� �� �ϻ��� �� �˾�?",
		L"���ī",{},L"�� ������ �׷��� �°� �׻� �̷��� ������� �µ��� ��� �� �ž�.",
		L"���ī",{},L"�׸��� �� �� ���������� ���ؼ��� �� �� �� �ž�.",
		L"���ī",{},L"�׷��� �ǵ��ƺ���, ����Ű���� ���Ƹ��� ���� �����̾��ٴ� �� ���� �⻵.",
		L"���ī",{},L"���� ����Ű�� �������� �����ϱ� ���� ����� ������.",
		L"���ī",{},L"���׳� ȸ���ϴ� �Ż��̾�, �װ� �پ�.",
		L"���ī",{},L"������ ���� ������ �� ��Ʈ�� ���� �߰�����.",
		L"���ī",{},L"���ʿ� �̰� �� �����Ѵٱ��� ��������, �� ������ ��¥�� �ƹ��͵� �����ٴ� �� ���� �˾����ȴٴ� �� �߿��� ������.",
		L"���ī",{},L"��, ���� �� ������ �� �ִ� ��Ʈ�� �־��ٸ� �ʶ� ��ͷ��� �̷��Ա��� ������ �ʾҰڳ�.",
		L"���ī",{},L"�ٸ� �ο��鵵 ���� �����鼭��.",
		L"���ī",{},L"������ ����� ������ ���̾�.",
		L"���ī",{},L"��¥�� �ƴ϶� �� �˾������� �� ���� �� �ǹ̴� ���� �ų� �ٸ������ϱ�.",
		L"���ī",{},L"�׷��� �� ������ ���� �׸����� �ʾ�.",
		L"���ī",{},L"���� �׸��� �ʾơ�."
	} {}
	~FifthScene() {}
};
