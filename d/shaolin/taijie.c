// Room: /d/shaolin/taijie.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "臺階");
	set("long", @LONG
穿過山門殿，面前三道平行的青石臺階通向前方的一個高
臺。臺階上精工鏤刻着麒麟，玄龜，松鶴等瑞獸，形態逼真動
人。高臺正中放着個二人高的青銅大香爐，前面擺着個香臺，
幾位香客正在虔誠膜拜。再往前就是天王殿。
LONG );
	set("exits", ([
		"east" : __DIR__"beilin1",
		"south" : __DIR__"smdian",
		"west" : __DIR__"beilin2",
		"northup" : __DIR__"twdian",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 810);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
