// /d/meizhuang/qhpo.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "奇槐坡");
	set("long", @LONG
這裏就是奇槐坡了，這裏種着大大小小，千奇百怪的槐樹，有的槐
樹一直向天，有的又曲折盤繞，你從這裏隱隱約約聽到一陣陣的琴聲，
似有似無，若隱若現。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xiaodao",
		"north"  : __DIR__"senlin1",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1440);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
