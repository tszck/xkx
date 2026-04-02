// ROOM lianjianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "煉劍場");
	set("long", @LONG
這裏是玄兵古洞的煉劍場。四周荒涼沒有人煙，地上隱約還能看見
斑斑的血跡，偶爾能看見的幾棵樹似乎也成了劍的表徵，一個個劍拔弩
張的。露天放着一個巨大的爐子，冒着蓬蓬的藍炎，激烈的罡氣震得你
一陣暈眩，原來這裏正在以內家真氣煉劍。
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/shamo3",
	]));
	set("objects",([
		__DIR__"npc/shijian" :1,
	]));
	set("coor/x", -30000);
	set("coor/y", 1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
