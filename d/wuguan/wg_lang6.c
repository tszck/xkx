// wg_lang6.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是個長廊，往東通向休息室，西面是物品房，這裏靜悄悄的，人
們走路都也小心翼翼的，怕吵着東面休息室裏休息的人。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_woshi1",
		"west" : __DIR__"wg_wupinfang",
	]));
	set("outdoors", "wuguan");
	set("coor/x", 51);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

