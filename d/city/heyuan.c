// Room: /city/heyuan.c

inherit ROOM;

void create()
{
	set("short", "何園");
	set("long", @LONG
何員外修的何園是揚州城中數一數二的好園林，就是傳到江南也頗
有些名聲，園內假山水池錯落有致，一草一木，別具匠心，往往細微之
處卻又有曲徑通幽之感。滿目芳華，撲鼻芬香，令人陶醉。
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"north" : __DIR__"caohenanjie",
		"south" : __DIR__"heyuanhouyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -51);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}