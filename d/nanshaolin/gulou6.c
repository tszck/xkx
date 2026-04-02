// Room: /d/nanshaolin/gulou6.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓樓六層");
	set("long", @LONG
沿窗洞吹進一陣陣凌厲的山風，寒意浸人。樓上傳來一陣陣沉悶的
鼓聲。
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou7",
		"down" : __DIR__"gulou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

