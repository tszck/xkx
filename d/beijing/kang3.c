inherit ROOM;


void create()
{
	set("short", "康府後院");
	set("long", @LONG
這裏是康府後院，西首是一個小花園。北邊有一條長廊走道直通往
內堂。東邊是一間馬棚。南邊就是康親王最愛去的私人練武場。
LONG
);
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"mapeng",
		"north" : __DIR__"neitang",
		"south" : __DIR__"kang2",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
