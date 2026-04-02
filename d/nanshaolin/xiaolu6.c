// Room: /d/nanshaolin/xiaolu6.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
這是一片密密的竹林。這裏人跡罕至，惟聞足底叩擊路面，有僧敲
木魚聲；微風吹拂竹葉，又如簌簌禪唱。令人塵心為之一滌，真是絕佳
的禪修所在。
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu7",
		"east" : __DIR__"xiaolu5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

