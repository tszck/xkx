//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "東街");
	set("long", @LONG
這是荊州城東的一條小街。雖然這裏沒有西街繁華，近日卻也頗有
些江湖人物來去匆匆。西邊是一條僻靜的小巷，東邊卻是一座壯觀的樓
閣。
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"yuanmiaoguan",
		"south" : __DIR__"dongjie2",
		"west"  : __DIR__"xiang1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}