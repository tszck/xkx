// ROOM lianqiang.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "作槍洞");
	set("long", @LONG
這裏是玄兵古洞的造槍的地方。地處鐵掌峯潮陰之處，四周洞壁黑
幽幽的，中間放着一個巨大的爐子，冒着蓬蓬的藍炎，倒把整個洞照得
挺光亮的。
LONG );
	set("exits", ([
		"west" : "/d/tiezhang/sslin2",
	]));
	set("objects",([
		__DIR__"npc/shiqiang" :1,
	]));
	set("coor/x", -2020);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
