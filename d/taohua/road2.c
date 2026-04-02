inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
這是一條小徑，彎彎曲曲向遠方延伸。小徑兩邊種植了一些桃花樹。
你只一瞥就發現：這些桃花全是白色的。
LONG);
	set("exits", ([
		"west" : __DIR__"road1",
		"east" : __DIR__"road3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}