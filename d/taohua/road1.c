inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
這是一條小徑，彎彎曲曲向遠方延伸。小徑兩邊種植了一些桃花樹。
你只一瞥就發現：這些桃花全是白色的。
LONG );
	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
	]));
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
       	replace_program(ROOM);
}