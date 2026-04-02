// ROOM m_room1.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "沙漠綠洲");
	set("long", @LONG
這裏是沙漠中不多的一塊綠洲，向南不遠隱約可以看見一座黑黑的
山洞。隨風傳來一些叮叮噹噹的打鐵的聲音。也不知是誰在打造什麼。
LONG );
	set("exits", ([
		"east"  : "/d/xingxiu/nanjiang2",
		"south" : __DIR__"xuanbing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41200);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
