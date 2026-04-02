inherit ROOM;

void create()
{
	set("short", "朝陽門");
	set("long", @LONG
這裏就是朝陽門，城牆上刻着“朝陽門”三個大字。東門就在東南
邊，那裏人來車往，是進出京城的要道，盤查十分嚴密。一條寬闊的大
道向西延伸，通往著名的王府井大街。從這裏也可以出北京城，東北邊
就是郊外，那裏有一大片竹林，一個人也看不見。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"chaoyan1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -160);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
