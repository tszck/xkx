// Room: /d/taohuacun/taohua1.c

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
這是一片爛漫的桃花林，滿山遍野的桃樹枝上，開着桃紅的桃
花。桃花上頭，飛滿了細細嗡嗡的不甘寂寞的蜜蜂。腳下是一條不
寬也不窄的林間小道，道邊是密密叢叢的嫩草和爭奇鬥豔的小花。
LONG );
	set("outdoors", "taohuacun");
//	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"taohua2",
		"south" : "/d/city/ximen",
		"west"  : "/d/5lt/exit",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
	set("coor/x", -100);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}