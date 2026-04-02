// /d/yixing/clwoshi.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "臥室");
	set("long", @LONG
室內陳設甚是奢華，極大的牀邊有張朱漆書桌，桌旁兩張椅子，上
鋪錦墊。牀前羅帳低垂，隱約看見牀上似乎無人。窗前的香爐中青煙嫋
嫋，你只覺置身於一個香噴噴，軟綿綿的神仙洞府。
LONG );
	set("exits", ([
		"south" : __DIR__"clxiaoting",
	]));
	set("objects",([
		__DIR__"npc/cl_shijian" : 1,
	]));
	setup();

	replace_program(ROOM);
}
