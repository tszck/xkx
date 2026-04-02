// Room: /d/lingxiao/cityout1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城外");
	set("long", @LONG
這裏是凌霄城的城外，出現在你面前的是高聳的城牆，看來如果不
從城門走，想要越牆而入，是不太可能的。凌霄城外野狼很多，絕對不
是什麼安全的地方，還是趕快進城吧。
LONG
	);
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"shanya",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8940);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
